#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    float media;
} Aluno;

int aprovado(Aluno aluno) {
    if(aluno.media >= 10.0) {
        return 1;  // 1 significa verdadeiro (aprovado)
    } else {
        return 0;  // 0 significa falso (reprovado)
    }
}

int main() {
    Aluno aluno1;
    
    strcpy(aluno1.nome, "Carlos Lima");
    aluno1.idade = 22;
    aluno1.media = 11.5;
    
    if(aprovado(aluno1) == 1) {
        printf("%s esta APROVADO com media %.2f\n", 
               aluno1.nome, aluno1.media);
    } else {
        printf("%s esta REPROVADO com media %.2f\n", 
               aluno1.nome, aluno1.media);
    }
    
    return 0;
}