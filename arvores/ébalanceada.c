int ehBalanceada(No* raiz) {
    if (raiz == NULL) return 0;

    int alturaEsq = ehBalanceada(raiz->esq);
    if (alturaEsq == -1) return -1; // Subárvore esquerda desbalanceada

    int alturaDir = ehBalanceada(raiz->dir);
    if (alturaDir == -1) return -1; // Subárvore direita desbalanceada

    int diferencaAltura = alturaEsq - alturaDir;
    if (diferencaAltura > 1 || diferencaAltura < -1) return -1; // Árvore desbalanceada

    if (alturaEsq > alturaDir) {
        return 1 + alturaEsq;
    } else {
        return 1 + alturaDir;
    }
}
