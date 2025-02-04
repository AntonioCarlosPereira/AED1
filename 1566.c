#include <stdio.h>
#include <stdlib.h>

void countingSort(int *V, int n, int limite) {
    // Aloca o vetor auxiliar para contar as ocorrências
    int *aux = (int *)calloc(limite, sizeof(int)); // Usa calloc para inicializar com 0

    // Conta as ocorrências dos elementos no vetor V
    for (int i = 0; i < n; ++i) {
        aux[V[i]]++;
    }

    // Reconstrói o vetor V com os elementos ordenados
    int k = 0;
    for (int i = 0; i < limite; ++i) {
        for (int j = 0; j < aux[i]; ++j) {
            V[k++] = i;
        }
    }

    free(aux); // Libera a memória alocada
}

int main(void) {
    int NC, N;

    // Leitura do número de casos de teste
    scanf("%d", &NC);
    while (NC--) {
        // Leitura do tamanho do vetor
        scanf("%d", &N);

        // Aloca o vetor V dinamicamente
        int *V = (int *)malloc(N * sizeof(int));

        // Leitura dos elementos do vetor
        for (int i = 0; i < N; ++i) {
            scanf("%d", &V[i]);
        }

        // Aplica o Counting Sort no vetor
        countingSort(V, N, 231);

        // Impressão dos elementos ordenados
        printf("%d", V[0]);
        for (int i = 1; i < N; ++i) {
            printf(" %d", V[i]);
        }
        printf("\n");

        free(V); // Libera a memória alocada para o vetor V
    }

    return 0;
}
