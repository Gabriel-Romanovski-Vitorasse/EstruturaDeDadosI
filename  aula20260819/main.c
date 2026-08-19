#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int buscaBinaria(int vetor[], int inicio, int fim, int alvo) {
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == alvo)
        return meio;
    else if (vetor[meio] < alvo)
        return buscaBinaria(vetor, meio + 1, fim, alvo);
    else
        return buscaBinaria(vetor, inicio, meio - 1, alvo);
}

/*int buscaBinaria(int vetor[], int alvo) {
    int inicio = 0;
    int fim = TAM - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == alvo)
            return meio;
        else if (vetor[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}*/

int main()
{
    int elem, test[TAM] = {-8,-5,1,4,14,21,23,54,67,90};

    printf("==============================================\n");
    printf("\tBuscador de vetores\n");
    printf("==============================================\n");

    printf("Qual valor deseja procurar: ");
    scanf("%d", &elem);

    int v = buscaBinaria(test, 0,TAM-1,elem);
        printf("\nvalor: %d\n", elem);
        printf("Endereco: %d", v);


    return 0;
}
