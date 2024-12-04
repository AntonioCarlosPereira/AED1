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
    No *novo = (No *)malloc(sizeof(No)); // Cria um novo nó
    novo->valor = valor;
    novo->proximo = *inicio; // O próximo do novo nó aponta para o início da lista
    *inicio = novo; // Atualiza o início da lista
}

// Insere no fim (para fila)
void inserir_fim(No **inicio, int valor) {
    No *novo = (No *)malloc(sizeof(No)); // Cria um novo nó
    novo->valor = valor;
    novo->proximo = NULL; // O próximo do novo nó é NULL

    if (*inicio == NULL) {
        *inicio = novo; // Se a lista estiver vazia, o novo nó é o início
    } else {
        No *atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo; // Vai até o final da lista
        }
        atual->proximo = novo; // O último nó aponta para o novo nó
    }
}

// Insere de forma ordenada (para fila de prioridade)
void inserir_ordenado(No **inicio, int valor) {
    No *novo = (No *)malloc(sizeof(No)); // Cria um novo nó
    novo->valor = valor;

    // Insere o novo nó na posição correta (ordenada)
    if (*inicio == NULL || (*inicio)->valor < valor) {
        novo->proximo = *inicio; // Coloca o novo nó no início
        *inicio = novo;
    } else {
        No *atual = *inicio;
        while (atual->proximo != NULL && atual->proximo->valor >= valor) {
            atual = atual->proximo; // Encontra a posição correta
        }
        novo->proximo = atual->proximo; // Coloca o novo nó na posição
        atual->proximo = novo; // Atualiza o ponteiro do nó anterior
    }
}

// Remove do início
int remover_inicio(No **inicio) {
    if (*inicio == NULL) return -1;  // Lista vazia

    No *removido = *inicio;
    int valor = removido->valor;
    *inicio = removido->proximo;  // Atualiza o início da lista
    free(removido); // Libera a memória do nó removido
    return valor;
}

// Verifica se a lista está vazia
bool lista_vazia(No *inicio) {
    return inicio == NULL;
}

// Limpa toda a lista
void limpar_lista(No **inicio) {
    while (!lista_vazia(*inicio)) {
        remover_inicio(inicio); // Remove todos os nós
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
        } else {
            if (is_stack) {
                printf("stack\n");
            } else if (is_queue) {
                printf("queue\n");
            } else if (is_pqueue) {
                printf("priority queue\n");
            }
        }

        // Limpar as listas
        limpar_lista(&pilha);
        limpar_lista(&fila);
        limpar_lista(&fila_prioridade);
    }

    return 0;
}
