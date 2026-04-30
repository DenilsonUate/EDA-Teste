#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS 100
#define MAX_NOME 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    int idade;
    float media;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

// Funcao para cadastrar aluno
void cadastrarAluno() {
    if(totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }
    
    Aluno novoAluno;
    novoAluno.id = totalAlunos + 1;
    
    printf("\n--- CADASTRO DE ALUNO ---\n");
    printf("Nome: ");
    fgets(novoAluno.nome, MAX_NOME, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = 0;
    
    printf("Idade: ");
    scanf("%d", &novoAluno.idade);
    
    printf("Media: ");
    scanf("%f", &novoAluno.media);
    while(getchar() != '\n');
    
    alunos[totalAlunos] = novoAluno;
    totalAlunos++;
    
    printf("\nAluno cadastrado com sucesso! ID: %d\n", novoAluno.id);
}

// Funcao para buscar aluno por nome
void buscarPorNome() {
    char busca[MAX_NOME];
    int encontrou = 0;
    int i;
    
    printf("\n--- BUSCA POR NOME ---\n");
    printf("Digite o nome: ");
    fgets(busca, MAX_NOME, stdin);
    busca[strcspn(busca, "\n")] = 0;
    
    printf("\nResultados da busca:\n");
    for(i = 0; i < totalAlunos; i++) {
        if(strstr(alunos[i].nome, busca) != NULL) {
            printf("ID: %d | Nome: %s | Idade: %d | Media: %.2f\n", 
                   alunos[i].id, alunos[i].nome, alunos[i].idade, alunos[i].media);
            encontrou = 1;
        }
    }
    
    if(!encontrou) {
        printf("Nenhum aluno encontrado com o nome \"%s\"\n", busca);
    }
}

// Funcao para ordenar por media (bubble sort)
void ordenarPorMedia() {
    Aluno temp;
    int i, j;
    
    for(i = 0; i < totalAlunos - 1; i++) {
        for(j = 0; j < totalAlunos - i - 1; j++) {
            if(alunos[j].media < alunos[j+1].media) {  // Ordem decrescente
                temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
        }
    }
    
    printf("\n--- ALUNOS ORDENADOS POR MEDIA (MAIOR PARA MENOR) ---\n");
    for(i = 0; i < totalAlunos; i++) {
        printf("%d. %s - Media: %.2f\n", i+1, alunos[i].nome, alunos[i].media);
    }
}

// Funcao para mostrar o aluno com melhor desempenho
void melhorDesempenho() {
    int i;
    int melhorIdx = 0;
    int melhorMedia = -1;
    
    if(totalAlunos == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }
    
    for(i = 0; i < totalAlunos; i++) {
        if(alunos[i].media > melhorMedia) {
            melhorMedia = alunos[i].media;
            melhorIdx = i;
        }
    }
    
    printf("\n=== MELHOR ALUNO ===\n");
    printf("Nome: %s\n", alunos[melhorIdx].nome);
    printf("ID: %d\n", alunos[melhorIdx].id);
    printf("Idade: %d\n", alunos[melhorIdx].idade);
    printf("Media: %.2f\n", alunos[melhorIdx].media);
    
    if(alunos[melhorIdx].media >= 10) {
        printf("Status: APROVADO com excelencia!\n");
    } else if(alunos[melhorIdx].media >= 7) {
        printf("Status: APROVADO\n");
    } else {
        printf("Status: REPROVADO\n");
    }
}

// Funcao para listar todos os alunos
void listarAlunos() {
    int i;
    
    if(totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    
    printf("\n=== LISTA DE ALUNOS ===\n");
    for(i = 0; i < totalAlunos; i++) {
        printf("ID: %d | Nome: %s | Idade: %d | Media: %.2f\n", 
               alunos[i].id, alunos[i].nome, alunos[i].idade, alunos[i].media);
    }
}

// Funcao para exibir menu
void exibirMenu() {
    printf("\n=== SISTEMA DE GESTAO DE ALUNOS ===\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Buscar aluno por nome\n");
    printf("3 - Listar alunos ordenados por media\n");
    printf("4 - Mostrar aluno com melhor desempenho\n");
    printf("5 - Listar todos os alunos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    
    printf("=== SISTEMA DE GESTAO DE ALUNOS ===\n");
    printf("Bem-vindo ao sistema!\n");
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        while(getchar() != '\n');
        
        switch(opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                buscarPorNome();
                break;
            case 3:
                if(totalAlunos > 0) {
                    ordenarPorMedia();
                } else {
                    printf("\nNenhum aluno cadastrado! Cadastre alunos primeiro.\n");
                }
                break;
            case 4:
                melhorDesempenho();
                break;
            case 5:
                listarAlunos();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
    
    return 0;
}
