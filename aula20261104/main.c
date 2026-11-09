#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *esq;
    struct No *dir;
}No;

typedef struct No* ArvBin;

ArvBin* criaArvBin(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if(raiz!=NULL) *raiz = NULL;
    return raiz;

}

int inserir_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){//caso não exista a arvore
        return 0;
    }

    No *novo;
    novo = (No*) malloc (sizeof(No));
    if(novo == NULL){//caso não exista o novo
        return 0;
    }
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }else{
        No *atual = *raiz;
        No *ant = NULL;

        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){//caso seja repetido, não será válido.
                free(novo);
                return 0;
            }
            if(valor>atual->info){
                atual = atual->dir;//vai para o lado direito da arvore
            }else{
                atual = atual->esq;//vai para o lado esquerdo a arvore
            }
        }

        if(valor>ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;

    }
    if(*raiz != NULL){
        printf("%d \t", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_arvBin(ArvBin *raiz){
  if(raiz==NULL){
      return;
  }
  if(*raiz!=NULL){
    emOrdem_arvBin(&((*raiz)->esq));
    printf("%d\t", (*raiz)->info);
    emOrdem_arvBin(&((*raiz)->dir));
  }
}

void posOrdem_arvBin(ArvBin *raiz){
  if(raiz==NULL){
      return;
  }
  if(*raiz!=NULL){
    posOrdem_arvBin(&((*raiz)->esq));
    posOrdem_arvBin(&((*raiz)->dir));
    printf("%d\t", (*raiz)->info);
  }
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    No *atual = *raiz;

    while(atual!=NULL){
        if(valor == atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

int totalNos_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL){
        return 0;
    }
    int qtd_dir = totalNos_ArvBin(&((*raiz)->dir));
    int qtd_esq = totalNos_ArvBin(&((*raiz)->esq));

    return(qtd_dir+qtd_esq+1);
}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL){
        return -1;
    }
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    int alt_esq = altura_ArvBin(&((*raiz)->esq));

    if(alt_esq > alt_dir){
        return alt_esq+1;
    } else{
        return alt_dir+1;
    }
}

int main()
{
    printf("Inicio!\n");
    ArvBin *raiz = criaArvBin();
    int N=10, dados[10] = {28,16,40,11,21,36,48,19,32,56};

    for(int i=0;i<N;i++){
        inserir_ArvBin(raiz, dados[i]);
    }
    printf("Pre-Ordem: ");
    preOrdem_ArvBin(raiz);
    printf("\nEm Ordem: ");
    emOrdem_arvBin(raiz);
    printf("\nPos-Ordem: ");
    posOrdem_arvBin(raiz);
    printf("\n\ntotal de nos: %d", totalNos_ArvBin(raiz));
    printf("\nAltura da arvore: %d", altura_ArvBin(raiz));

    return 0;
}
