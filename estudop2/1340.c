#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int valor;
    struct list *next;
} list;

int popFila(list *head) {
    if (head->next == NULL) return -1; // Fila vazia
    
    int v;
    list *aux = head->next;
    v = aux->valor;
    head->next = aux->next;
    free(aux);
    return v;
}

void pushFila(int x, list *head) {
    list *new = (list*) malloc(sizeof(list));
    list *aux = head;
    
    while (aux->next != NULL) {
        aux = aux->next;
    }
    
    new->valor = x;
    new->next = NULL;
    
    aux->next = new;
}

void pushPilha(int valor, list *head) {
    list *new = (list*) malloc(sizeof(list));
    new->valor = valor;
    new->next = head->next;
    head->next = new;
}

int popPilha(list *head) {
    if (head->next == NULL) return -1; // Pilha vazia

    int v;
    list *aux = head->next;
    v = aux->valor;
    head->next = aux->next;
    free(aux);
    return v;
}

void pushFilaPrioridade(int x, list *head) {
    list *new = (list*) malloc(sizeof(list));
    list *aux = head;

    while (aux->next != NULL && aux->next->valor >= x) {
        aux = aux->next;
    }
    
    new->valor = x;
    new->next = aux->next;
    aux->next = new;
}

int popFilaPrioridade(list *head) {
    if (head->next == NULL) return -1; // Fila de prioridade vazia
    
    int v;
    list *aux = head->next;
    v = aux->valor;
    head->next = aux->next;
    free(aux);
    return v;
}
