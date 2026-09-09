#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAMANHO 8

/*void maior(int *vetor){
    int maior = 0;
    for(int i=0; i < TAMANHO - 1; i++){
        if(vetor[i]>maior){
            maior = vetor[i];
        }
    }
    printf("%i\n\n", maior);
}*/

void menor(int *vetor){
    int menor = vetor[TAMANHO];
    for(int i=0; i < TAMANHO - 1; i++){
        if(vetor[i]<menor){
            menor = vetor[i];
        }
    }
    printf("%i\n\n", menor);
}

void merge(int *v, int inicio, int meio, int fim){
    int *temp, i, j, k, tam, p1, p2, fim1 = 0, fim2 = 0;
    tam = fim - inicio + 1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tam*(sizeof(int)));

    if(temp != NULL){
        for(i = 0; i < tam; i++){
            if(!fim1 && !fim2){
                if(v[p1]<v[p2]){ temp[i] = v[p1++];}
                else{ temp[i] = v[p2++];}
                if(p1>meio){fim1 = 1;}
                if(p2>fim) {fim2 = 1;}
            } else{
                if(!fim1){ temp[i] = v[p1++]; }
                else{ temp[i] = v[p2++]; }
            }
        }
        for(j=0, k = inicio; j<tam; j++, k++){
            v[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim);
    }
}

void insertionsort(int *vetor){
    int i, j, aux;
    for(i=1;i<TAMANHO;i++){
        aux = vetor[i];
        for(j=i;(j>0) && (aux<vetor[j-1]);j-- ){
            vetor[j]=vetor[j-1];
        }
        vetor[j] = aux;
    }
}

void selectionsort(int *vetor){
    int menor, troca, j, i;
    for(j=0; j < TAMANHO-1; j++){//analisa todos os indices
        menor = j;
        for(i = j+1; i < TAMANHO; i++){//busca o menor
            if(vetor[i]<vetor[menor]){
                menor = i;
            }
        }
        if(j != menor){//troca os valores
            troca = vetor[j];
            vetor[j] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}


/*void bubblesort(int *vetor){
    int aux;
    for (int j = 0; j < TAMANHO - 1; j++) {
        for (int i = 0; i < TAMANHO - 1 - j; i++) {
            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}*/

void bubblesort(int *vetor){
    int aux, loop = 1;
    while(loop){
        loop = 0;
       for (int i = 0; i < TAMANHO - 1; i++) {
            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                loop = 1;
            }
        }
    }
}

int main(void) {
    int codigo[TAMANHO] = {33,77,1,2,89,6,13,55};

            //maior(codigo);
            //menor(codigo);
            printf("Antes:\n");
            printf("|");
            for(int i = 0; i < TAMANHO; i++){
                printf(" %i |", codigo[i]);
            }

            //bubblesort(codigo);
            //selectionsort(codigo);
            //insertionsort(codigo);
            mergeSort(codigo, 0, 7);

            printf("\n\n");
            printf("Depois:\n");
            printf("|");
            for(int i = 0; i < TAMANHO; i++){
                printf(" %i |", codigo[i]);
            }


    return 0;
}
