int ehBalanceada(No* raiz) {
    if (raiz == NULL) return 0;

    int alturaEsq = ehBalanceada(raiz->esq);
    if (alturaEsq == -1) return -1; // Subárvore esquerda desbalanceada

    int alturaDir = ehBalanceada(raiz->dir);
    if (alturaDir == -1) return -1; // Subárvore direita desbalanceada

    if (abs(alturaEsq - alturaDir) > 1) return -1; // Árvore desbalanceada

    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}
