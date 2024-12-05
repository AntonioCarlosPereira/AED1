#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para um nó da lista encadeada
typedef struct Caixa {
    int tempo;            // Tempo ocupado do caixa
    struct Caixa* prox;   // Ponteiro para o próximo nó
} Caixa;

// Função para criar um novo nó
Caixa* criar_caixa() {
    Caixa* novo = (Caixa*)malloc(sizeof(Caixa));
    novo->tempo = 0;
    novo->prox = NULL;
    return novo;
}

// Função para adicionar um nó na lista
Caixa* adicionar_caixa(Caixa* cabeca) {
    Caixa* novo = criar_caixa();
    if (cabeca == NULL) {
        return novo;
    }
    Caixa* atual = cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return cabeca;
}

// Função para encontrar o caixa com menor tempo ocupado
Caixa* encontrar_menor_caixa(Caixa* cabeca) {
    Caixa* menor = cabeca;
    Caixa* atual = cabeca->prox;
    while (atual != NULL) {
        if (atual->tempo < menor->tempo) {
            menor = atual;
        }
        atual = atual->prox;
    }
    return menor;
}

// Função para calcular o tempo máximo ocupado
int calcular_tempo_total(Caixa* cabeca) {
    int max_tempo = 0;
    Caixa* atual = cabeca;
    while (atual != NULL) {
        if (atual->tempo > max_tempo) {
            max_tempo = atual->tempo;
        }
        atual = atual->prox;
    }
    return max_tempo;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int vi[N];  // Tempo por item para cada caixa
    int cj[M];  // Número de itens de cada cliente

    // Ler tempos por item de cada caixa
    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }

    // Ler itens dos clientes
    for (int i = 0; i < M; i++) {
        scanf("%d", &cj[i]);
    }

    // Criar a lista encadeada de caixas
    Caixa* cabeca = NULL;
    for (int i = 0; i < N; i++) {
        cabeca = adicionar_caixa(cabeca);
    }

    // Processar os clientes
    for (int i = 0; i < M; i++) {
        // Encontrar o caixa com menor tempo ocupado
        Caixa* menor = encontrar_menor_caixa(cabeca);
        
        // Atribuir o tempo do cliente ao caixa
        menor->tempo += cj[i] * vi[i % N]; // Aqui é necessário usar o tempo do caixa correto
    }

    // Calcular o tempo total
    int tempo_total = calcular_tempo_total(cabeca);

    // Imprimir o resultado
    printf("%d\n", tempo_total);

    // Liberar memória da lista encadeada
    Caixa* atual = cabeca;
    while (atual != NULL) {
        Caixa* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    return 0;
}
