1068
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar a pilha
typedef struct Pilha {
    int topo;             // Índice do elemento no topo da pilha
    unsigned capacidade;  // Capacidade máxima da pilha
    char* array;          // Array dinâmico que armazena os elementos da pilha
} Pilha;

// Função para criar a pilha com uma capacidade dada
Pilha* criarPilha(unsigned capacidade) {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    // Aloca memória para a estrutura Pilha

    pilha->capacidade = capacidade;      // Define a capacidade da pilha
    pilha->topo = -1;                    // Inicializa o topo como -1 (pilha vazia)
    pilha->array = (char*) malloc(pilha->capacidade * sizeof(char));
    // Aloca memória para o array da pilha com a capacidade necessária

    return pilha;  // Retorna o ponteiro para a pilha criada
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;  // Retorna 1 (verdadeiro) se o topo for -1, indicando que está vazia
}

// Função para adicionar um item à pilha
void push(Pilha* pilha, char item) {
    pilha->array[++pilha->topo] = item;
    // Incrementa o índice do topo e armazena o item no novo topo
}

// Função para remover um item da pilha
char pop(Pilha* pilha) {
    if (estaVazia(pilha))       // Verifica se a pilha está vazia antes de remover
        return '\0';           // Retorna '\0' como valor inválido
    return pilha->array[pilha->topo--];
    // Retorna o item do topo e decrementa o índice do topo
}

// Função para verificar a correção dos parênteses
char* verificarParenteses(char* s) {
    int n = strlen(s);              // Calcula o comprimento da string
    Pilha* pilha = criarPilha(n);   // Cria uma pilha com capacidade igual ao tamanho da string

    // Percorre a string caracter por caracter
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case ')':  // Caso seja um parêntese de fechamento
                if (estaVazia(pilha) || pop(pilha) != '(') {
                    // Se a pilha estiver vazia ou o topo não for o parêntese correspondente
                    free(pilha->array);  // Libera a memória do array
                    free(pilha);         // Libera a memória da pilha
                    return "incorrect";  // Retorna "incorrect"
                }
                break;

            case '}':  // Caso seja uma chave de fechamento
                if (estaVazia(pilha) || pop(pilha) != '{') {
                    free(pilha->array);
                    free(pilha);
                    return "incorrect";
                }
                break;

            case ']':  // Caso seja um colchete de fechamento
                if (estaVazia(pilha) || pop(pilha) != '[') {
                    free(pilha->array);
                    free(pilha);
                    return "incorrect";
                }
                break;

            case '(':
                push(pilha, s[i]);  // Adiciona o caractere à pilha
                break;
            case '{':
                push(pilha, s[i]);  // Adiciona o caractere à pilha
                break;
            case '[':  // Caso seja um parêntese, chave ou colchete de abertura
                push(pilha, s[i]);  // Adiciona o caractere à pilha
                break;
        }
    }

    // Após percorrer a string, verifica se a pilha está vazia
    char* resultado = estaVazia(pilha) ? "correct" : "incorrect";

    // Libera a memória da pilha
    free(pilha->array);
    free(pilha);

    return resultado;  // Retorna o resultado final
}

// Função principal
int main() {
    int N;

    // Leitura do número de expressões a serem verificadas
    scanf("%d", &N);
    getchar();  // Consome o caractere de nova linha após o número

    // Loop para processar cada expressão
    for (int i = 0; i < N; i++) {
        char expressao[1001];  // Buffer para armazenar a expressão
        fgets(expressao, sizeof(expressao), stdin);
        // Lê a expressão (máximo de 1000 caracteres) incluindo o '\n'

        expressao[strcspn(expressao, "\n")] = '\0';
        // Remove o '\n' ao final da string, substituindo por '\0'

        printf("%s\n", verificarParenteses(expressao));
        // Chama a função de verificação e imprime o resultado
    }

    return 0;  // Retorna 0 indicando que o programa terminou com sucesso
}
