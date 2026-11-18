#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
}NO;

typedef struct NO* ArvAVL;

int altura_NO (NO *no){
    if(no == NULL){
        return -1;
    }else{
        return no->altura;
    }
}

int fatorBalanceamento_NO(NO *no){
    return altura_NO(no->esq) - altura_NO(no->dir);
}

int maior(int x, int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}

void rotacaoRR(ArvAVL *A){
    printf("RotacaoRR\n");
    NO *B;
    B = (*A) ->dir;
    (*A) ->dir = B->esq;
    B->esq = *A;
    (*A)->altura = maior(altura_NO((*A)->dir), altura_NO((*A)->esq))+1;
    B->altura = maior(altura_NO(B->dir), (*A)->altura)+1;
    *A = B;
}

void rotacaoLL(ArvAVL *A){
    printf("RotacaoLL\n");
    NO *B;
    B = (*A) ->esq;
    (*A) ->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir))+1;
    B->altura = maior(altura_NO(B->esq), (*A)->altura)+1;
    *A = B;
}

void rotacaoLR(ArvAVL *A){
    rotacaoRR(&(*A)->esq);
    rotacaoLL(A);
}

void rotacaoRL(ArvAVL *A){
    rotacaoLL(&(*A)->dir);
    rotacaoRR(A);
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;

    if(*raiz==NULL){
      NO *novo;
      novo = (NO*) malloc (sizeof(NO));
      if(novo == NULL){
        return 0;
      }
      novo->info = valor;
      novo->altura = 0;
      novo->esq = NULL;
      novo->dir = NULL;
      *raiz = novo;
      return 1;
    }
    NO *atual = *raiz;
    if(valor<atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor))==1 ){
            if(fatorBalanceamento_NO(atual)>=2){
                if(valor<(*raiz)->esq->info){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else if(valor>atual->info){
        if((res = insere_ArvAVL(&(atual->dir), valor))==1 ){
            if(fatorBalanceamento_NO(atual) <= -2){
                if((*raiz)->dir->info < valor){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }}
    }else{
        printf("Valor duplicado.\n");
        return 0;
    }

    atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;

    return res;
}

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}


int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
         printf("No %d: %d\n",(*raiz)->info,altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int main(){
    ArvAVL *raiz = cria_ArvAVL();
    insere_ArvAVL(raiz, 10);
    insere_ArvAVL(raiz, 20);
    insere_ArvAVL(raiz, 30);
    preOrdem_ArvAVL(raiz);
    libera_ArvAVL(raiz);
}
