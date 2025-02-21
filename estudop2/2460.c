#include <stdio.h>

typedef struct{
    int valor;
    list *next;
}list;


int popCB(list *head, int id){
    list *aux = head;
    list *prev = NULL;
    
    if(aux != NULL || aux->valor ==valor){
        head->next = aux->next;
        free(aux);
    }
    
    while(aux->valor != id){
        prev=aux;
        aux= aux->next;
    }
    prev->next = aux->next;
    free(aux); //o free é apenas no nó removido
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

