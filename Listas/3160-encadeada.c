#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para a lista encadeada
typedef struct Amigo {
    char nome[21];
    struct Amigo *proximo;
} Amigo;

// Função para criar um novo nó de amigo
Amigo* criarAmigo(char *nome) {
    Amigo *novoAmigo = (Amigo*)malloc(sizeof(Amigo));
    strcpy(novoAmigo->nome, nome);
    novoAmigo->proximo = NULL;
    return novoAmigo;
}

// Função para inserir um novo amigo na lista
void inserirAmigo(Amigo **cabeca, char *nome) {
    Amigo *novoAmigo = criarAmigo(nome);
    if (*cabeca == NULL) {
        *cabeca = novoAmigo;
    } else {
        Amigo *temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoAmigo;
    }
}

// Função para imprimir a lista de amigos
void imprimirLista(Amigo *cabeca) {
    Amigo *temp = cabeca;
    while (temp != NULL) {
        printf("%s", temp->nome);
        if (temp->proximo != NULL) {
            printf(" ");
        }
        temp = temp->proximo;
    }
    printf("\n");
}

// Função para inserir novos amigos na posição correta
void inserirNovosAmigos(Amigo **cabeca, char *novosAmigos, char *indicacao) {
    Amigo *temp = *cabeca;
    Amigo *anterior = NULL;

    // Encontrar a posição de indicação, se houver
    while (temp != NULL && strcmp(temp->nome, indicacao) != 0) {
        anterior = temp;
        temp = temp->proximo;
    }

    // Processar novos amigos
    char *token = strtok(novosAmigos, " ");
    while (token != NULL) {
        Amigo *novoAmigo = criarAmigo(token);
        if (indicacao == NULL || strcmp(indicacao, "nao") == 0) {
            // Adicionar novos amigos no final
            inserirAmigo(cabeca, token);
        } else if (anterior == NULL) {
            // Inserir no início se a indicação estiver na cabeça
            novoAmigo->proximo = *cabeca;
            *cabeca = novoAmigo;
        } else {
            // Inserir no meio da lista
            novoAmigo->proximo = temp;
            anterior->proximo = novoAmigo;
            anterior = novoAmigo;
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char linha1[1001], linha2[1001], indicacao[21];
    Amigo *lista = NULL;

    // Leitura das linhas de entrada
    fgets(linha1, sizeof(linha1), stdin);
    fgets(linha2, sizeof(linha2), stdin);
    fgets(indicacao, sizeof(indicacao), stdin);
    linha1[strcspn(linha1, "\n")] = '\0';
    linha2[strcspn(linha2, "\n")] = '\0';
    indicacao[strcspn(indicacao, "\n")] = '\0';

    // Processar a lista atual de amigos
    char *token = strtok(linha1, " ");
    while (token != NULL) {
        inserirAmigo(&lista, token);
        token = strtok(NULL, " ");
    }

    // Inserir novos amigos na posição correta
    inserirNovosAmigos(&lista, linha2, indicacao);

    // Imprimir a lista final de amigos
    imprimirLista(lista);

    // Liberação da memória alocada
    Amigo *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}
