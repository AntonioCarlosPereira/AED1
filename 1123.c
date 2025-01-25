-montar o grafo
-armazenar as cidades participantes dessas rotas
-utilizar dijaksta para achar o menor caminho apartir do ponto de reparo 
-verificar se este caminho não passa pela rota

-----------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MAX

#define MAX_VERTICES 100  // Número máximo de vértices permitido

// Função para inicializar a matriz de adjacência
void inicializarGrafo(int grafo[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo[i][j] = 0;  // Inicializa todos os pesos com 0 (sem aresta)
        }
    }
}

// Função para adicionar uma aresta com peso
void adicionarAresta(int grafo[MAX_VERTICES][MAX_VERTICES], int origem, int destino, int peso) {
    grafo[origem][destino] = peso;  // Aresta de origem para destino
    grafo[destino][origem] = peso;  // Aresta de destino para origem (grafo não direcionado)
}

// Função para encontrar o vértice com menor distância
int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Função de Dijkstra com sequência
int dijkstraComSequencia(int grafo[MAX_VERTICES][MAX_VERTICES], int vertices, int start, int end) {
    int dist[vertices];   // Distâncias mínimas
    int visited[vertices]; // Vértices visitados
    int forced = 0;        // Flag para indicar quando forçamos a sequência

    // Inicializa as distâncias e os visitados
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Laço principal de Dijkstra
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);  // Escolhe o vértice com a menor distância
        visited[u] = 1;

        // Se o vértice u for menor que o destino e a sequência ainda não foi forçada
        if (u < end && !forced) {
            forced = 1;  // Ativa a sequência forçada

            // Segue a sequência numérica até o destino
            for (int v = u + 1; v <= end; v++) {
                if (grafo[u][v] && dist[u] != INT_MAX) {
                    dist[v] = dist[u] + grafo[u][v];  // Atualiza a distância
                    u = v;  // Move para o próximo vértice numericamente maior
                }
            }
        } else {
            // Atualiza as distâncias dos vizinhos de u normalmente
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                    dist[v] = dist[u] + grafo[u][v];
                }
            }
        }
    }

    return dist[end];  // Retorna a distância do vértice de origem até o destino
}

int main() {
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int vertices, arestas, rota, origem;

    // Leitura do número de vértices e arestas
    scanf("%d %d %d %d", &vertices, &arestas, &rota, &origem);

    // Inicializa o grafo com o número de vértices
    inicializarGrafo(grafo, vertices);

    // Processamento das arestas
    for (int i = 0; i < arestas; i++) {
        int origemAresta, destino, peso;
        // Leitura de cada aresta
        scanf("%d %d %d", &origemAresta, &destino, &peso);

        // Verifica se os vértices fornecidos estão dentro do intervalo válido
        if (origemAresta >= 0 && origemAresta < vertices && destino >= 0 && destino < vertices) {
            // Adiciona a aresta ao grafo
            adicionarAresta(grafo, origemAresta, destino, peso);
        }
    }

    // Executa o algoritmo de Dijkstra e obtém o resultado
    int result = dijkstraComSequencia(grafo, vertices, origem, rota);

    // Imprime o resultado
    printf("%d\n", result);

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------
    #include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MAX

#define MAX_VERTICES 100  // Número máximo de vértices permitido

// Função para inicializar a matriz de adjacência
void inicializarGrafo(int grafo[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo[i][j] = 0;  // Inicializa todos os pesos com 0 (sem aresta)
        }
    }
}

// Função para adicionar uma aresta com peso
void adicionarAresta(int grafo[MAX_VERTICES][MAX_VERTICES], int origem, int destino, int peso) {
    grafo[origem][destino] = peso;  // Aresta de origem para destino
    grafo[destino][origem] = peso;  // Aresta de destino para origem (grafo não direcionado)
}

