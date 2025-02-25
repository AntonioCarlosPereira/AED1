#include <stdio.h>

typedef struct{
    int valor;
    list *next;
}list;


int popCB(list **head, int id) {
    if (*head == NULL) {
        return -1; // A lista está vazia
    }

    list *aux = *head;
    list *prev = NULL;

    // Verifica se o nó a ser removido é o primeiro
    if (aux->valor == id) {
        *head = aux->next; // O cabeçalho agora aponta para o próximo nó
        int valorRemovido = aux->valor; // Armazena o valor do nó removido
        free(aux); // Libera o nó removido
        return valorRemovido; // Retorna o valor do nó removido
    }

    // Procura pelo nó com o valor igual a id
    while (aux != NULL && aux->valor != id) {
        prev = aux;
        aux = aux->next;
    }

    // Se o nó não foi encontrado
    if (aux == NULL) {
        return -1; // Não encontrou o nó
    }

    prev->next = aux->next; // O nó anterior agora aponta para o próximo nó
    int valorRemovido = aux->valor; // Armazena o valor do nó removido
    free(aux); // Libera o nó removido
    return valorRemovido; // Retorna o valor do nó removido
}




void push(int valor, list *head){//push de uma list
    list *new = (list*) malloc(sizeof(list*));
    new->valor = valor;
    new->next =NULL;
    head->next = new;
    
    if(head == NULL){
        head = new;
    } else {
        list *aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new;
    }
    
}

