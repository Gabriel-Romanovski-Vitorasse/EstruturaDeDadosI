#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
}cel;

typedef struct cel* Lista;

Lista* cria_Lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL) return 0;
    cel *aux = (cel*) malloc (sizeof(cel));
    if(aux == NULL) return 0;

    aux->conteudo = x;
    aux->seg = NULL;

    if(*lista == NULL){
        *lista = aux;
    }else{
        cel *temp;
        temp = *lista;
        while(temp->seg != NULL){
            temp = temp->seg;
        }
        temp->seg = aux;
    }
    return 1;
}

void imprimir_lista(Lista *lista){
    if(lista==NULL) {
        printf("A lista nao existe");
        return;
    }
    if(*lista==NULL) {
        printf("A lista esta vazia.");
        return;
    }

    cel *aux = *lista;
    printf("Lista: |");
    while(aux!=NULL){
        printf(" %d |", aux->conteudo);
        aux = aux->seg;
    }
    printf("\n");
}
int remove_lista_fim(Lista *lista){
    if(lista==NULL) {
        printf("A lista nao existe");
        return 0;
    }
    if(*lista==NULL) {
        printf("A lista esta vazia.");
        return 0;
    }
    cel *ant = NULL, *aux = *lista;
    while(aux->seg != NULL){
        ant = aux;
        aux = aux->seg;
    }
    if(ant == NULL){
        *lista = NULL;
        free(aux);
    }else{
        ant->seg = NULL;
        free(aux);
    }

    return 1;
}

void esvaziar_lista(Lista *lista){
    if(lista == NULL) {
        printf("A lista nao existe.");
        return;
    }
    cel *aux;
    while(*lista != NULL){
        aux = *lista;
        *lista = (*lista)->seg;
        free(aux);
    }
}
void deletar_lista(Lista *lista){
    if(lista == NULL){
        printf("A lista nao existe.");
        return;
    } 
    esvaziar_lista(lista);
    free(lista);
}

int main()
{
    printf("Inicio Lista!\n");
    Lista *list;
    list = cria_Lista();
    insere_lista_fim(list, 10);
    insere_lista_fim(list, 20);
    insere_lista_fim(list, 30);
    insere_lista_fim(list, 40);
    imprimir_lista(list);
    deletar_lista(list);
    /*remove_lista_fim(list);
    imprimir_lista(list);
    remove_lista_fim(list);
    imprimir_lista(list);
    remove_lista_fim(list);
    imprimir_lista(list);
    remove_lista_fim(list);
    imprimir_lista(list);*/

    return 0;
}
