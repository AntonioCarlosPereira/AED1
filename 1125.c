#include <stdio.h>
#include <string.h>

#define MAX_G 100
#define MAX_P 100
#define MAX_S 10

void process_campeonato() {
    while (1) {
        int G, P;
        scanf("%d %d", &G, &P);
        if (G == 0 && P == 0) {
            break;
        }

        int resultados[MAX_G][MAX_P];
        for (int i = 0; i < G; i++) {
            for (int j = 0; j < P; j++) {
                scanf("%d", &resultados[i][j]);
            }
        }

        int S;
        scanf("%d", &S);
        for (int s = 0; s < S; s++) {
            int K;
            scanf("%d", &K);

            int pontuacao[K];
            for (int k = 0; k < K; k++) {
                scanf("%d", &pontuacao[k]);
            }

            int total_pontos[MAX_P] = {0};

            // Calcula os pontos de cada piloto para o sistema atual
            for (int g = 0; g < G; g++) {
                for (int p = 0; p < P; p++) {
                    int posicao = resultados[g][p] - 1; // Convertendo para índice 0
                    if (posicao < K) {
                        total_pontos[p] += pontuacao[posicao];
                    }
                }
            }

            // Determina o(s) campeão(ões)
            int max_pontos = 0;
            for (int p = 0; p < P; p++) {
                if (total_pontos[p] > max_pontos) {
                    max_pontos = total_pontos[p];
                }
            }

            // Imprime os campeões
            int primeiro = 1;
            for (int p = 0; p < P; p++) {
                if (total_pontos[p] == max_pontos) {
                    if (!primeiro) {
                        printf(" ");
                    }
                    printf("%d", p + 1);
                    primeiro = 0;
                }
            }
            printf("\n");
        }
    }
}

int main() {
    process_campeonato();
    return 0;
}
