#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct ArvoreB {
    char valor;
    struct ArvoreB *E;
    struct ArvoreB *D;
} ArvoreB;

ArvoreB* novoNo(char letra) {
    ArvoreB *no = (ArvoreB *) malloc(sizeof(ArvoreB)); // Corrigido: 'ArvoreB' no lugar de 'noArv'
    no->valor = letra;
    no->E = no->D = NULL;
    return no;
}

ArvoreB* inserir(ArvoreB *node, int valor) { // Corrigido: 'node, int valor'
    if (node == NULL) { // Corrigido: '==' para comparação
        ArvoreB *node = (ArvoreB*) malloc(sizeof(ArvoreB));
        node->valor = valor;
        node->D = NULL;
        node->E = NULL;
        return node;
    }
    if (valor < node->valor) {
        node->E = inserir(node->E, valor); // Corrigido: faltava ponto e vírgula
    }
    if (valor > node->valor) {
        node->D = inserir(node->D, valor); // Corrigido: faltava ponto e vírgula
    }
    
    return node;
}

ArvoreB* Arv(int vet[], int tamanho) { // Corrigido: 'vet[]' ao invés de 'vet'
    ArvoreB *source = NULL;
    for (int i = 0; i < tamanho; i++) {
        source = inserir(source, vet[i]);
    }
    return source;
}

void Pre(ArvoreB* raiz) {
    if (raiz != NULL) { // Corrigido: '!=' para comparação
        printf("%d ", raiz->valor); // Corrigido: 'raiz->valor' ao invés de '&raiz->valor'
        Pre(raiz->E);
        Pre(raiz->D);
    }
}

void Post(ArvoreB* raiz) { // Corrigido: nome da função para 'Post'
    if (raiz != NULL) { // Corrigido: '!=' para comparação
        Post(raiz->E);
        Post(raiz->D);
        printf("%d ", raiz->valor); // Corrigido: 'raiz->valor'
    }
}

void In(ArvoreB* raiz) {
    if (raiz != NULL) { // Corrigido: '!=' para comparação
        In(raiz->E);
        printf("%d ", raiz->valor); // Corrigido: 'raiz->valor'
        In(raiz->D);
    }
}

int main() {
    int C, N;
    int vet[500];
    int casos = 1; // Corrigido: 'casos' como nome de variável válido
    
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &vet[i]);
        }
        
        ArvoreB *Raiz = Arv(vet, N); // Corrigido: 'N' ao invés de 'sizeof(vet)'
        
        printf("Case %d:\n", casos++); // Corrigido: impressão da variável 'casos'
        printf("Pre.: ");
        Pre(Raiz);
        printf("\nIn..: ");
        In(Raiz);
        printf("\nPost: ");
        Post(Raiz);
        printf("\n");
    }
    
    return 0;
}
