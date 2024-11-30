#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista encadeada (elemento da pilha)
typedef struct No {
    char dado;         // Armazena o caractere atual ('(', '{', '[')
    struct No* prox;   // Ponteiro para o próximo nó na lista
} No;

// Estrutura da pilha utilizando lista encadeada
typedef struct Pilha {
    No* topo;          // Ponteiro para o nó no topo da pilha
} Pilha;

// Função para inicializar a pilha
void inicializaPilha(Pilha* p) {
    p->topo = NULL;    // Define o topo como NULL, indicando que a pilha está vazia
}

// Função para empilhar um elemento
void push(Pilha* p, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));  // Aloca memória para um novo nó
    if (!novoNo) {                         // Verifica se a memória foi alocada corretamente
        printf("Erro de alocação de memória!\n");
        exit(1);                           // Encerra o programa em caso de erro
    }
    novoNo->dado = valor;                  // Atribui o valor ao novo nó
    novoNo->prox = p->topo;                // O próximo nó aponta para o antigo topo
    p->topo = novoNo;                      // Atualiza o topo para o novo nó
}

// Função para desempilhar um elemento
void pop(Pilha* p) {
    if (p->topo != NULL) {                 // Só remove se a pilha não estiver vazia
        No* temp = p->topo;                // Salva o nó do topo em uma variável temporária
        p->topo = p->topo->prox;           // Atualiza o topo para o próximo nó
        free(temp);                        // Libera a memória do nó removido
    }
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* p) {
    return p->topo == NULL;                // Retorna 1 (verdadeiro) se o topo for NULL
}

// Função para liberar toda a memória da pilha
void limpaPilha(Pilha* p) {
    while (!estaVazia(p)) {                // Enquanto a pilha não estiver vazia
        pop(p);                            // Remove todos os elementos da pilha
    }
}

// Função para verificar se a expressão tem os parênteses balanceados
int BemFormada(char s[]) {
    Pilha pilha;
    inicializaPilha(&pilha);               // Inicializa a pilha

    // Percorre cada caractere da string
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case ')':                      // Caso seja um parêntese de fechamento
                if (!estaVazia(&pilha) && pilha.topo->dado == '(') {
                    pop(&pilha);           // Desempilha o parêntese correspondente
                } else {
                    limpaPilha(&pilha);    // Limpa a pilha antes de retornar
                    return 0;              // Retorna 0 (não está bem formada)
                }
                break;

            case '}':                      // Caso seja uma chave de fechamento
                if (!estaVazia(&pilha) && pilha.topo->dado == '{') {
                    pop(&pilha);           // Desempilha a chave correspondente
                } else {
                    limpaPilha(&pilha);
                    return 0;
                }
                break;

            case ']':                      // Caso seja um colchete de fechamento
                if (!estaVazia(&pilha) && pilha.topo->dado == '[') {
                    pop(&pilha);           // Desempilha o colchete correspondente
                } else {
                    limpaPilha(&pilha);
                    return 0;
                }
                break;

            case '(':                      // Caso seja um parêntese de abertura
            case '{':                      // Caso seja uma chave de abertura
            case '[':                      // Caso seja um colchete de abertura
                push(&pilha, s[i]);        // Empilha o caractere de abertura
                break;

            default:                       // Ignora qualquer outro caractere
                break;
        }
    }

    // Verifica se a pilha está vazia ao final
    int resultado = estaVazia(&pilha);     // Se a pilha estiver vazia, está bem formada
    limpaPilha(&pilha);                    // Libera a memória restante
    return resultado;
}

// Função principal
int main() {
    int N;
    scanf("%d", &N);                       // Lê o número de expressões a serem verificadas
    getchar();                             // Limpa o buffer após o scanf

    for (int i = 0; i < N; i++) {
        char expressao[1001];              // Buffer para armazenar a expressão
        fgets(expressao, 1001, stdin);     // Lê a expressão (máximo de 1000 caracteres)
        expressao[strcspn(expressao, "\n")] = '\0';  // Remove o '\n' ao final da string

        if (BemFormada(expressao)) {       // Chama a função para verificar a expressão
            printf("correct\n");           // Imprime "correct" se estiver bem formada
        } else {
            printf("incorrect\n");         // Imprime "incorrect" caso contrário
        }
    }

    return 0;                              // Encerra o programa com sucesso
}
 