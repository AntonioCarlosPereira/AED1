#include <stdio.h>   // Inclusão da biblioteca para funções de entrada e saída padrão (como printf, scanf).
#include <string.h>  // Inclusão da biblioteca para manipulação de strings (como strlen, strcmp, strtok).
#include <stdlib.h>  // Inclusão da biblioteca para funções de alocação de memória e outros utilitários (como qsort).

// Função de comparação para usar com qsort
// A função 'compare' é passada para a função qsort para ordenar as strings em ordem alfabética.
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);  // Compara duas strings lexicograficamente.
}

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de casos de teste (quantas listas de compras o programa deve processar).
    getchar();  // Consome o caractere de nova linha '\n' deixado pelo scanf, para não interferir na leitura subsequente.

    char list[1001];  // Array para armazenar a lista de compras (suporta até 1000 caracteres na lista).
    for (int i = 0; i < N; i++) {  // Loop para processar cada caso de teste.
        // fgets lê até o \n (nova linha), então naturalmente irá separar as listas por espaços
        fgets(list, sizeof(list), stdin);  // Lê a linha de entrada com a lista de compras.
        list[strcspn(list, "\n")] = '\0';  // Remove o newline '\n' do final da string lida, causador pelo fgets.

        // Processamento da lista de compras
        char *items[1000];  // Array de ponteiros para armazenar os itens separados da lista.
        int count = 0;  // Contador de itens na lista de compras.
        
        // strtok é uma função que divide uma string em tokens, usando delimitadores (neste caso, espaços).
        // Ela modifica a string original dividindo-a em substrings e retorna cada uma dessas substrings.
        char *token = strtok(list, " ");  // A primeira chamada ao strtok divide a string na primeira palavra.

        // Dividir a lista de compras em itens, um item por vez.
        while (token != NULL) {  // Enquanto houver tokens (itens).
            items[count++] = token;  // Armazena o item no array 'items'.
            token = strtok(NULL, " ");  // Obtém o próximo token da string.
        }

        // Ordenar os itens lexicograficamente (ordem alfabética) usando a função qsort.
        qsort(items, count, sizeof(char *), compare);  // Ordena os itens de acordo com a função 'compare'.

        // Imprimir os itens únicos e ordenados na mesma linha.
        for (int j = 0; j < count; j++) {  // Para cada item na lista ordenada.
            // Verifica se o item atual é diferente do anterior (evita imprimir duplicatas).
            if (j == 0 || strcmp(items[j], items[j - 1]) != 0) {
                if (j != 0) {  // Se não for o primeiro item, imprime um espaço antes do item.
                    printf(" ");
                }
                printf("%s", items[j]);  // Imprime o item na tela.
            }
        }
        printf("\n");  // Imprime uma nova linha após os itens do caso de teste atual.
    }

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso.
}







#include <stdio.h>   // Inclusão da biblioteca para funções de entrada e saída padrão (como printf, scanf).
#include <string.h>  // Inclusão da biblioteca para manipulação de strings (como strcpy, strcmp, strtok).
#include <stdlib.h>  // Inclusão da biblioteca para funções de alocação de memória e outros utilitários (como malloc, free).

// Definição do nó da lista encadeada
// Cada nó da lista armazenará um item (máximo de 20 caracteres + '\0') e um ponteiro para o próximo nó.
typedef struct Node {
    char item[21];    // Array de caracteres para armazenar o item da lista (máximo 20 caracteres + '\0').
    struct Node *next; // Ponteiro para o próximo nó na lista encadeada.
} Node;

// Função para comparar duas strings (semelhante ao strcmp).
// A função retorna um valor negativo, zero ou positivo dependendo da comparação das duas strings.
int compare_strings(const char *a, const char *b) {
    return strcmp(a, b);  // Usa a função strcmp para comparar as duas strings.
}

// Função para verificar se o item já existe na lista encadeada.
int exists_in_list(Node *head, const char *item) {
    Node *current = head;  // Ponteiro que percorre a lista encadeada.
    
    // Percorre a lista encadeada até encontrar o item ou chegar ao final.
    while (current != NULL) {
        // Compara o item atual da lista com o item desejado.
        if (compare_strings(current->item, item) == 0) {
            return 1;  // Se o item já existe, retorna 1.
        }
        current = current->next;  // Avança para o próximo nó da lista.
    }
    
    return 0;  // Retorna 0 se o item não foi encontrado na lista.
}

