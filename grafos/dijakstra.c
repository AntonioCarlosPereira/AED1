#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int V, valor;
} node;

typedef struct {
    node elementos[260];
    int tamanho;
} minHeap;

void pushHeap(minHeap *heap, int V, int valor) {
    node novo = {V, valor};
    heap->elementos[heap->tamanho] = novo;
    int i = heap->tamanho;
    heap->tamanho++;

    while (i > 0 && heap->elementos[i].valor < heap->elementos[(i - 1) / 2].valor) {
        node aux = heap->elementos[i];
        heap->elementos[i] = heap->elementos[(i - 1) / 2];
        heap->elementos[(i - 1) / 2] = aux;
        i = (i - 1) / 2;
    }
}

node popHeap(minHeap *heap) {
    node raiz = heap->elementos[0];
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    int i = 0;

    while (2 * i + 1 < heap->tamanho) {
        int menor = 2 * i + 1;
        if (menor + 1 < heap->tamanho && heap->elementos[menor + 1].valor < heap->elementos[menor].valor) {
            menor++;
        }
        if (heap->elementos[i].valor <= heap->elementos[menor].valor) {
            break;
        }
        node aux = heap->elementos[i];
        heap->elementos[i] = heap->elementos[menor];
        heap->elementos[menor] = aux;
        i = menor;
    }

    return raiz;
}

int graf[260][260];
int visited[260];
int distMin[260];
int anterior[260];

void initGraf(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        distMin[i] = INT_MAX;
        anterior[i] = -1;

        for (int j = 0; j < n; j++) {
            graf[i][j] = -1;  // Inicializa sem arestas
        }
    }
}

void dijkstra(int n, int origem, int destino) {
    minHeap heap;
    heap.tamanho = 0;
    distMin[origem] = 0;

    pushHeap(&heap, origem, 0);

    while (heap.tamanho > 0) {
        node atual = popHeap(&heap);
        int u = atual.V;

        if (visited[u]) continue;
        visited[u] = 1;

        if (u == destino) break;

        for (int v = 0; v < n; v++) {
            if (graf[u][v] != -1) {
                int custo_v = distMin[u] + graf[u][v];

                if (distMin[v] > custo_v) {
                    distMin[v] = custo_v;
                    anterior[v] = u;
                    pushHeap(&heap, v, custo_v);
                }
            }
        }
    }
}

void minPath(int origem, int destino) {
    if (distMin[destino] == INT_MAX) {
        printf("Caminho inexistente\n");
        return;
    }

    int caminho[260];
    int atual = destino;
    int tam = 0;

    while (atual != -1) {
        caminho[tam++] = atual;
        atual = anterior[atual];
    }

    printf("Caminho mínimo de %d para %d: ", origem, destino);
    for (int i = tam - 1; i >= 0; i--) {
        printf("%d ", caminho[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Digite o número de vértices e arestas: ");
    scanf("%d %d", &n, &m);

    initGraf(n);

    printf("Digite as arestas no formato: origem destino peso\n");
    for (int i = 0; i < m; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        graf[u][v] = peso;
        graf[v][u] = peso;  // Grafo não direcionado
    }

    int origem, destino;
    printf("Digite o vértice de origem e destino: ");
    scanf("%d %d", &origem, &destino);

    dijkstra(n, origem, destino);
    minPath(origem, destino);

    return 0;
}




