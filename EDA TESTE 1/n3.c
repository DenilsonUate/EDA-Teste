#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    float media;
} Aluno;

int main() {
    Aluno alunos[5];
    int i;  // DECLARADO FORA do for
    
    for(i = 0; i < 5; i++) {
        printf("\n--- Aluno %d ---\n", i+1);
        printf("Nome: ");
        fgets(alunos[i].nome, 100, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;
        
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        
        printf("Media: ");
        scanf("%f", &alunos[i].media);
        while(getchar() != '\n');
    }
    
    printf("\n--- Dados dos Alunos ---\n");
    for(i = 0; i < 5; i++) {
        printf("Aluno %d: %s, %d anos, media %.2f\n", 
               i+1, alunos[i].nome, alunos[i].idade, alunos[i].media);
    }
    
    return 0;
}