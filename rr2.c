#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista encadeada (elemento da pilha)
typedef struct No {
    char dado;
    struct No* prox;
} No;

// Estrutura da pilha com lista encadeada
typedef struct Pilha {
    No* topo;
} Pilha;

// Função para inicializar a pilha
void inicializaPilha(Pilha* p) {
    p->topo = NULL;
}

// Função para empilhar um elemento
void push(Pilha* p, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novoNo->dado = valor;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

// Função para desempilhar um elemento
void pop(Pilha* p) {
    if (p->topo != NULL) {
        No* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// Função para liberar toda a memória da pilha
void limpaPilha(Pilha* p) {
    while (!estaVazia(p)) {
        pop(p);
    }
}

// Função para verificar se a expressão tem os parênteses balanceados
int BemFormada(char s[]) {
    Pilha pilha;
    inicializaPilha(&pilha);

    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case ')': 
                if (!estaVazia(&pilha) && pilha.topo->dado == '(') {
                    pop(&pilha);  // Desempilha se há um '(' correspondente
                } else {
                    limpaPilha(&pilha);
                    return 0; // Parêntese não correspondente
                }
                break;

            case '}': 
                if (!estaVazia(&pilha) && pilha.topo->dado == '{') {
                    pop(&pilha);  // Desempilha se há um '{' correspondente
                } else {
                    limpaPilha(&pilha);
                    return 0; // Chave não correspondente
                }
                break;

            case ']': 
                if (!estaVazia(&pilha) && pilha.topo->dado == '[') {
                    pop(&pilha);  // Desempilha se há um '[' correspondente
                } else {
                    limpaPilha(&pilha);
                    return 0; // Colchete não correspondente
                }
                break;

            case '(': 
            case '{': 
            case '[': 
                push(&pilha, s[i]); // Empilha parêntese de abertura
                break;

            default: 
                // Ignora caracteres que não sejam parênteses, colchetes ou chaves
                break;
        }
    }

    int resultado = estaVazia(&pilha);
    limpaPilha(&pilha); // Libera qualquer memória restante
    return resultado;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Limpa o buffer após ler N

    for (int i = 0; i < N; i++) {
        char expressao[1001]; // Limite de 1000 caracteres conforme restrições
        fgets(expressao, 1001, stdin);
        expressao[strcspn(expressao, "\n")] = '\0'; // Remove nova linha

        if (BemFormada(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
