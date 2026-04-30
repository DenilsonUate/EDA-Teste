#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 20  // Usei 20 para facilitar visualizacao

void gerarVetorAleatorio(int vetor[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }
}

void imprimirVetor(int vetor[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void copiarVetor(int origem[], int destino[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

// Algoritmo 1: BUBBLE SORT
int bubbleSort(int vetor[], int n) {
    int i, j, temp;
    int trocas = 0;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                trocas++;
            }
        }
    }
    return trocas;
}

// Algoritmo 2: SELECTION SORT
int selectionSort(int vetor[], int n) {
    int i, j, min_idx, temp;
    int trocas = 0;
    
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            temp = vetor[i];
            vetor[i] = vetor[min_idx];
            vetor[min_idx] = temp;
            trocas++;
        }
    }
    return trocas;
}

int main() {
    int original[TAMANHO];
    int vetor1[TAMANHO];
    int vetor2[TAMANHO];
    int trocas1, trocas2;
    
    srand(time(NULL));
    
    printf("=== PROGRAMA DE COMPARACAO DE ORDENACAO ===\n\n");
    
    // Gerar vetor aleatorio
    gerarVetorAleatorio(original, TAMANHO);
    
    printf("1. Vetor aleatorio gerado:\n");
    imprimirVetor(original, TAMANHO);
    
    // Teste com Bubble Sort
    copiarVetor(original, vetor1, TAMANHO);
    trocas1 = bubbleSort(vetor1, TAMANHO);
    
    printf("\n2. Bubble Sort:\n");
    printf("   Vetor ordenado: ");
    imprimirVetor(vetor1, TAMANHO);
    printf("   Total de trocas: %d\n", trocas1);
    
    // Teste com Selection Sort
    copiarVetor(original, vetor2, TAMANHO);
    trocas2 = selectionSort(vetor2, TAMANHO);
    
    printf("\n3. Selection Sort:\n");
    printf("   Vetor ordenado: ");
    imprimirVetor(vetor2, TAMANHO);
    printf("   Total de trocas: %d\n", trocas2);
    
    // Comparacao
    printf("\n4. Comparacao:\n");
    printf("   Bubble Sort fez %d trocas\n", trocas1);
    printf("   Selection Sort fez %d trocas\n", trocas2);
    
    if(trocas1 < trocas2) {
        printf("   -> Bubble Sort fez %d trocas a menos\n", trocas2 - trocas1);
    } else if(trocas2 < trocas1) {
        printf("   -> Selection Sort fez %d trocas a menos\n", trocas1 - trocas2);
    } else {
        printf("   -> Ambos fizeram o mesmo numero de trocas\n");
    }
    
    return 0;
}
