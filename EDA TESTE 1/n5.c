#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto produtos[3];
    float totalEstoque = 0;
    int i;  // DECLARADO FORA do for
    float valorProduto;
    
    strcpy(produtos[0].nome, "Camiseta");
    produtos[0].preco = 29.90;
    produtos[0].quantidade = 50;
    
    strcpy(produtos[1].nome, "Calca Jeans");
    produtos[1].preco = 89.90;
    produtos[1].quantidade = 30;
    
    strcpy(produtos[2].nome, "Tenis");
    produtos[2].preco = 149.90;
    produtos[2].quantidade = 20;
    
    printf("--- Estoque ---\n");
    
    for(i = 0; i < 3; i++) {
        valorProduto = produtos[i].preco * produtos[i].quantidade;
        totalEstoque = totalEstoque + valorProduto;
        
        printf("%s: R$%.2f x %d = R$%.2f\n", 
               produtos[i].nome, produtos[i].preco, 
               produtos[i].quantidade, valorProduto);
    }
    
    printf("\nValor total do estoque: R$%.2f\n", totalEstoque);
    
    return 0;
}