#include <stdio.h>

int buscaBinariaRecursiva(int vetor[], int esquerda, int direita, int alvo) {
    if(esquerda > direita) {
        return -1;  // Caso base: nao encontrou
    }
    
    int meio = (esquerda + direita) / 2;
    
    if(vetor[meio] == alvo) {
        return meio;  // Caso base: encontrou
    }
    else if(vetor[meio] < alvo) {
        return buscaBinariaRecursiva(vetor, meio + 1, direita, alvo);  // Busca direita
    }
    else {
        return buscaBinariaRecursiva(vetor, esquerda, meio - 1, alvo);  // Busca esquerda
    }
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = 10;
    int alvo = 7;
    int posicao;
    
    posicao = buscaBinariaRecursiva(numeros, 0, tamanho - 1, alvo);
    
    if(posicao != -1) {
        printf("Elemento %d encontrado na posicao %d\n", alvo, posicao);
    } else {
        printf("Elemento %d nao encontrado\n", alvo);
    }
    
    return 0;
}
