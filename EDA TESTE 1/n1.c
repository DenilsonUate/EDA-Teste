#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[100];
    int idade;
    float media;
};

int main() {
    struct Aluno aluno1;
    
    strcpy(aluno1.nome, "Joao Silva");
    aluno1.idade = 20;
    aluno1.media = 8.5;
    
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Media: %.2f\n", aluno1.media);
    
    return 0;
}