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


int main()
{
    printf("Inicio!\n");
    ArvBin *raiz = criaArvBin();
    int N=10, dados[10] = {28,16,40,11,21,36,48,19,32,56};

    for(int i=0;i<N;i++){
        inserir_ArvBin(raiz, dados[i]);
    }
    preOrdem_ArvBin(raiz);

    return 0;
}
