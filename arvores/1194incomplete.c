#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct ArvoreB { // Estrutura da árvore binária
    char let;
    struct ArvoreB *E;
    struct ArvoreB *D;
} ArvoreB;

// Função para criar um novo nó
ArvoreB* novoNo(char letra) {
    ArvoreB *no = (ArvoreB *) malloc(sizeof(ArvoreB));
    no->let = letra;
    no->E = no->D = NULL;
    return no;
}

// Função que encontra o índice de uma letra na string inF
int indRI(char *str, int inicio, int fim, char letra) {
    for (int i = inicio; i <= fim; i++) {
        if (str[i] == letra)
            return i;
    }
    return -1; // Retorna -1 caso não encontre
}

// Função que monta a árvore baseada nas travessias pré-ordem (preF) e in-ordem (inF)
ArvoreB* Arv(char *preF, char *inF, int start, int end, int *indice) {
    if (start > end) { // Condição de parada
        return NULL;
    }
    
    // Cria o nó com o próximo caractere da pré-ordem
    ArvoreB *node = novoNo(preF[(*indice)++]);

    // Se só há um elemento, retorna o nó
    if (start == end) {
        return node;
    }

    // Encontra o índice da raiz na in-ordem
    int RaizInf = indRI(inF, start, end, node->let);

    // Constrói a subárvore esquerda e direita
    node->E = Arv(preF, inF, start, RaizInf - 1, indice);
    node->D = Arv(preF, inF, RaizInf + 1, end, indice);

    return node; // Retorna a raiz
}

// Função para imprimir a árvore em pós-ordem
void showposfixa(ArvoreB *no) {
    if (no == NULL)
        return;

    showposfixa(no->E);
    showposfixa(no->D);
    printf("%c", no->let);
}

int main() {
    char preF[] = "ABDFECG"; // Exemplo de percurso pré-ordem
    char inF[]  = "DBFAECG"; // Exemplo de percurso in-ordem
    int indice = 0;

    // Criando a árvore binária
    ArvoreB *raiz = Arv(preF, inF, 0, 6, &indice);

    // Exibindo a árvore em pós-ordem
    printf("Pós-ordem: ");
    showposfixa(raiz);
    printf("\n");

    return 0;
}
