#include <stdio.h>

int buscaLinear(int vetor[], int tamanho, int alvo) {
    int i;
    for(i = 0; i < tamanho; i++) {
        if(vetor[i] == alvo) {
            return i;  // Retorna a posicao onde encontrou
        }
    }
    return -1;  // Nao encontrou
}

int main() {
    int numeros[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int tamanho = 9;
    int alvo = 7;
    int posicao;
    
    posicao = buscaLinear(numeros, tamanho, alvo);
    
    if(posicao != -1) {
        printf("Elemento %d encontrado na posicao %d\n", alvo, posicao);
    } else {
        printf("Elemento %d nao encontrado\n", alvo);
    }
    
    return 0;
}
