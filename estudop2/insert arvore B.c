void insert(ArvoreB *raiz, int valor){
    if(raiz == NULL){
        ArvoreB *new = (ArvoreB*) malloc(sizeof(ArvoreB));
        new->value = valor;
        new->E = NULL;
        new->D = NULL;
    }
    if(valor < raiz->value){
        insert(raiz->E, valor);
    }
    if(valor > raiz->value){
        insert(raiz->D, valor);
    }
}
