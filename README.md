# EDA-Teste

# Trabalho de Algoritmos de Ordenação - Bubble Sort

## Descrição do Trabalho

**Grupo:** 
  -Denilson Sansao Uate;
  -Frederico Albino Jr;
  -Ludovina Dos Ceu Andre;
  -Sabura Tamimo Sorte.

Este trabalho implementa o algoritmo de ordenação **Bubble Sort** em suas duas versões:
- Versão padrão
- Versão otimizada (com interrupção antecipada)

## Explicação dos Algoritmos

### Bubble Sort Padrão
O Bubble Sort funciona comparando elementos adjacentes e trocando-os se estiverem na ordem errada. Esse processo se repete até que o vetor esteja completamente ordenado. A cada passagem completa, o maior elemento "flutua" para sua posição correta no final do vetor.

**Funcionamento:**
1. Percorre o vetor do início ao fim
2. Compara cada elemento com o próximo
3. Se estiverem fora de ordem, troca-os
4. Repete o processo para todos os elementos

### Bubble Sort Otimizado
A versão otimizada adiciona uma flag (variável de controle) que verifica se houve alguma troca durante uma passagem completa. Se nenhuma troca for realizada, significa que o vetor já está ordenado, e o algoritmo pode ser interrompido antecipadamente.

**Melhoria:** Evita passagens desnecessárias quando o vetor já está ordenado.

## Tabela de Complexidade

| Algoritmo      | Melhor Caso | Caso Médio | Pior Caso | Espaço |
|----------------|-------------|------------|-----------|--------|
| **Bubble Sort**  | O(n)        | O(n²)      | O(n²)     | O(1)   |
| **Selection Sort** | O(n²)      | O(n²)      | O(n²)     | O(1)   |
| **Insertion Sort** | O(n)      | O(n²)      | O(n²)     | O(1)   |

### Explicação da Tabela:

- **Melhor Caso:** Vetor já ordenado
- **Pior Caso:** Vetor em ordem decrescente
- **O(n):** Tempo linear (rápido)
- **O(n²):** Tempo quadrático (lento para grandes quantidades)
- **O(1):** Espaço constante (não usa memória extra significativa)

### Comparação entre os algoritmos:

| Característica | Bubble Sort | Selection Sort | Insertion Sort |
|----------------|-------------|----------------|----------------|
| **Estável?**   | Sim         | Não            | Sim            |
| **In-place?**  | Sim         | Sim            | Sim            |
| **Melhor para:** | Dados pequenos | Dados pequenos | Dados quase ordenados |

## Como Compilar e Executar

```bash
# Compilar todos os arquivos
gcc bubble_sort.c bubble_sort_otimizado.c main.c -o programa

# Executar
./programa
