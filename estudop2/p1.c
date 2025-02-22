

typedef struct{
    int valor;
    struct celula *next;
}celula;

celula *busca(int x, calula *head){
    celula *aux = head;
    while (aux != NULL) {
        if (aux->valor == key) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

void push(int x, celula *head){
    celula *new = (celula*) malloc(sizeof(celula));
    new->valor = x;
    new->next = head->next;
    head->next = new;
    
}
