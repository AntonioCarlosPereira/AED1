#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    int valor;
    struct pilha *prox;
} Pilha;

// Função para empilhar (PUSH)
void Push(Pilha **head, int x) {
    Pilha *new = (Pilha *)malloc(sizeof(Pilha));
    new->valor = x;
    new->prox = *head;
    *head = new;
}

// Função para desempilhar (POP)
void Pop(Pilha **head) {
    if (*head == NULL) {
        return; // Pilha vazia, nada a remover
    }
    Pilha *temp = *head;
    *head = temp->prox;
    free(temp);
}

// Verifica se a pilha está vazia
int EV(Pilha **head) {
    return (*head == NULL);
}

// Retorna o menor valor na pilha (MIN)
int MV(Pilha **head) {
    if (*head == NULL) {
        return -1; // Pilha vazia
    }
    Pilha *temp = *head;
    int min = temp->valor; // Inicializa com o valor do primeiro nó
    while (temp != NULL) {
        if (temp->valor < min) {
            min = temp->valor;
        }
        temp = temp->prox;
    }
    return min;
}

int main() {
    int rep;
    char op[10];
    Pilha *head = NULL;

    // Leitura do número de operações
    scanf("%d", &rep);

    for (int i = 0; i < rep; i++) {
        scanf("%s", op);

        if (strcmp(op, "PUSH") == 0) {
            int value;
            scanf("%d", &value);
            Push(&head, value);
        } else if (strcmp(op, "POP") == 0) {
            if (EV(&head)) {
                printf("EMPTY\n");
            } else {
                Pop(&head);
            }
        } else if (strcmp(op, "MIN") == 0) {
            if (EV(&head)) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", MV(&head));
            }
        }
    }

    return 0;
}
