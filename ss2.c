#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da fila duplamente encadeada
typedef struct Fila {
    int Per;
    struct Fila *seg;
    struct Fila *ant;
} Fila;

// Função para adicionar um elemento à fila
void Push(Fila **head, Fila **tail, int x) {
    Fila *new = malloc(sizeof(Fila));  // Aloca memória para um novo nó
    if (new == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    new->Per = x;        // Define o valor do novo nó
    new->seg = NULL;     // Inicialmente, o próximo é NULL
    new->ant = *tail;    // O anterior aponta para o atual último nó

    if (*tail != NULL) {
        (*tail)->seg = new;  // Atualiza o ponteiro do último nó
    }
    *tail = new;         // Atualiza o ponteiro do último nó

    if (*head == NULL) {
        *head = new;     // Se a lista estava vazia, atualiza a cabeça
    }
}

// Função para remover um elemento da fila
void RemoveePop(Fila **head, Fila **tail, int x) {
    Fila *temp = *head;

    while (temp != NULL) {
        if (temp->Per == x) {
            if (temp->ant != NULL) {
                temp->ant->seg = temp->seg;
            } else {
                *head = temp->seg;
            }
            if (temp->seg != NULL) {
                temp->seg->ant = temp->ant;
            } else {
                *tail = temp->ant;
            }
            free(temp);  // Libera a memória do nó
            return;
        }
        temp = temp->seg;
    }
}

// Função para imprimir a fila
void PrintFila(Fila *p) {
    int primeiro = 1;
    while (p != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", p->Per);
        primeiro = 0;
        p = p->seg;
    }
    printf("\n");
}

int main() {
    Fila *head = NULL;  // Cabeça da lista
    Fila *tail = NULL;  // Cauda da lista
    int N, M;
    
    // Lê a quantidade de elementos na fila inicial
    scanf("%d", &N);
    getchar();  // Consome o newline após o número de elementos
    
    // Lê os elementos da fila inicial
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        Push(&head, &tail, temp);
    }
    
    // Lê a quantidade de elementos a serem removidos
    scanf("%d", &M);
    getchar();  // Consome o newline após o número de elementos a serem removidos
    
    // Lê os elementos a serem removidos
    for (int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);
        RemoveePop(&head, &tail, temp);
    }
    
    // Imprime a fila resultante
    PrintFila(head);
    
    return 0;
}