// Função para encontrar o vértice com menor distância
int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Função de Dijkstra com sequência
int dijkstraComSequencia(int grafo[MAX_VERTICES][MAX_VERTICES], int vertices, int start, int end) {
    int dist[vertices];   // Distâncias mínimas
    int visited[vertices]; // Vértices visitados
    int forced = 0;        // Flag para indicar quando forçamos a sequência

    // Inicializa as distâncias e os visitados
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Laço principal de Dijkstra
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);  // Escolhe o vértice com a menor distância
        visited[u] = 1;

        // Se o vértice u for menor que o destino e a sequência ainda não foi forçada
        if (u < end && !forced) {
            forced = 1;  // Ativa a sequência forçada

            // Segue a sequência numérica até o destino
            for (int v = u + 1; v <= end; v++) {
                if (grafo[u][v] && dist[u] != INT_MAX) {
                    dist[v] = dist[u] + grafo[u][v];  // Atualiza a distância
                    u = v;  // Move para o próximo vértice numericamente maior
                }
            }
        } else {
            // Atualiza as distâncias dos vizinhos de u normalmente
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                    dist[v] = dist[u] + grafo[u][v];
                }
            }
        }
    }

    return dist[end];  // Retorna a distância do vértice de origem até o destino
}

int main() {
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int vertices, arestas, rota, origem;

    // Leitura do número de vértices e arestas
    scanf("%d %d %d %d", &vertices, &arestas, &rota, &origem);

    // Inicializa o grafo com o número de vértices
    inicializarGrafo(grafo, vertices);

    // Processamento das arestas
    for (int i = 0; i < arestas; i++) {
        int origemAresta, destino, peso;
        // Leitura de cada aresta
        scanf("%d %d %d", &origemAresta, &destino, &peso);

        // Verifica se os vértices fornecidos estão dentro do intervalo válido
        if (origemAresta >= 0 && origemAresta < vertices && destino >= 0 && destino < vertices) {
            // Adiciona a aresta ao grafo
            adicionarAresta(grafo, origemAresta, destino, peso);
        }
    }

    // Executa o algoritmo de Dijkstra e obtém o resultado
    int result = dijkstraComSequencia(grafo, vertices, origem, rota);

    // Imprime o resultado
    printf("%d\n", result);

    return 0;
}
    ------------------------------------------------------------------------------------------------------------------

    #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 250
#define INF INT_MAX

typedef struct {
    int destino;
    int custo;
} Aresta;

typedef struct {
    Aresta arestas[MAX_CIDADES];
    int tamanho;
} ListaAdj;

ListaAdj grafo[MAX_CIDADES];
int distancia[MAX_CIDADES];

// Função para inicializar o grafo
void inicializarGrafo(int n) {
    for (int i = 0; i < n; i++) {
        grafo[i].tamanho = 0;
    }
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(int u, int v, int p) {
    grafo[u].arestas[grafo[u].tamanho].destino = v;
    grafo[u].arestas[grafo[u].tamanho].custo = p;
    grafo[u].tamanho++;
}

// Função para encontrar o vértice com a menor distância não visitado
int encontrarMinimo(int n, int visitado[]) {
    int minDistancia = INF, minIndice = -1;

    for (int i = 0; i < n; i++) {
        if (!visitado[i] && distancia[i] < minDistancia) {
            minDistancia = distancia[i];
            minIndice = i;
        }
    }

    return minIndice;
}

// Algoritmo de Dijkstra modificado para lidar com a rota de serviço
int dijkstra(int n, int m, int c, int k) {
    int visitado[MAX_CIDADES] = {0};

    // Inicializa as distâncias
    for (int i = 0; i < n; i++) {
        distancia[i] = INF;
    }
    distancia[k] = 0;

    // Executa Dijkstra
    for (int i = 0; i < n; i++) {
        int u = encontrarMinimo(n, visitado);
        if (u == -1) break;  // Não há mais vértices acessíveis
        visitado[u] = 1;

        for (int j = 0; j < grafo[u].tamanho; j++) {
            int v = grafo[u].arestas[j].destino;
            int peso = grafo[u].arestas[j].custo;

            // Respeita a rota de serviço
            if (u < c - 1 && v != u + 1) continue;

            if (!visitado[v] && distancia[u] != INF && distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
            }
        }
    }

    return distancia[c - 1];
}

int main() {
    int n, m, c, k;

    while (1) {
        // Lê as entradas
        scanf("%d %d %d %d", &n, &m, &c, &k);
        if (n == 0 && m == 0 && c == 0 && k == 0) break;

        inicializarGrafo(n);

        // Lê as arestas
        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adicionarAresta(u, v, p);
            adicionarAresta(v, u, p);  // Grafo não direcionado
        }

        // Executa o algoritmo de Dijkstra e imprime o resultado
        printf("%d\n", dijkstra(n, m, c, k));
    }

    return 0;
}
