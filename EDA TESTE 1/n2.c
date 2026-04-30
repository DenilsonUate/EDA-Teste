#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    float media;
} Aluno;

int main() {
    Aluno aluno1, aluno2, aluno3;
    
    strcpy(aluno1.nome, "Maria Santos");
    aluno1.idade = 19;
    aluno1.media = 9.0;
    
    strcpy(aluno2.nome, "Pedro Costa");
    aluno2.idade = 21;
    aluno2.media = 7.5;
    
    strcpy(aluno3.nome, "Ana Souza");
    aluno3.idade = 20;
    aluno3.media = 8.0;
    
    printf("Aluno 1: %s, %d anos, media %.2f\n", 
           aluno1.nome, aluno1.idade, aluno1.media);
    printf("Aluno 2: %s, %d anos, media %.2f\n", 
           aluno2.nome, aluno2.idade, aluno2.media);
    printf("Aluno 3: %s, %d anos, media %.2f\n", 
           aluno3.nome, aluno3.idade, aluno3.media);
    
    return 0;
}