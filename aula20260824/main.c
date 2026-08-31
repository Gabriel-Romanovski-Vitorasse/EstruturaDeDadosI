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
            insertionsort(codigo);

            printf("\n\n");
            printf("Depois:\n");
            printf("|");
            for(int i = 0; i < TAMANHO; i++){
                printf(" %i |", codigo[i]);
            }


    return 0;
}
