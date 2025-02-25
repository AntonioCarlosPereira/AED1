void atribuiPai(No* raiz, No* pai) {
    if (raiz == NULL) {
        return;
    }

    // O nó atual tem o ponteiro para o pai atribuído
    raiz->pai = pai;

    // Recursivamente, chama para os filhos
    atribuiPai(raiz->esq, raiz);  // O pai da esquerda será o nó atual
    atribuiPai(raiz->dir, raiz);  // O pai da direita será o nó atual
}

int** criarMatriz(int n) {
    int** matriz = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }
    
    return matriz;
}

#include <stdio.h>
#include <limits.h>

int menorCaminho(int graph[1000][1000], int V, int start, int end) {
    int dist[V], sptSet[V];

    // Inicializa as distâncias e o conjunto de vértices processados
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[start] = 0;  // A distância de 'start' até ele mesmo é 0

    // Loop principal do algoritmo
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;
        
        // Encontrar o vértice com a menor distância ainda não processado
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        sptSet[u] = 1;  // Marca o vértice como processado

        // Atualiza as distâncias dos vizinhos do vértice 'u'
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v]) {  // Verifica se há uma aresta
                if (dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];  // Atualiza a distância
                }
            }
        }
    }

    // Retorna a distância do vértice 'start' até o vértice 'end'
    return dist[end];
}

void push(int valor, heap *h) {
    if (h->tamanho >= maxsize) return; // Evita estouro da heap

    int i = h->tamanho;
    h->dado[i] = valor;
    h->tamanho++;

    // Subir o elemento até restaurar a propriedade de max-heap
    while (i > 0 && h->dado[i] > h->dado[(i - 1) / 2]) {
        int temp = h->dado[i];
        h->dado[i] = h->dado[(i - 1) / 2];
        h->dado[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int pop(heap *h) {
    if (h->tamanho == 0) return -1; // Retorna um valor inválido caso a heap esteja vazia

    int raiz = h->dado[0];
    h->dado[0] = h->dado[h->tamanho - 1];
    h->tamanho--;

    int i = 0;
    while (2 * i + 1 < h->tamanho) { // Enquanto houver filhos
        int E = 2 * i + 1;
        int D = 2 * i + 2;
        int maior = E;

        if (D < h->tamanho && h->dado[D] > h->dado[E]) {
            maior = D;
        }
        if (h->dado[i] >= h->dado[maior]) {
            break;
        }

        int temp = h->dado[i];
        h->dado[i] = h->dado[maior];
        h->dado[maior] = temp;
        i = maior;
    }

    return raiz;
}
