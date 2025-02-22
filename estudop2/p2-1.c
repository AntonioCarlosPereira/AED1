#include <stdio.h>
#include <string.h> // Para memset

int MG(int G[numv][numv], int numv) { 
    int noGM = 0, graumax = 0;
    int grau[numv];

    for(int i = 0; i<numv; i++){
        grau[i] = 0;
    } // Inicializa todos os graus com 0

    for (int i = 0; i < numv; i++) {
        for (int j = 0; j < numv; j++) {
            if (G[i][j] != 0) {
                grau[i]++;
            }
        }
        if (grau[i] > graumax || (grau[i] == graumax && i < noGM)) {
            graumax = grau[i];
            noGM = i;
        }
    }
    return noGM;
}


int altura(ArvoreB *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    int alturaEsq = altura(raiz->E);
    int alturaDir = altura(raiz->D);
    
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

int isConex(G[numv][numv], int numv){
    
}

int conexo(G[numv][numv], int numv){
    int start = 0;
    int pilha[numv];
    int top = 0;
    int visited[numv];
    

    for(int i = 0; i<numv ; i++){
        visited[i]=0;
    }
    
    pilha[top++] = start;
    visited[start] = 1;
    
    while(top>0){
        int v = pilha[--top];
        
        
        for(int i = 0; i<numv; i++){
            if(G[v][i] != 0 && !visited[i]){
                visited[i] = 1;
                pilha[top++] = i;
            }
        }
    }
    
    
    for(int i = 0; i<numv ; i++){
        if(!visited[i]){
            return 0;
        }
    }
    return 1;
    
}

int CompConexo(G[numv][numv], int numv){
    int comp = 0;

    int visited[numv];
    

    for(int i = 0; i<numv ; i++){
        visited[i]=0;
    }
    
    for(int c = 0; c<numv ; c++){
        if(!visited[c]){
            comp++;
            int pilha[numv];
            int top = 0;
            pilha[top++] = c;
            visited[c] = 1;
            
            while(top>0){
                int v = pilha[--top];
                
                
                for(int i = 0; i<numv; i++){
                    if(G[v][i] != 0 && !visited[i]){
                        visited[i] = 1;
                        pilha[top++] = i;
                    }
                }
            }
        }
    }
    return comp;

}
