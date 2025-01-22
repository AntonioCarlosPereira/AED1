-montar o grafo
-armazenar as cidades participantes dessas rotas
-utilizar dijaksta para achar o menor caminho apartir do ponto de reparo 
-verificar se este caminho não passa pela rota
--------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100  // Defina um valor máximo para o número de vértices

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



int main() {
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int vertices, arestas, rota, origem;

    // Leitura do número de vértices e arestas
    scanf("%d %d", &vertices, &arestas);
    
    // Inicializa o grafo com o número de vértices
    inicializarGrafo(grafo, vertices);

    // Processamento das arestas
    for (int i = 0; i < arestas; i++) {
        int origem, destino, peso;
        // Leitura de cada aresta
        scanf("%d %d %d", &origem, &destino, &peso);
        
        // Verifica se os vértices fornecidos estão dentro do intervalo válido
        if (origem >= 0 && origem < vertices && destino >= 0 && destino < vertices) {
            // Adiciona a aresta ao grafo
            adicionarAresta(grafo, origem, destino, peso);
        } else {
            printf("Vértice inválido! Aresta não adicionada.\n");
        }
    }


    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <limits.h>

#define V 6  // Número de vértices no grafo

// Função para encontrar o vértice com a menor distância não visitada
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Função de Dijkstra que recebe a matriz de adjacência e os vértices de origem e destino
int dijkstra(int graph[V][V], int start, int end) {
    int dist[V];  // Vetor de distâncias mínimas
    int visited[V];  // Vetor para verificar se o vértice foi visitado
    
    // Inicializa as distâncias com infinito e o vetor de visitados com 0
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;  // A distância da origem para ela mesma é 0
    
    // Encontra o caminho mínimo para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice não visitado com a menor distância
        int u = minDistance(dist, visited);
        
        // Marca o vértice como visitado
        visited[u] = 1;
        
        // Atualiza as distâncias para os vizinhos do vértice escolhido
        for (int v = 0; v < V; v++) {
            // Se houver uma aresta de u para v, e v não foi visitado, e a distância através de u é menor
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Retorna a distância do vértice de origem até o destino
    return dist[end];
}

int main() {
    // Grafo representado por uma matriz de adjacência
    // graph[i][j] = peso da aresta entre i e j (0 significa sem aresta)
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 0},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 0},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 5},
        {0, 0, 0, 0, 5, 0}
    };
    
    int start = 0;  // Vértice de origem
    int end = 4;    // Vértice de destino
    
    int result = dijkstra(graph, start, end);
    
    printf("O peso do caminho mais curto de %d a %d é: %d\n", start, end, result);
    
    return 0;
}
----------------------------------------------------------------------------------------------------------------------
  int dijkstraComSequencia(int graph[V][V], int start, int end) {
    int dist[V];  // Distâncias mínimas
    int visited[V];  // Vértices visitados
    int forced = 0;  // Flag para indicar quando forçamos a sequência

    // Inicializa as distâncias e os visitados
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Laço principal de Dijkstra
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);  // Escolhe o vértice com a menor distância
        visited[u] = 1;

        // Se o vértice u for menor que o destino e a sequência ainda não foi forçada
        if (u < end && !forced) {
            forced = 1;  // Ativa a sequência forçada

            // Segue a sequência numérica até o destino
            for (int v = u + 1; v <= end; v++) {
                dist[v] = dist[u] + graph[u][v];  // Atualiza a distância
                u = v;  // Move para o próximo vértice numericamente maior
            }
        } else {
            // Atualiza as distâncias dos vizinhos de u normalmente
            for (int v = 0; v < V; v++) {
                if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    return dist[end];  // Retorna a distância do vértice de origem até o destino
}
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
