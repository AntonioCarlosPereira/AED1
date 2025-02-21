
void dfs(M[numv][numv], int v, int visited[numv]){
    visited[v]=1;
    
    for(int i = 0, i<numv, i++){
        if(M[v][i] != 0 && !visited[i]){
            dfs(M, i, visited);
        }
    }
}
//




int main(){
    scnaf() int vertex, arestas;
    int M[vertex][vertex];
    
    
    for(int i = 0; i<arestas; i++){//monta a matriz musando os numeros equivalentes as letras
        scanf()int c,v;
        int index-c = c -'a';
        int index-v = v-'a';
        M[index-v][index-c] = 1;
        M[index-c][index-v] = 1;
    }
    
    
    for(int i = 0; i<numcomp; i++){//printa a letra pelo numero
        printf() componentes[i] + 'a';
    }
}
