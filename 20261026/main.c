#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

no* criaNo(int valor){
    no *novo = (no*) malloc(sizeof(no));
    if(novo != NULL){
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

void preOrdem(no *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(no *raiz){
    if(raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

void liberaArvore(no *raiz){
    if(raiz != NULL){
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz);
    }
}

int main()
{

    no *raiz = criaNo(8);
    raiz->esq = criaNo(3);
    raiz->dir = criaNo(10);
    raiz->esq->esq = criaNo(1);
    raiz->esq->dir = criaNo(6);
    raiz->dir->dir = criaNo(14);
    raiz->dir->esq = criaNo(7);

    printf("Pre-ordem: ");
    preOrdem(raiz);
    printf("\nEm ordem:  ");
    emOrdem(raiz);
    printf("\nPos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    liberaArvore(raiz);
    return 0;
}
