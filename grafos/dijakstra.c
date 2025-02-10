#include <stdio.h>

typedef struct{
    int V, valor;
} node;



typedef struct{
    node elementos[260 * 260];
    int tamanho;
} minHeap;

void pushHeap(minHeap *heap, int valor){
    heap->elementos[heap->tamanho] = elemento;
    int i = heap->tamanho;
    heap->tamanho++;

    while(i > 0 && heap->elementos[i].valor < heap->elemento[(i -1) / 2].valor){
        node aux = heap->elementos[i];
        heap->elementos[i].valor = heap->elemento[(i -1) / 2];
        heap->elemento[(i -1) / 2] = aux;
        i = (i -1) / 2;
    }
}

void popHeap(heap){
    node raiz = heap->elementos[0];
    heap->elementos[0] = heap elementos[heap->tamanho -1];
    heap->tamanho--;
    int i = 0;

    while(2*i +1 < heap->tamanho){
        int menor = 2*i +1;
        if(menor + 1< heap->tamanho && heap->elementos[menor+1].valor < heap->elementos[menor].valor){//escolhe qual o menor filho entre o direito e o esquerdo
            menor++;
        }
        if(heap->elementos[i].valor <= heap->elementos[menor].valor){//quando a propriedade foi restaurada
            break;
        }
        node aux = heap->elementos[i];
        heap->elementos[i] = heap->elementos[menor];
        heap->elementos[menor] = aux;
        i = menor;

    }
    return raiz;
}

node graf[260][260];
int visited[260];
int distMin[260];
int anterior[260];

void initGraf(int n){//valores iniciais de todos os vertices do grafo
    for(int i = 0; i < n; i++){
        visited[i] = 0;
        distMin[i] = INT_MAX;
        anterior[i] = -1;
        
        for(int j = 0; j<n; j++){
            graf[i][j] = -1;
        }
    }
}

int dijakstra(int n, int origem, int dest){
    
    minHeap heap;//inicia o heap
    heap.tamnho = 0;//inicia o tamnho do heap como 0
    distMin[origem] = 0; 
    
    node inicial = {origem , 0};  //primeiro no do heap
    popHeap(heap, inicial);   //adiciona esse primeiro no ao heap
    
    while(heap.tamnho > 0){
        
        node atual = popHeap(heap);
        int u = atual.V;
        
        if (visitado[u]) continue;
        visitado[u] = 1;
        
        if (u == destino) break;
        
        for(int v = 0; v< n; v++){//busca o nó adjacente de menor custo
            
            if (grafo[u][v] != -1) {  // Se há aresta checa a menor distancia
                int custo_v = distMin[u] + graf[u][v];
            }
              
            if(distMin[v] > custo_v) {//insere no heap a aresta de menor distancia 
                distMin[v] = custo_v;
                anterior[v] = u;
                pushHeap(heap, (node){v, custo_v});
                
            } 
            
            
        }
        
        
    }
    
    
}

void mimPath(int origem, int destino){
    if(distMin[destino] = INT_MAX){
        printf("inexitente");
    }
    
    int caminho[INT_MAX];
    int atual = destino;
    int tam = 0;
    
    while (atual != -1) {
        caminho[tam++] = atual;
        atual = predecessores[atual];
    }
    
    for(int i = 0; i < tam; i++){
        printf()caminho[i];
    }
}


int main(){
    

}







