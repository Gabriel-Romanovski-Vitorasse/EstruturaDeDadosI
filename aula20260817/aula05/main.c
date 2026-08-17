#include <stdio.h>
#include <stdlib.h>
#define TAM 7
/*int buscar (int *m, int n){
    for(int i=0; i<TAM;i++){
        if(m[i] == n) {
            return i;
        }
    }
    return -1;
}*/

int buscaOrdenada (int *m, int n){
    for(int i=0; i<TAM;i++){
        if(m[i] == n) {
            return i;
        }
        else{
            if(n<m[i]) return -1;
        }
    }
    return -1;
}


int main()
{
    int num[TAM] = {23,4,67,-8,54,90,21}, elem, test[TAM] = {-8,4,21,23,54,67,90};

    printf("==============================================\n");
    printf("\tBuscador de vetores\n");
    printf("==============================================\n");

    printf("Qual valor deseja procurar: ");
    scanf("%d", &elem);

    int v = buscaOrdenada(test, elem);
    if(v == -1) printf("Valor nao encontrado.\n");
    else{
        printf("\nvalor: %d\n", elem);
        printf("Endereco: %d", v);
    }

    return 0;
}
