1068
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a pilha
typedef struct Pilha {
    int topo;
    unsigned capacidade;
    char* array;
} Pilha;

// Função para criar a pilha com uma capacidade dada
Pilha* criarPilha(unsigned capacidade) {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->array = (char*) malloc(pilha->capacidade * sizeof(char));
    return pilha;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

// Função para adicionar um item à pilha
void push(Pilha* pilha, char item) {
    pilha->array[++pilha->topo] = item;
}

// Função para remover um item da pilha
char pop(Pilha* pilha) {
    if (estaVazia(pilha))
        return '\0';
    return pilha->array[pilha->topo--];
}

// Função para verificar a correção dos parênteses
char* verificarParenteses(char* s) {
    int n = strlen(s);
    Pilha* pilha = criarPilha(n);

    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case ')':
                if (estaVazia(pilha) || pop(pilha) != '(') {
                    free(pilha->array);
                    free(pilha);
                    return "incorrect";
                }
                break;

            case '}':
                if (estaVazia(pilha) || pop(pilha) != '{') {
                    free(pilha->array);
                    free(pilha);
                    return "incorrect";
                }
                break;

            case ']':
                if (estaVazia(pilha) || pop(pilha) != '[') {
                    free(pilha->array);
                    free(pilha);
                    return "incorrect";
                }
                break;

            case '(':
            case '{':
            case '[':
                push(pilha, s[i]);
                break;
        }
    }

    char* resultado = estaVazia(pilha) ? "correct" : "incorrect";
    free(pilha->array);
    free(pilha);
    return resultado;
}

int main() {
    int N;
    
    // Leitura do número de expressões
    scanf("%d", &N);
    getchar();  // Consome o newline após o número de expressões
    
    for (int i = 0; i < N; i++) {
        char expressao[1001];
        fgets(expressao, sizeof(expressao), stdin);
        expressao[strcspn(expressao, "\n")] = '\0';  // Remove o newline do final da string
        
        printf("%s\n", verificarParenteses(expressao));
    }
    
    return 0;
}
