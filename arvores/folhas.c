void count(ArvoreB *raiz) {
    if (raiz == NULL) {
        return;
    }

    // Verificar se é uma folha
    if (raiz->E == NULL && raiz->D == NULL) {
        printf("%d ", raiz->valor);  // Imprime o valor da folha
    }

    // Chamada recursiva nas subárvores esquerda e direita
    count(raiz->E);
    count(raiz->D);
}
