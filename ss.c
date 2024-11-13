#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da fila
typedef struct Fila {
    int Per;
    struct Fila *seg;
} Fila;

// Função para adicionar um elemento à fila
void Push(Fila **p, int x) {
    Fila *new = malloc(sizeof(Fila));  // Aloca memória para um novo nó
    if (new == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    new->Per = x;                      // Define o valor do novo nó
    new->seg = *p;                     // Faz o novo nó apontar para o antigo primeiro nó
    *p = new;                          // Atualiza a cabeça da lista para o novo nó
}

// Função para remover um elemento da fila
void RemoveePop(Fila **p, int x) {
    Fila *temp = *p, *prev = NULL;

    // Se a cabeça da lista contiver o valor a ser removido
    while (temp != NULL && temp->Per == x) {
        *p = temp->seg;  // Muda a cabeça
        free(temp);      // Libera a memória antiga da cabeça
        temp = *p;       // Atualiza o ponteiro temporário
    }

    // Procura o nó a ser removido
    while (temp != NULL) {
        while (temp != NULL && temp->Per != x) {
            prev = temp;
            temp = temp->seg;
        }

        // Se o valor não estiver presente
        if (temp == NULL) return;

        // Remove o nó
        prev->seg = temp->seg;
        free(temp);  // Libera a memória do nó
        temp = prev->seg; // Atualiza o ponteiro temporário
    }
}

// Função para imprimir a fila
void PrintFila(Fila *p) {
    while (p != NULL) {
        printf("%d ", p->Per);
        p = p->seg;
    }
    printf("\n");
}

int main() {
    Fila *fila = NULL;
    int N, M;
    
    // Lê a quantidade de elementos na fila inicial
    scanf("%d", &N);
    getchar();  // Consome o newline após o número de elementos
    
    // Lê os elementos da fila inicial
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        Push(&fila, temp);
    }
    
    // Lê a quantidade de elementos a serem removidos
    scanf("%d", &M);
    getchar();  // Consome o newline após o número de elementos a serem removidos
    
    // Lê os elementos a serem removidos
    for (int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);
        RemoveePop(&fila, temp);
    }
    
    // Imprime a fila resultante
    PrintFila(fila);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct No {
    int id;
    struct No *prox;
} No;

// Função para adicionar um elemento ao final da lista
void adicionar(No **cabeca, int id) {
    No *novo = (No *)malloc(sizeof(No));
    novo->id = id;
    novo->prox = NULL;
    
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        No *temp = *cabeca;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

// Função para remover um elemento da lista
void remover(No **cabeca, int id) {
    No *temp = *cabeca, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        *cabeca = temp->prox;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->prox;
    }

    if (temp == NULL) return;

    prev->prox = temp->prox;
    free(temp);
}

// Função para imprimir a lista
void imprimir(No *cabeca) {
    No *temp = cabeca;
    while (temp != NULL) {
        printf("%d ", temp->id);
        temp = temp->prox;
    }
    printf("\n");
}

// Função principal
int main() {
    int N, M;
    
    // Leitura do número de pessoas inicialmente na fila
    scanf("%d", &N);
    
    No *fila = NULL;

    // Leitura dos identificadores das pessoas na fila
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        adicionar(&fila, id);
    }
    
    // Leitura do número de pessoas que deixaram a fila
    scanf("%d", &M);

    // Leitura dos identificadores das pessoas que deixaram a fila
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        remover(&fila, id);
    }
    
    // Imprime o estado final da fila
    imprimir(fila);
    
    // Libera a memória alocada
    No *temp;
    while (fila != NULL) {
        temp = fila;
        fila = fila->prox;
        free(temp);
    }
    
    return 0;
}

//como funciona as listas com e sem cabeça?
//nova = (celula *) malloc (sizeof(celula))
//(celula *) pra que serve isso?
