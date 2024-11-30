#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300  // Define o tamanho máximo das expressões infixas e posfixas

// Estrutura de nó para a lista encadeada
typedef struct Node {
    char data;          // Armazena o valor do operador ou caractere
    struct Node* next;  // Ponteiro para o próximo nó na pilha
} Node;

// Funções para manipular a pilha (baseada em lista encadeada)

// Cria um novo nó da pilha com o valor especificado
Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));  // Aloca memória para o nó
    new_node->data = data;  // Define o valor do nó
    new_node->next = NULL;  // O próximo inicialmente aponta para NULL
    return new_node;
}

// Empilha um valor (push) na pilha
void push(Node** top, char data) {
    Node* new_node = create_node(data);  // Cria um novo nó com o valor
    new_node->next = *top;  // O próximo do novo nó aponta para o nó do topo
    *top = new_node;  // Atualiza o topo da pilha para o novo nó
}

// Remove e retorna o valor no topo da pilha (pop)
char pop(Node** top) {
    if (*top == NULL) return '\0';  // Retorna '\0' se a pilha estiver vazia
    Node* temp = *top;  // Nó temporário para armazenar o topo atual
    char data = temp->data;  // Armazena o valor do topo
    *top = temp->next;  // Atualiza o topo para o próximo nó
    free(temp);  // Libera a memória do nó removido
    return data;  // Retorna o valor removido
}

// Retorna o valor no topo da pilha sem removê-lo
char peek(Node* top) {
    if (top == NULL) return '\0';  // Retorna '\0' se a pilha estiver vazia
    return top->data;  // Retorna o valor do topo
}

// Verifica se a pilha está vazia
int is_empty(Node* top) {
    return top == NULL;  // Retorna 1 se a pilha estiver vazia, 0 caso contrário
}

// Função para verificar a precedência dos operadores
int precedence(char op) {
    // Operadores de maior precedência retornam valores maiores
    switch (op) {
        case '+': case '-': return 1;  // Soma e subtração têm menor precedência
        case '*': case '/': return 2;  // Multiplicação e divisão têm precedência média
        case '^': return 3;            // Exponenciação tem maior precedência
        default: return 0;             // Outros caracteres retornam 0
    }
}

// Verifica se o operador é associativo à direita (ex.: '^')
int is_right_associative(char op) {
    return op == '^';  // Exponenciação é associativa à direita
}

// Função para converter uma expressão infixa para notação posfixa
void infix_to_postfix(char* infix, char* postfix) {
    Node* operators = NULL;  // Pilha para armazenar operadores
    int k = 0;  // Índice para a string de saída (postfix)

    // Percorre a string de entrada (infix)
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {  // Operandos (letras ou números) vão direto para a saída
            postfix[k++] = c;
        } else if (c == '(') {  // Parêntese de abertura vai para a pilha
            push(&operators, c);
        } else if (c == ')') {  // Parêntese de fechamento
            while (!is_empty(operators) && peek(operators) != '(') {
                postfix[k++] = pop(&operators);  // Desempilha até encontrar '('
            }
            if (!is_empty(operators)) pop(&operators);  // Remove o '('
        } else {  // Operadores
            // Enquanto o operador no topo da pilha tiver maior ou igual precedência
            // e não for associativo à direita
            while (!is_empty(operators) &&
                   precedence(peek(operators)) >= precedence(c) &&
                   (!is_right_associative(c) || precedence(peek(operators)) > precedence(c))) {
                postfix[k++] = pop(&operators);  // Move o operador para a saída
            }
            push(&operators, c);  // Empilha o operador atual
        }
    }

    // Esvazia os operadores restantes na pilha
    while (!is_empty(operators)) {
        postfix[k++] = pop(&operators);
    }

    postfix[k] = '\0';  // Finaliza a string de saída com '\0'
}

int main() {
    int n;
    char infix[MAX], postfix[MAX];

    // Lê o número de expressões a serem convertidas
    scanf("%d", &n);
    getchar();  // Consome o caractere de nova linha após o número

    for (int i = 0; i < n; i++) {
        fgets(infix, MAX, stdin);  // Lê a expressão infixa
        infix[strcspn(infix, "\n")] = '\0';  // Remove o '\n' ao final da string
        infix_to_postfix(infix, postfix);  // Converte para notação posfixa
        printf("%s\n", postfix);  // Imprime o resultado
    }

    return 0;
}
