#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *topo;
}cel;

typedef cel* Pilha;

Pilha* cria_Pilha(){
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

int peek(Pilha *p){
    if (p == NULL || *p == NULL) {
        printf("ERRO: a pilha está vazia ou não existe.\n");
        return -1; // Retorna um código de erro genérico
    }
     cel *aux = *p;

    return aux->valor;
}

void push(Pilha *p, int conteudo){
    if (p == NULL) {
        printf("A Pilha não existe.\n");
        return; // Interrompe a execução caso p seja nulo
    }
    cel *aux = (cel*) malloc (sizeof(cel));
    if (aux == NULL) return;

    aux->valor = conteudo;
    aux->topo = *p; // O atual da nova célula passa a ser o antigo topo
    *p = aux; // O topo da pilha passa a ser a nova célula

}
void pop (Pilha *p){

}

int main()
{
    printf("Hello world!\n");
    Pilha *pil;
    pil = cria_Pilha();
    push(pil, 10);
    printf("%d\n", peek(pil));
    push(pil, 20);
    printf("%d\n", peek(pil));
    return 0;
}
