#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para inserir novos amigos na posição correta na lista existente
// A função toma a lista atual de amigos, o número de amigos na lista, 
// a lista de novos amigos a serem inseridos, e a indicação de onde inserir os novos amigos.
void inserirAmigos(char **lista, int *count, char *novosAmigos, char *indicacao) {
    char *token = strtok(novosAmigos, " "); // Dividir a lista de novos amigos em palavras
    char *amigos[100]; // Array para armazenar os novos amigos
    int countNovos = 0; // Contador para o número de novos amigos
    
    // Processar cada novo amigo e armazená-lo no array 'amigos'
    while (token != NULL) {
        amigos[countNovos++] = token; // Armazenar cada amigo na lista 'amigos'
        token = strtok(NULL, " "); // Continuar extraindo os tokens (nomes dos amigos)
    }

    // Se a indicação for "nao", adicionar os novos amigos ao final da lista
    if (strcmp(indicacao, "nao") == 0) {
        // Inserir os novos amigos no final da lista
        for (int i = 0; i < countNovos; i++) {
            lista[*count + i] = amigos[i]; // Coloca os novos amigos no final
        }
        *count += countNovos; // Atualizar o contador de amigos na lista
    } else {
        // Se houver indicação, encontrar a posição do amigo indicado na lista
        int pos = 0;
        while (pos < *count && strcmp(lista[pos], indicacao) != 0) {
            pos++; // Buscar a posição do amigo indicado
        }
        
        // Mover os amigos existentes para abrir espaço para os novos amigos
        for (int i = *count - 1; i >= pos; i--) {
            lista[i + countNovos] = lista[i]; // Move os amigos para a direita
        }
        
        // Inserir os novos amigos na posição correta
        for (int i = 0; i < countNovos; i++) {
            lista[pos + i] = amigos[i]; // Coloca os novos amigos no lugar
        }
        *count += countNovos; // Atualizar o contador de amigos na lista
    }
}

int main() {
    char linha1[1001], linha2[1001], indicacao[21]; // Arrays para armazenar as entradas
    char *lista[1000]; // Array para armazenar a lista de amigos
    int count = 0; // Contador para o número de amigos na lista

    // Leitura das linhas de entrada
    fgets(linha1, sizeof(linha1), stdin); // Lê a linha da lista atual de amigos
    fgets(linha2, sizeof(linha2), stdin); // Lê a linha dos novos amigos a serem inseridos
    fgets(indicacao, sizeof(indicacao), stdin); // Lê a linha de indicação (onde inserir os novos amigos)
    
    // Remover o newline no final de cada linha lida
    linha1[strcspn(linha1, "\n")] = '\0'; 
    linha2[strcspn(linha2, "\n")] = '\0';
    indicacao[strcspn(indicacao, "\n")] = '\0';

    // Processar a lista atual de amigos, dividindo-a em palavras
    char *token = strtok(linha1, " "); // Usar strtok para dividir a lista em tokens (nomes dos amigos)
    while (token != NULL) {
        lista[count++] = token; // Armazenar cada nome na lista
        token = strtok(NULL, " "); // Continuar extraindo os tokens (nomes dos amigos)
    }

    // Inserir os novos amigos na posição correta da lista
    inserirAmigos(lista, &count, linha2, indicacao);

    // Imprimir a lista final de amigos
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            printf(" "); // Imprimir um espaço entre os nomes
        }
        printf("%s", lista[i]); // Imprimir o nome do amigo
    }
    printf("\n");

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
