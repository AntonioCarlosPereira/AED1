int altura(ArvoreB *raiz) {
    if(raiz == NULL){
        return 0;
    }
    if(altura(raiz->E) > altura(raiz->D)){
        return 1+ altura(raiz->E);
    }else{
        return 1+ altura(raiz->D);
    }

}
//se criarmos variaveis para altura->E e D seria um pouco mais eficiente

int altura(ArvoreB *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    int alturaEsq = altura(raiz->E);
    int alturaDir = altura(raiz->D);
    
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}
