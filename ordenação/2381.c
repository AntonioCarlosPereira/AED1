#include <stdio.h>
#include <string.h>

void Selecao(int n, char *v[]) {
    int i, j, min;
    char *x;

    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            // Comparação entre strings usando strcmp
            if (strcmp(v[j], v[min]) < 0) {
                min = j;
            }
        }
        // Troca de strings
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main() {
    int N, K;

    // Lendo os valores de N e K
    scanf("%d %d", &N, &K);
    
    // Alocando memória para os nomes dos alunos
    char *name[N];
    for (int i = 0; i < N; i++) {
        name[i] = malloc(21 * sizeof(char));  // Cada nome pode ter no máximo 20 caracteres
        scanf("%s", name[i]);
    }

    // Ordenando os nomes em ordem alfabética
    Selecao(N, name);

    // Imprimindo o nome do K-ésimo aluno (lembrando que K é 1-based)
    printf("%s\n", name[K - 1]);

    // Liberando a memória alocada
    for (int i = 0; i < N; i++) {
        free(name[i]);
    }

    return 0;
}