// Função para inserir um item na lista encadeada em ordem alfabética.
// A inserção ocorre apenas se o item não existir na lista (sem duplicatas).
void insert_sorted(Node **head, const char *item) {
    // Verifica se o item já existe na lista antes de inserir.
    if (exists_in_list(*head, item)) {
        return;  // Se o item já existir, a função retorna sem inserir.
    }

    // Criação de um novo nó para armazenar o item.
    Node *new_node = (Node *)malloc(sizeof(Node));  // Aloca memória para o novo nó.
    strcpy(new_node->item, item);  // Copia o item para o novo nó.
    new_node->next = NULL;  // Inicializa o ponteiro 'next' como NULL, indicando o final da lista.

    // Se a lista estiver vazia ou o item a ser inserido for menor que o primeiro da lista, insere no início.
    if (*head == NULL || compare_strings((*head)->item, item) > 0) {
        new_node->next = *head;  // O novo nó aponta para o primeiro nó da lista.
        *head = new_node;  // O novo nó torna-se o primeiro nó da lista.
    } else {
        Node *current = *head;
        
        // Percorre a lista até encontrar o local correto para o item.
        while (current->next != NULL && compare_strings(current->next->item, item) < 0) {
            current = current->next;  // Avança para o próximo nó na lista.
        }
        
        // Insere o novo nó após o nó encontrado.
        new_node->next = current->next;  // O novo nó aponta para o próximo nó.
        current->next = new_node;  // O nó atual aponta para o novo nó.
    }
}

// Função para imprimir a lista encadeada.
void print_list(Node *head) {
    Node *current = head;  // Ponteiro para percorrer a lista encadeada.
    int first = 1;  // Variável para controlar a impressão dos espaços entre os itens.

    // Percorre a lista e imprime os itens.
    while (current != NULL) {
        // Imprime um espaço entre os itens, exceto antes do primeiro item.
        if (!first) {
            printf(" ");
        }
        printf("%s", current->item);  // Imprime o item do nó atual.
        first = 0;  // Após o primeiro item, a variável 'first' será 0, para imprimir o espaço.
        current = current->next;  // Avança para o próximo nó.
    }
    printf("\n");  // Imprime uma nova linha após a lista ser completamente impressa.
}

// Função para liberar a memória alocada para a lista encadeada.
void free_list(Node *head) {
    Node *current = head;  // Ponteiro para percorrer a lista.

    // Libera cada nó da lista.
    while (current != NULL) {
        Node *temp = current;  // Armazena o nó atual em uma variável temporária.
        current = current->next;  // Avança para o próximo nó.
        free(temp);  // Libera a memória do nó armazenado na variável temporária.
    }
}

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de casos de teste (quantas listas de compras o programa deve processar).
    getchar();  // Consome o caractere de nova linha deixado pelo scanf, para não interferir na leitura subsequente.

    for (int i = 0; i < N; i++) {  // Loop para processar cada caso de teste.
        char list[1001];  // Array para armazenar a lista de compras (suporta até 1000 caracteres na lista).
        fgets(list, sizeof(list), stdin);  // Lê a linha com a lista de compras.
        list[strcspn(list, "\n")] = '\0';  // Remove o newline '\n' no final da string lida.

        Node *head = NULL;  // Inicializa a lista encadeada como vazia (head é NULL).

        // Tokeniza a lista de compras, separando-a pelos espaços.
        char *token = strtok(list, " ");
        while (token != NULL) {
            insert_sorted(&head, token);  // Insere cada item na lista encadeada, mantendo a ordem alfabética.
            token = strtok(NULL, " ");  // Obtém o próximo token (item) da lista.
        }

        // Imprime a lista ordenada e sem duplicatas.
        print_list(head);

        // Libera a memória da lista encadeada.
        free_list(head);
    }

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso.
}

//Esses códigos não foram aceitos no beecrowd e não consegui solucionar o problema 