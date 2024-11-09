#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função de comparação para usar com qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // Consumir o newline após o número de casos de teste

    char list[1001];
    for (int i = 0; i < N; i++) {
        // fgets lê até o \n, então naturalmente irá separar as listas
        fgets(list, sizeof(list), stdin);
        list[strcspn(list, "\n")] = '\0';  // Remover o newline do final da linha

        // Processamento da lista de compras
        char *items[1000];
        int count = 0;
        // strtok é uma função que divide uma string em tokens usando delimitadores
        // e vai dividir a lista de compras em itens separados enquanto apaga o array original
        // tudo isso usando um while
        char *token = strtok(list, " ");

        // Dividir a lista de compras em itens
        while (token != NULL) {
            items[count++] = token;
            token = strtok(NULL, " ");
        }

        // Ordenar os itens
        qsort(items, count, sizeof(char *), compare);

        // Imprimir itens únicos e ordenados
        for (int j = 0; j < count; j++) {
            if (j == 0 || strcmp(items[j], items[j - 1]) != 0) {
                if (j != 0) {
                    printf(" ");
                }
                printf("%s", items[j]);
            }
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição do nó da lista encadeada
typedef struct Node {
    char item[21];   // Para armazenar o item (máximo de 20 caracteres + '\0')
    struct Node *next; // Ponteiro para o próximo nó
} Node;

// Função para comparar duas strings (semelhante ao strcmp)
int compare_strings(const char *a, const char *b) {
    return strcmp(a, b);
}

// Função para verificar se o item já existe na lista encadeada
int exists_in_list(Node *head, const char *item) {
    Node *current = head;
    while (current != NULL) {
        if (compare_strings(current->item, item) == 0) {
            return 1;  // O item já existe
        }
        current = current->next;
    }
    return 0;  // O item não existe
}

// Função para inserir um item na lista encadeada em ordem alfabética
void insert_sorted(Node **head, const char *item) {
    // Verificar se o item já existe na lista
    if (exists_in_list(*head, item)) {
        return;  // Não inserir duplicatas
    }

    // Criar um novo nó
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->item, item);
    new_node->next = NULL;

    // Inserir o novo nó em ordem alfabética
    if (*head == NULL || compare_strings((*head)->item, item) > 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node *current = *head;
        // Percorrer a lista até encontrar o local correto para o item
        while (current->next != NULL && compare_strings(current->next->item, item) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Função para imprimir a lista encadeada
void print_list(Node *head) {
    Node *current = head;
    int first = 1;

    while (current != NULL) {
        if (!first) {
            printf(" ");
        }
        printf("%s", current->item);
        first = 0;
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória da lista encadeada
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // Consumir o newline após o número de casos de teste

    for (int i = 0; i < N; i++) {
        char list[1001];
        fgets(list, sizeof(list), stdin);
        list[strcspn(list, "\n")] = '\0';  // Remover o newline do final da linha

        Node *head = NULL;

        // Tokenizar a lista de compras
        char *token = strtok(list, " ");
        while (token != NULL) {
            insert_sorted(&head, token);
            token = strtok(NULL, " ");
        }

        // Imprimir a lista ordenada sem duplicatas
        print_list(head);

        // Liberar a memória da lista encadeada
        free_list(head);
    }

    return 0;
}

//Esses códigos não foram aceitos no beecrowd e não consegui solucionar o problema 