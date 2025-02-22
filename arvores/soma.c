int cont(ArvoreB *raiz) {
    if (raiz == NULL) {
        return 0;  // Caso base: árvore vazia, retorna 0
    }
    
    // Conta o nó atual (1) e soma os nós das subárvores esquerda e direita
    return 1 + cont(raiz->E) + cont(raiz->D);
}
