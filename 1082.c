#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Profundidade(int x){//busca em profundidade
    visited[x] = 1;
    vertices[tam++] = x;
    for(int i = 0; i<V; i++){
        if(MA[x][i]){//procuramos as adjacvencias de x
            if(!visited[i]){//se o vetor adjacente ainda não foi visitado realizamos a busca em profundidade nele
                Profundidade(i);
            }
        } //depois disso teremos os vertices visitados(os conexos com x) e o numero deles(o tamanho do subgrafo )
    }
}

void compara(int *x, int *y){
 	if (*x == *y)
		return 0;
	else if (*x > *y)
		return 1;
	else
	    return -1;  
}

int main()
{   
    int compC = 0;
    int V, A, casos;
    char V1, V2;
    int C;
    int MA[26][26];
    int visted[26];
    int vertices[26];
    
    
    scanf("%d", &casos);//ler numero de casos
    
    while(casos--){
        
        scanf("%d%d", &V, &A);//numero de vertices e arestas 
        
        
        for(int i = 0; i<A; i++){//criando a matriz de adjacencia 
            scanf("%c%c", &V1, &V2);
            MA[V1 - 'a'][V2 - 'a'] = 1;// - a para armazenar os vertices de caracteres em valores numericos
            MA[V2 - 'a'][V1 - 'a'] = 1;//existe outros jeitos de resolver mas isso evita muitos problemas pelo que observei
            
        }
        
        printf("Case #%d:\n", ++caso);
        
        for(int i = 0; i < V; i++){//fazer a busca em profundidade 
            
            
            if(!visited){
                
                Profundidade(i);
                compC++;
                qsort(vertices,tam,stizeof(char), compara);
                for (j = 0; j < tam; ++j){//imprime o subgrafos conectados ao vertice(se o vertice ja estava presente em um subgrafo anterior ele sera pulado pela busca em profundidade)
                    printf("%c,", vertices[j] + 'a');//o +'a' é usado para converter o numero em letra para que possamos imprimir a letra pelo nuumero
                }
                printf("\n");
            }
            tam=0;
        }
        
        
        printf("%d connected components\n", compC);
		printf("\n");
		memset(visted, false, sizeof(visited));//reset dos componentes para a proxima chamada do while 
		memset(MA, 0, sizeof(MA));
        
        
    }
}
