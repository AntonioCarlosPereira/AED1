#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Biblioteca para verificar tipos de caracteres, como isalnum (alfanuméricos)

// Definição de um nó para a pilha
typedef struct Pilha {
    int x;                 // Armazena o valor do nó (operador ou operando)
    struct Pilha *next;    // Ponteiro para o próximo nó na pilha
} No;

// Função para empilhar um valor na pilha
void Push(int y, No *head) {
    No *new;
    new = (No*) malloc(sizeof(No));  // Aloca memória para um novo nó
    new->x = y;                      // Define o valor do novo nó
    new->next = head->next;          // Aponta para o nó atualmente no topo da pilha
    head->next = new;                // Atualiza o topo da pilha para o novo nó
}

// Função para desempilhar um valor da pilha
int Pop(No *head) {
    int z;                           // Variável para armazenar o valor do nó a ser removido
    No *q;
    q = head->next;                  // Aponta para o nó no topo da pilha
    z = q->x;                        // Obtém o valor do nó
    head->next = q->next;            // Atualiza o topo da pilha para o próximo nó
    free(q);                         // Libera a memória do nó removido
    return z;                        // Retorna o valor do nó desempilhado
}

// Função para converter uma expressão infixa para pós-fixa
void FtoP(char *Eq) {
    No head;                         // Estrutura que gerencia a pilha
    head.next = NULL;                // Inicializa a pilha como vazia
    int k = 0;                       // Índice para o resultado pós-fixo
    char result[301] = {0};          // String que armazenará a expressão pós-fixa
    
    for (int i = 0; Eq[i] != '\0'; i++) {  // Itera sobre cada caractere da expressão
        if (isalnum(Eq[i])) {              // Verifica se o caractere é alfanumérico
            result[k++] = Eq[i];           // Adiciona diretamente ao resultado
        }
        if (Eq[i] == '(') {                // Parêntese de abertura
            Push(Eq[i], &head);            // Empilha o parêntese
        }
        if (Eq[i] == ')') {                // Parêntese de fechamento
            // Desempilha e adiciona ao resultado até encontrar o parêntese de abertura
            while (Pop(&head) != '(') {
                result[k++] = Pop(&head);
            }
        }
        if (Eq[i] == '*' || Eq[i] == '+' || Eq[i] == '/' || Eq[i] == '-' || Eq[i] == '^') {
            // Operadores são empilhados para gerenciar a precedência
            Push(Eq[i], &head);
        }
    }
    printf("%s\n", result);                // Exibe o resultado da conversão
}

// Função principal
int main() {
    int N;                                 // Número de expressões a serem processadas
    char Eq[301];                          // Buffer para armazenar cada expressão
    
    scanf("%d", &N);                       // Lê o número de expressões
    getchar();                             // Remove o newline após a entrada de N
    
    for (int i = 0; i < N; i++) {          // Itera sobre cada expressão
        fgets(Eq, sizeof(Eq), stdin);      // Lê a expressão infixa
        FtoP(Eq);                          // Converte para pós-fixa e exibe o resultado
    }
    
    return 0;                              // Indica execução bem-sucedida
}

