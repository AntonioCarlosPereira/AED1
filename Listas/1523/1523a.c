#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000 // Máximo de motoristas
#define MAX_K 1000  // Máximo de carros no estacionamento

// Estrutura para armazenar eventos
typedef struct {
    int tempo;
    char tipo; // 'C' para chegada, 'S' para saída
} Evento;

// Função de comparação para ordenar os eventos
// Ordena por tempo crescente. Se os tempos forem iguais, 'S' (saída) vem antes de 'C' (chegada).
int comparar_eventos(const void *a, const void *b) {
    Evento *ea = (Evento *)a;
    Evento *eb = (Evento *)b;
    if (ea->tempo == eb->tempo) {
        return ea->tipo - eb->tipo; // 'S' vem antes de 'C' para empates
    }
    return ea->tempo - eb->tempo;
}

int main() {
    int n, k;

    while (1) {
        // Ler o número de motoristas (N) e a capacidade do estacionamento (K)
        scanf("%d %d", &n, &k);
        
        // Caso de parada
        if (n == 0 && k == 0) break;

        Evento eventos[2 * MAX_N];
        int total_eventos = 0;

        // Ler os horários de chegada e saída de cada motorista
        for (int i = 0; i < n; i++) {
            int chegada, saida;
            scanf("%d %d", &chegada, &saida);
            eventos[total_eventos++] = (Evento){chegada, 'C'}; // Evento de chegada
            eventos[total_eventos++] = (Evento){saida, 'S'};   // Evento de saída
        }

        // Ordenar os eventos
        qsort(eventos, total_eventos, sizeof(Evento), comparar_eventos);

        // Simular o estacionamento
        int carros_estacionados = 0; // Número de carros no estacionamento
        int possivel = 1; // Flag para verificar se o caso é possível

        for (int i = 0; i < total_eventos; i++) {
            if (eventos[i].tipo == 'C') {
                // Chegada: verificar se há espaço
                if (carros_estacionados < k) {
                    carros_estacionados++; // Estaciona o carro
                } else {
                    possivel = 0; // Sem espaço, impossível estacionar
                    break;
                }
            } else if (eventos[i].tipo == 'S') {
                // Saída: verificar se há carros no estacionamento
                if (carros_estacionados > 0) {
                    carros_estacionados--; // Remove um carro
                } else {
                    possivel = 0; // Ordem inválida (saída sem carros)
                    break;
                }
            }
        }

        // Resultado do caso atual
        printf("%s\n", possivel ? "Sim" : "Nao");
    }

    return 0;
}
