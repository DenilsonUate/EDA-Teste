#include <stdio.h>

void bubbleSort(int vetor[], int n) {
    int i, j, temp;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(vetor[j] > vetor[j+1]) {
                // Troca os elementos
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void imprimirVetor(int vetor[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = 7;
    
    printf("Vetor original: ");
    imprimirVetor(numeros, tamanho);
    
    bubbleSort(numeros, tamanho);
    
    printf("Vetor ordenado: ");
    imprimirVetor(numeros, tamanho);
    
    return 0;
}
