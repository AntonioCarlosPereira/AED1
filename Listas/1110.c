#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó (No) que vai representar cada carta na fila
typedef struct no {
    int valor;      // O valor da carta
    struct no *next;  // Ponteiro para o próximo nó na fila
} No;

// Definição da estrutura FILA que irá armazenar o ponteiro para o início (front) e o final (last) da fila
typedef struct FILA {
    No *front;   // Ponteiro para a carta do topo (início) da fila
    No *last;    // Ponteiro para a carta da base (final) da fila
} FILA;

// Função para inicializar uma fila, definindo ambos os ponteiros front e last como NULL (fila vazia)
void InicioFila(FILA *p) {
    p->front = NULL;  // A fila está vazia, logo front é NULL
    p->last = NULL;   // A fila está vazia, logo last também é NULL
}

// Função para inserir uma nova carta no final da fila (push)
void PushF(FILA *q, int x) {
    // Aloca memória para o novo nó
    No *newNode = (No*) malloc(sizeof(No));
    if (newNode == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);  // Caso não consiga alocar memória, o programa termina
    }
    newNode->valor = x;  // Atribui o valor da carta ao novo nó
    newNode->next = NULL; // O próximo nó será NULL, pois será o último da fila

    if (q->last == NULL) {  // Se a fila está vazia (last é NULL)
        q->front = newNode;  // O primeiro nó (front) é o novo nó
        q->last = newNode;   // O último nó (last) também é o novo nó
    } else {  // Se a fila não está vazia
        q->last->next = newNode;  // O antigo último nó aponta para o novo nó
        q->last = newNode;        // Atualiza o ponteiro last para o novo nó
    }
}

// Função para remover (descarte) a carta do topo da fila (pop)
int PopF(FILA *q) {
    if (q->front == NULL) {  // Se a fila estiver vazia
        printf("Fila vazia\n");
        return -1;  // Retorna um valor de erro
    }
    
    No *temp = q->front;  // Salva o ponteiro para o nó do topo
    int value = temp->valor;  // Armazena o valor da carta a ser descartada
    q->front = q->front->next;  // Move o ponteiro front para o próximo nó

    if (q->front == NULL) {  // Se a fila ficou vazia após a remoção
        q->last = NULL;  // O ponteiro last também deve ser NULL
    }

    free(temp);  // Libera a memória do nó removido
    return value;  // Retorna o valor da carta descartada
}

int main() {
    int n;
    scanf("%d", &n);  // Lê o número de cartas a serem manipuladas (n)

    FILA cartas;  // Cria uma variável do tipo FILA para armazenar as cartas
    InicioFila(&cartas);  // Inicializa a fila (setando front e last como NULL)

    // Inserir as cartas numeradas de 1 até n na fila
    for (int i = 1; i <= n; i++) {
        PushF(&cartas, i);  // Insere cada carta na fila
    }

    // Impressão das cartas descartadas
    printf("Discarded cards: ");
    int first = 1;  // Variável para controlar a formatação da saída (se a vírgula será colocada ou não)

    // Enquanto houver mais de uma carta na fila
    while (cartas.front != cartas.last) {  
        if (first) {
            // Se for o primeiro valor, não coloca vírgula antes
            printf("%d", PopF(&cartas));  // Descartar a carta do topo (pop)
            first = 0;  // A partir daqui, colocaremos vírgulas
        } else {
            // Para as próximas cartas descartadas, colocamos uma vírgula antes do número
            printf(", %d", PopF(&cartas));  // Descartar a carta do topo (pop)
        }
        
        // Mover a carta do topo para a base da fila
        PushF(&cartas, PopF(&cartas));  // Descartar e em seguida mover para a base
    }

    // Após o loop, a última carta remanescente será a carta no topo da fila (front)
    printf("\nRemaining card: %d\n", cartas.front->valor);  // Imprime a carta remanescente

    return 0;
}
