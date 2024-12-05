#include <stdio.h>
#include <limits.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int vi[N];  // Tempo por item para cada funcionário
    int cj[M];  // Itens para cada cliente
    int caixas[N]; // Tempo ocupado de cada caixa
    
    // Inicializar os tempos ocupados dos caixas como 0
    for (int i = 0; i < N; i++) {
        caixas[i] = 0;
    }
    
    // Ler tempos dos funcionários
    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }
    
    // Ler os itens dos clientes
    for (int i = 0; i < M; i++) {
        scanf("%d", &cj[i]);
    }
    
    // Processar cada cliente
    for (int i = 0; i < M; i++) {
        int menor_tempo = INT_MAX;
        int idx_caixa = -1;
        
        // Encontrar o caixa com menor tempo ocupado
        for (int j = 0; j < N; j++) {
            if (caixas[j] < menor_tempo) {
                menor_tempo = caixas[j];
                idx_caixa = j;
            }
        }
        
        // Adicionar o tempo do cliente ao caixa escolhido
        caixas[idx_caixa] += cj[i] * vi[idx_caixa];
    }
    
    // Encontrar o tempo máximo entre os caixas
    int tempo_total = 0;
    for (int i = 0; i < N; i++) {
        if (caixas[i] > tempo_total) {
            tempo_total = caixas[i];
        }
    }
    
    // Imprimir o resultado
    printf("%d\n", tempo_total);
    return 0;
}
