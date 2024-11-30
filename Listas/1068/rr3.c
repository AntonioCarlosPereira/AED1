#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Estrutura de um nó da pilha
struct pilhaNo {
    char valor;                 // Armazena o valor do nó (um caractere: '(' ou ')')
    struct pilhaNo* abaixo;     // Ponteiro para o nó abaixo na pilha
};

// Estrutura da pilha
struct pilha {
    int tamanho;                // Quantidade de elementos na pilha
    struct pilhaNo* topo;       // Ponteiro para o nó no topo da pilha
};

// Função para empilhar um elemento
void push(struct pilha* p, int valor) {
    p->tamanho += 1;                                     // Incrementa o tamanho da pilha
    struct pilhaNo* novoTopo = (struct pilhaNo*) malloc(sizeof(struct pilhaNo)); 
    // Aloca memória para o novo nó da pilha

    novoTopo->valor = valor;                             // Define o valor do nó
    novoTopo->abaixo = p->topo;                          // Conecta o nó atual ao antigo topo
    p->topo = novoTopo;                                  // Atualiza o topo da pilha
}

// Função para desempilhar um elemento
void pop(struct pilha* p) {
    if (p->tamanho > 0) {                                // Só desempilha se a pilha não estiver vazia
        p->tamanho -= 1;                                 // Decrementa o tamanho da pilha
        struct pilhaNo* velhoTopo = p->topo;             // Guarda o nó atual do topo
        p->topo = p->topo->abaixo;                       // Atualiza o topo para o próximo nó
        free(velhoTopo);                                 // Libera a memória do nó removido
    }
}

// Função para acessar o valor do topo da pilha
char top(struct pilha* p) {
    return p->topo->valor;                               // Retorna o valor do nó no topo
}

// Função para verificar o tamanho da pilha
int size(struct pilha* p) {
    return p->tamanho;                                   // Retorna o número de elementos na pilha
}

// Função para verificar se a pilha está vazia
int empty(struct pilha* p) {
    return p->tamanho == 0;                              // Retorna 1 (verdadeiro) se a pilha está vazia
}

// Função para inicializar a pilha
void inicializa(struct pilha* p) {
    p->tamanho = 0;                                      // Define o tamanho inicial como zero
    p->topo = NULL;                                      // Define o topo inicial como NULL
}

// Função para destruir a pilha e liberar memória
void destroi(struct pilha* p) {
    while (!empty(p)) {                                  // Enquanto a pilha não estiver vazia
        pop(p);                                          // Remove todos os elementos
    }
}

// Função principal
int main() {
    int i, tam;
    struct pilha p;                                      // Declara a pilha
    char expressao[1001];                                // Buffer para a expressão (até 1000 caracteres)

    // Lê expressões até o final do arquivo (EOF)
    while (scanf("%s\n", &expressao) != EOF) {
        inicializa(&p);                                  // Inicializa a pilha para a nova expressão
        tam = strlen(expressao);                         // Obtém o tamanho da expressão

        // Percorre cada caractere da expressão
        for (i = 0; i < tam; ++i) {
            if (expressao[i] == '(') {                   // Parêntese de abertura
                push(&p, '(');                           // Empilha o parêntese
            } else if (expressao[i] == ')') {            // Parêntese de fechamento
                if (empty(&p))                           // Se a pilha está vazia, a expressão é inválida
                    break;
                else 
                    pop(&p);                             // Remove o parêntese correspondente
            }
        }

        // Verifica o estado final da pilha
        if (i == tam && empty(&p))                       // Se percorreu toda a expressão e a pilha está vazia
            printf("correct\n");                         // A expressão é bem formada
        else 
            printf("incorrect\n");                       // Caso contrário, não é bem formada

        destroi(&p);                                     // Libera a memória da pilha para a próxima expressão
    }

    return 0;                                            // Encerra o programa
}
