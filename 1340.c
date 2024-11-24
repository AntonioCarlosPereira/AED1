#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura de um nó da lista
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Funções para operações com listas encadeadas

// Insere no topo (para pilha ou fila de prioridade)
void inserir_inicio(No **inicio, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *inicio;
    *inicio = novo;
}

// Insere no fim (para fila)
void inserir_fim(No **inicio, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Insere de forma ordenada (para fila de prioridade)
void inserir_ordenado(No **inicio, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;

    if (*inicio == NULL || (*inicio)->valor < valor) {
        novo->proximo = *inicio;
        *inicio = novo;
    } else {
        No *atual = *inicio;
        while (atual->proximo != NULL && atual->proximo->valor >= valor) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

// Remove do início
int remover_inicio(No **inicio) {
    if (*inicio == NULL) return -1;  // Lista vazia

    No *removido = *inicio;
    int valor = removido->valor;
    *inicio = removido->proximo;
    free(removido);
    return valor;
}

// Verifica se a lista está vazia
bool lista_vazia(No *inicio) {
    return inicio == NULL;
}

// Limpa toda a lista
void limpar_lista(No **inicio) {
    while (!lista_vazia(*inicio)) {
        remover_inicio(inicio);
    }
}

// Programa principal
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        No *pilha = NULL, *fila = NULL, *fila_prioridade = NULL;
        bool is_stack = true, is_queue = true, is_pqueue = true;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);

            if (op == 1) {
                scanf("%d", &x);

                // Inserções nas três estruturas
                inserir_inicio(&pilha, x);  // Pilha
                inserir_fim(&fila, x);     // Fila
                inserir_ordenado(&fila_prioridade, x);  // Fila de prioridade
            } else if (op == 2) {
                scanf("%d", &x);

                // Verificar pilha
                if (is_stack) {
                    int valor = remover_inicio(&pilha);
                    if (valor != x) is_stack = false;
                }

                // Verificar fila
                if (is_queue) {
                    int valor = remover_inicio(&fila);
                    if (valor != x) is_queue = false;
                }

                // Verificar fila de prioridade
                if (is_pqueue) {
                    int valor = remover_inicio(&fila_prioridade);
                    if (valor != x) is_pqueue = false;
                }
            }
        }

        // Determinar o resultado
        int count = is_stack + is_queue + is_pqueue;
        if (count == 0) {
            printf("impossible\n");
        } else if (count > 1) {
            printf("not sure\n");
        } else if (is_stack) {
            printf("stack\n");
        } else if (is_queue) {
            printf("queue\n");
        } else if (is_pqueue) {
            printf("priority queue\n");
        }

        // Limpar memória
        limpar_lista(&pilha);
        limpar_lista(&fila);
        limpar_lista(&fila_prioridade);
    }

    return 0;
}

