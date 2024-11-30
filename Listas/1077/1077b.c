#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definindo a estrutura para a pilha
typedef struct Pilha {
    char x;             // Armazena o valor (operador ou operando)
    struct Pilha *next; // Ponteiro para o próximo nó na pilha
} No;

// Função para adicionar um elemento à pilha (Push)
void Push(char y, No *head) {
    No *new = (No*) malloc(sizeof(No)); // Aloca um novo nó
    new->x = y;  // Atribui o valor (operador ou operando) ao nó
    new->next = head->next;  // O próximo do novo nó aponta para o topo da pilha
    head->next = new;  // O topo da pilha é atualizado para o novo nó
}

// Função para remover o elemento do topo da pilha (Pop)
char Pop(No *head) {
    No *q = head->next;   // Ponteiro para o nó do topo
    char z = q->x;        // Armazena o valor que será retornado
    head->next = q->next; // Atualiza o topo da pilha para o próximo nó
    free(q);              // Libera a memória do nó removido
    return z;             // Retorna o valor do topo removido
}

// Função para acessar o valor no topo da pilha sem removê-lo (Peek)
char Peek(No *head) {
    if (head->next) return head->next->x; // Se a pilha não estiver vazia, retorna o valor do topo
    return '\0'; // Se a pilha estiver vazia, retorna '\0'
}

// Função para determinar a precedência de um operador
int Precedence(char op) {
    switch (op) {
        case '+': case '-': return 1; // Menor precedência
        case '*': case '/': return 2; // Precedência média
        case '^': return 3;           // Maior precedência
        default: return 0;            // Para caracteres que não são operadores
    }
}

// Função para verificar se o operador é associativo à direita (somente o operador '^')
int IsRightAssociative(char op) {
    return op == '^';  // O operador '^' é associativo à direita
}

// Função principal para converter expressão infixa para posfixa
void FtoP(char *Eq) {
    No head;       // Cabeça da pilha (inicialmente vazia)
    head.next = NULL; // A pilha começa vazia
    int k = 0;     // Índice para armazenar a string resultante (posfixa)
    char result[301] = {0}; // Array para armazenar o resultado da conversão

    // Loop para percorrer cada caractere da expressão infixa
    for (int i = 0; Eq[i] != '\0'; i++) {
        char c = Eq[i];  // Caractere atual da expressão

        if (isalnum(c)) {  // Se o caractere for um operando (número ou letra)
            result[k++] = c;  // Coloca o operando diretamente no resultado
        } else if (c == '(') {  // Se for um parêntese de abertura, empilha
            Push(c, &head);
        } else if (c == ')') {  // Se for um parêntese de fechamento
            // Desempilha até encontrar o parêntese de abertura
            while (head.next && Peek(&head) != '(') {
                result[k++] = Pop(&head); // Coloca os operadores no resultado
            }
            Pop(&head); // Remove o parêntese de abertura '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Se for um operador, desempilha operadores com maior ou igual precedência
            // E coloca no resultado até encontrar um operador com menor precedência ou parênteses
            while (head.next && 
                   Precedence(Peek(&head)) >= Precedence(c) &&
                   (!IsRightAssociative(c) || Precedence(Peek(&head)) > Precedence(c))) {
                result[k++] = Pop(&head); // Coloca no resultado os operadores desempilhados
            }
            Push(c, &head); // Empilha o operador atual
        }
    }

    // Esvazia a pilha, colocando os operadores restantes no resultado
    while (head.next) {
        result[k++] = Pop(&head); // Coloca os operadores restantes no resultado
    }

    printf("%s\n", result); // Imprime a expressão na notação posfixa
}

// Função principal
int main() {
    int N;                  // Número de expressões a serem processadas
    char Eq[301];           // Array para armazenar cada expressão infixa

    // Lê o número de expressões
    scanf("%d", &N);
    getchar();  // Consome o caractere de nova linha após o número

    // Loop para ler e converter cada expressão infixa
    for (int i = 0; i < N; i++) {
        fgets(Eq, sizeof(Eq), stdin);  // Lê a expressão infixa
        Eq[strcspn(Eq, "\n")] = '\0';  // Remove o '\n' no final da string (caso tenha sido lido pelo fgets)
        FtoP(Eq);  // Converte para notação posfixa e imprime
    }

    return 0;
}
