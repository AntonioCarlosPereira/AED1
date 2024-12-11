#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    char dado;
    struct Node *prox;
} Node;

// Função para empilhar (push)
void push(Node **topo, char valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

// Função para desempilhar (pop)
char pop(Node **topo) {
    if (*topo == NULL) return '\0'; // Pilha vazia
    Node *temp = *topo;
    char valor = temp->dado;
    *topo = temp->prox;
    free(temp);
    return valor;
}

// Função para contar diamantes em uma string
int contar_diamantes(char *entrada) {
    Node *pilha = NULL; // Pilha inicializada como vazia
    int diamantes = 0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == '<') {
            push(&pilha, '<');
        } else if (entrada[i] == '>') {
            if (pop(&pilha) == '<') {
                diamantes++;
            }
        }
    }

    // Limpa a pilha caso haja elementos restantes
    while (pilha != NULL) {
        pop(&pilha);
    }

    return diamantes;
}

int main() {
    int N;
    printf("Digite o número de casos de teste: ");
    scanf("%d", &N);
    getchar(); // Limpa o buffer do teclado após o número

    for (int i = 0; i < N; i++) {
        char entrada[1001];
        fgets(entrada, 1001, stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; // Remove o caractere de nova linha
        printf("%d\n", contar_diamantes(entrada));
    }

    return 0;
}
