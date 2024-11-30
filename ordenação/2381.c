#include <stdio.h>
#include <string.h>

// Função para ordenar um vetor de strings usando o algoritmo de seleção
void Selecao(int n, char *v[]) {
    int i, j, min;
    char *x;

    // Laço externo para percorrer todos os elementos
    for (i = 0; i < n-1; i++) {
        min = i; // Assume que o menor valor está no índice i
        // Laço interno para comparar o elemento atual com os próximos
        for (j = i + 1; j < n; j++) {
            // Comparação entre as strings usando a função strcmp
            // strcmp retorna um valor negativo se v[j] é "menor" que v[min] lexicograficamente
            if (strcmp(v[j], v[min]) < 0) {
                min = j; // Atualiza o índice do menor valor
            }
        }
        // Troca as strings de lugar, colocando a menor string no início
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main() {
    int N, K;

    // Lê os valores de N (quantidade de alunos) e K (posição do aluno desejado)
    scanf("%d %d", &N, &K);
    
    // Aloca memória para armazenar os nomes dos alunos
    char *name[N];
    
    // Laço para ler os nomes dos alunos
    for (int i = 0; i < N; i++) {
        // Aloca memória suficiente para armazenar nomes com até 20 caracteres (+1 para o '\0')
        name[i] = malloc(21 * sizeof(char));  
        // Lê o nome do aluno e armazena na memória alocada
        scanf("%s", name[i]);
    }

    // Chama a função de ordenação para ordenar os nomes em ordem alfabética
    Selecao(N, name);

    // Imprime o nome do K-ésimo aluno, lembrando que K é baseado em 1, então usamos K-1
    printf("%s\n", name[K - 1]);

    // Libera a memória alocada para os nomes dos alunos
    for (int i = 0; i < N; i++) {
        free(name[i]);
    }

    return 0;
}
