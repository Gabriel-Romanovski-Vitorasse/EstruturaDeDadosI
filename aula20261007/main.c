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
int pop(Pilha *p){
    if (p == NULL || *p == NULL) {
        printf("ERRO: a pilha esta vazia ou nao existe.\n");
        return -1;
    }
    cel *aux = *p;          // guarda o topo atual
    int valor = aux->valor; // guarda o valor antes de liberar
    *p = aux->topo;         // o topo passa a ser o elemento de baixo
    free(aux);              // libera a célula removida
    return valor;
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
