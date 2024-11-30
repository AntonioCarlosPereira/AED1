#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para a lista encadeada
// A estrutura Amigo contém o nome do amigo e um ponteiro para o próximo amigo da lista.
typedef struct Amigo {
    char nome[21];         // Nome do amigo (máximo de 20 caracteres + '\0')
    struct Amigo *proximo; // Ponteiro para o próximo amigo na lista
} Amigo;

// Função para criar um novo nó de amigo
// Aloca memória para um novo nó de amigo, preenche seu nome e inicializa o ponteiro para o próximo amigo como NULL.
Amigo* criarAmigo(char *nome) {
    Amigo *novoAmigo = (Amigo*)malloc(sizeof(Amigo)); // Aloca memória para um novo amigo
    strcpy(novoAmigo->nome, nome); // Copia o nome do amigo para o novo nó
    novoAmigo->proximo = NULL; // Inicializa o ponteiro "proximo" como NULL
    return novoAmigo; // Retorna o novo nó
}

// Função para inserir um novo amigo na lista
// Insere o amigo no final da lista encadeada.
void inserirAmigo(Amigo **cabeca, char *nome) {
    Amigo *novoAmigo = criarAmigo(nome); // Cria o novo amigo com o nome dado
    if (*cabeca == NULL) {
        *cabeca = novoAmigo; // Se a lista estiver vazia, o novo amigo se torna a cabeça da lista
    } else {
        Amigo *temp = *cabeca;
        // Percorre a lista até o último nó
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        // Aponta o último nó para o novo amigo
        temp->proximo = novoAmigo;
    }
}

// Função para imprimir a lista de amigos
// Imprime os nomes dos amigos na lista, separados por espaços.
void imprimirLista(Amigo *cabeca) {
    Amigo *temp = cabeca; // Ponteiro para percorrer a lista
    while (temp != NULL) {
        printf("%s", temp->nome); // Imprime o nome do amigo atual
        if (temp->proximo != NULL) {
            printf(" "); // Imprime um espaço entre os nomes, se não for o último amigo
        }
        temp = temp->proximo; // Avança para o próximo amigo
    }
    printf("\n"); // Imprime uma nova linha ao final da lista
}

// Função para inserir novos amigos na posição correta
// A inserção ocorre no final, início ou no meio da lista, dependendo da indicação fornecida.
void inserirNovosAmigos(Amigo **cabeca, char *novosAmigos, char *indicacao) {
    Amigo *temp = *cabeca; // Ponteiro para percorrer a lista
    Amigo *anterior = NULL; // Ponteiro para o nó anterior ao nó atual, usado para inserção no meio

    // Encontrar a posição de indicação, se houver
    while (temp != NULL && strcmp(temp->nome, indicacao) != 0) {
        anterior = temp; // Avança o ponteiro anterior para o amigo atual
        temp = temp->proximo; // Avança o ponteiro para o próximo amigo
    }

    // Processar novos amigos (divididos por espaços na string)
    char *token = strtok(novosAmigos, " ");
    while (token != NULL) {
        Amigo *novoAmigo = criarAmigo(token); // Cria um novo amigo com o nome extraído

        if (indicacao == NULL || strcmp(indicacao, "nao") == 0) {
            // Se a indicação for NULL ou "nao", insere os novos amigos no final da lista
            inserirAmigo(cabeca, token);
        } else if (anterior == NULL) {
            // Se a indicação for no início da lista (não encontrado ainda), insere no começo
            novoAmigo->proximo = *cabeca; // O novo amigo aponta para o início da lista
            *cabeca = novoAmigo; // O novo amigo se torna a cabeça da lista
        } else {
            // Se a indicação for no meio da lista, insere após o amigo indicado
            novoAmigo->proximo = temp; // O novo amigo aponta para o amigo atual
            anterior->proximo = novoAmigo; // O amigo anterior agora aponta para o novo amigo
            anterior = novoAmigo; // Atualiza o ponteiro anterior para o novo amigo
        }

        token = strtok(NULL, " "); // Continua extraindo os próximos amigos
    }
}

int main() {
    char linha1[1001], linha2[1001], indicacao[21];
    Amigo *lista = NULL; // Inicializa a lista de amigos como NULL (vazia)

    // Leitura das linhas de entrada
    fgets(linha1, sizeof(linha1), stdin); // Lê a primeira linha de amigos
    fgets(linha2, sizeof(linha2), stdin); // Lê a segunda linha de novos amigos
    fgets(indicacao, sizeof(indicacao), stdin); // Lê a indicação de onde inserir os novos amigos

    // Remove o caractere de nova linha '\n' do final das strings
    linha1[strcspn(linha1, "\n")] = '\0';
    linha2[strcspn(linha2, "\n")] = '\0';
    indicacao[strcspn(indicacao, "\n")] = '\0';

    // Processa a lista inicial de amigos (linha1) e insere cada amigo na lista encadeada
    char *token = strtok(linha1, " ");
    while (token != NULL) {
        inserirAmigo(&lista, token); // Insere o amigo na lista
        token = strtok(NULL, " "); // Continua extraindo os próximos amigos
    }

    // Insere os novos amigos (linha2) na posição indicada (indicacao)
    inserirNovosAmigos(&lista, linha2, indicacao);

    // Imprime a lista final de amigos
    imprimirLista(lista);

    // Liberação da memória alocada para a lista de amigos
    Amigo *temp;
    while (lista != NULL) {
        temp = lista; // Armazena o nó atual
        lista = lista->proximo; // Avança para o próximo nó
        free(temp); // Libera a memória do nó atual
    }

    return 0; // Retorna 0, indicando que o programa foi executado com sucesso
}
