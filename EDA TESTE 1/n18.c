#include <stdio.h>

void bubbleSortOtimizado(int vetor[], int n) {
    int i, j, temp;
    int trocou;  // Flag para verificar se houve troca
    
    for(i = 0; i < n-1; i++) {
        trocou = 0;  // Assume que nao houve troca
        
        for(j = 0; j < n-i-1; j++) {
            if(vetor[j] > vetor[j+1]) {
                // Troca os elementos
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                trocou = 1;  // Houve troca
            }
        }
        
        // Se nao houve troca, o vetor ja esta ordenado
        if(trocou == 0) {
            printf("Vetor ja estava ordenado! Parando na passagem %d\n", i+1);
            break;
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
    int numeros1[] = {11, 12, 22, 25, 34, 64, 90};  // Ja ordenado
    int numeros2[] = {64, 34, 25, 12, 22, 11, 90};  // Desordenado
    int tamanho = 7;
    
    printf("--- Teste com vetor ja ordenado ---\n");
    printf("Original: ");
    imprimirVetor(numeros1, tamanho);
    bubbleSortOtimizado(numeros1, tamanho);
    printf("Resultado: ");
    imprimirVetor(numeros1, tamanho);
    
    printf("\n--- Teste com vetor desordenado ---\n");
    printf("Original: ");
    imprimirVetor(numeros2, tamanho);
    bubbleSortOtimizado(numeros2, tamanho);
    printf("Resultado: ");
    imprimirVetor(numeros2, tamanho);
    
    return 0;
}
