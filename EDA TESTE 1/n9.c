#include <stdio.h>

int buscaBinariaIterativa(int vetor[], int tamanho, int alvo) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    
    while(esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        
        if(vetor[meio] == alvo) {
            return meio;  // Encontrou
        }
        else if(vetor[meio] < alvo) {
            esquerda = meio + 1;  // Busca na metade direita
        }
        else {
            direita = meio - 1;  // Busca na metade esquerda
        }
    }
    return -1;  // Nao encontrou
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // PRECISA estar ordenado
    int tamanho = 10;
    int alvo = 7;
    int posicao;
    
    posicao = buscaBinariaIterativa(numeros, tamanho, alvo);
    
    if(posicao != -1) {
        printf("Elemento %d encontrado na posicao %d\n", alvo, posicao);
    } else {
        printf("Elemento %d nao encontrado\n", alvo);
    }
    
    return 0;
}
