#include <stdio.h>

typedef struct{
    int valor;
    Pilha *prox;
}Pilha;


int pop(Pilha *head){
    int v;
    Pilha *aux = head->next
    v = aux->valor
    head->next = head->nex->next;
    free aux;
    return v;
}

void push(int valor, Pilha *head){
    Pilha *new = (Pilha*) malloc(sizeof(Pilha*));
    new->valor = valor;
    new->next = head->next;
    head->next = new;
    
}

int mimpilha(Pilha *head, int NN){
    Pilha *aux = head;
    int mim = INT_MAX;
    
    for(int i = 0; i<NN; i++){
        if(aux->valor < mim){
            mim = aux->valor
        }
        aux = aux->next;
    }
    
    return mim;
}
