#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    float media;
} Aluno;

void ordenarPorMedia(Aluno alunos[], int n) {
    Aluno temp;
    int i, j;  // DECLARADOS FORA
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(alunos[j].media > alunos[j+1].media) {
                temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
        }
    }
}

int main() {
    Aluno alunos[5];
    int i;  // DECLARADO FORA
    
    printf("--- Cadastro de Alunos ---\n");
    for(i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: ");
        fgets(alunos[i].nome, 100, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;
        
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        
        printf("Media: ");
        scanf("%f", &alunos[i].media);
        while(getchar() != '\n');
    }
    
    ordenarPorMedia(alunos, 5);
    
    printf("\n--- Alunos Ordenados por Media (Crescente) ---\n");
    for(i = 0; i < 5; i++) {
        printf("%s - Media: %.2f (Idade: %d)\n", 
               alunos[i].nome, alunos[i].media, alunos[i].idade);
    }
    
    return 0;
}