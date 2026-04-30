#include <stdio.h>
#include <time.h>

// Busca Linear com contagem
int buscaLinearContagem(int vetor[], int tamanho, int alvo, int *comparacoes) {
    int i;
    *comparacoes = 0;
    for(i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if(vetor[i] == alvo) {
            return i;
        }
    }
    return -1;
}

// Busca Binaria com contagem
int buscaBinariaContagem(int vetor[], int tamanho, int alvo, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    *comparacoes = 0;
    
    while(esquerda <= direita) {
        (*comparacoes)++;
        meio = (esquerda + direita) / 2;
        
        if(vetor[meio] == alvo) {
            return meio;
        }
        else if(vetor[meio] < alvo) {
            esquerda = meio + 1;
        }
        else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main() {
    // Teste com vetor PEQUENO (10 elementos)
    int pequeno[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanhoP = 10;
    
    // Teste com vetor GRANDE (1000 elementos)
    int grande[1000];
    int i;
    for(i = 0; i < 1000; i++) {
        grande[i] = i + 1;
    }
    
    int alvo = 500;  // Elemento do meio
    int posicao;
    int comparacoesLinear;
    int comparacoesBinaria;
    
    printf("=== COMPARACAO DE BUSCAS ===\n\n");
    
    // TESTE VETOR PEQUENO
    printf("--- Vetor PEQUENO (10 elementos) ---\n");
    
    posicao = buscaLinearContagem(pequeno, tamanhoP, alvo, &comparacoesLinear);
    printf("Busca Linear: %d comparacoes\n", comparacoesLinear);
    
    posicao = buscaBinariaContagem(pequeno, tamanhoP, alvo, &comparacoesBinaria);
    printf("Busca Binaria: %d comparacoes\n", comparacoesBinaria);
    
    printf("Vantagem: Binaria fez %d comparacoes a menos\n\n", 
           comparacoesLinear - comparacoesBinaria);
    
    // TESTE VETOR GRANDE
    printf("--- Vetor GRANDE (1000 elementos) ---\n");
    
    posicao = buscaLinearContagem(grande, 1000, alvo, &comparacoesLinear);
    printf("Busca Linear: %d comparacoes\n", comparacoesLinear);
    
    posicao = buscaBinariaContagem(grande, 1000, alvo, &comparacoesBinaria);
    printf("Busca Binaria: %d comparacoes\n", comparacoesBinaria);
    
    printf("Vantagem: Binaria fez %d comparacoes a menos\n", 
           comparacoesLinear - comparacoesBinaria);
    
    // PIOR CASO (elemento nao existe)
    printf("\n--- PIOR CASO (elemento nao existe) ---\n");
    
    posicao = buscaLinearContagem(grande, 1000, 2000, &comparacoesLinear);
    printf("Busca Linear (pior caso): %d comparacoes\n", comparacoesLinear);
    
    posicao = buscaBinariaContagem(grande, 1000, 2000, &comparacoesBinaria);
    printf("Busca Binaria (pior caso): %d comparacoes\n", comparacoesBinaria);
    
    return 0;
}
