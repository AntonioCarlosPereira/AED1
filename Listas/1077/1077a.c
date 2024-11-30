
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

// Estrutura de nó para a lista encadeada
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Funções para manipular a pilha (baseada em lista encadeada)
Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node** top, char data) {
    Node* new_node = create_node(data);
    new_node->next = *top;
    *top = new_node;
}

char pop(Node** top) {
    if (*top == NULL) return '\0';  // Pilha vazia
    Node* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

char peek(Node* top) {
    if (top == NULL) return '\0';  // Pilha vazia
    return top->data;
}

int is_empty(Node* top) {
    return top == NULL;
}

// Função para verificar a precedência dos operadores
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Função para verificar se o operador é associativo à direita
int is_right_associative(char op) {
    return op == '^';
}

// Função principal para converter infixo para posfixo
void infix_to_postfix(char* infix, char* postfix) {
    Node* operators = NULL;  // Pilha usando lista encadeada
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {  // Operandos (letras ou números) vão direto para a saída
            postfix[k++] = c;
        } else if (c == '(') {  // Parêntese de abertura vai para a pilha
            push(&operators, c);
        } else if (c == ')') {  // Parêntese de fechamento
            while (!is_empty(operators) && peek(operators) != '(') {
                postfix[k++] = pop(&operators);
            }
            if (!is_empty(operators)) pop(&operators);  // Remove o '(' da pilha
        } else {  // Operadores
            while (!is_empty(operators) &&
                   precedence(peek(operators)) >= precedence(c) &&
                   (!is_right_associative(c) || precedence(peek(operators)) > precedence(c))) {
                postfix[k++] = pop(&operators);
            }
            push(&operators, c);
        }
    }

    // Esvazia a pilha restante
    while (!is_empty(operators)) {
        postfix[k++] = pop(&operators);
    }

    postfix[k] = '\0';  // Finaliza a string
}

int main() {
    int n;
    char infix[MAX], postfix[MAX];

    // Lê o número de casos de teste
    scanf("%d", &n);
    getchar();  // Consome o caractere de nova linha após o número

    for (int i = 0; i < n; i++) {
        fgets(infix, MAX, stdin);  // Lê a expressão infixa
        infix[strcspn(infix, "\n")] = '\0';  // Remove o '\n' ao final
        infix_to_postfix(infix, postfix);
        printf("%s\n", postfix);
    }

    return 0;
}
