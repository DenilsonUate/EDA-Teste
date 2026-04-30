#include <stdio.h>

int buscaLinearContagem(int vetor[], int tamanho, int alvo, int *comparacoes) {
    int i;
    *comparacoes = 0;  // Inicia contador
    
    for(i = 0; i < tamanho; i++) {
        (*comparacoes)++;  // Conta cada comparacao
        if(vetor[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numeros[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int tamanho = 9;
    int alvo = 9;
    int posicao;
    int comparacoes;
    
    posicao = buscaLinearContagem(numeros, tamanho, alvo, &comparacoes);
    
    if(posicao != -1) {
        printf("Elemento %d encontrado na posicao %d\n", alvo, posicao);
    } else {
        printf("Elemento %d nao encontrado\n", alvo);
    }
    printf("Total de comparacoes: %d\n", comparacoes);
    
    return 0;
}
