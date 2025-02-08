int Pesquisa(ArvoreB* Raiz, int valor, int profundidade){//função retorna a profundidade em que se encontra o elemento
    if(Raiz == NULL){
        return -1;
    }
    if(valor < Raiz->valor){
        Pesquisa(Raiz->E, valor, profundidade+1);
    }
    else if(valor > Raiz->valor){
        Pesquisa(Raiz->D, valor, profundidade+1);
    }
    else (valor == Raiz){
        return profundiade;
    }
}

bool Pesquisa(ArvoreB* Raiz, int valor){//função retorna se o elemento esta presente 
    if(Raiz == NULL){
        return 0;
    }
    if(valor < Raiz->valor){
        Pesquisa(Raiz->E, valor);
    }
    else if(valor > Raiz->valor){
        Pesquisa(Raiz->D, valor);
    }
    else {
        return 1;
    }
}

int busca_binaria(int v[], int n, int x) {//busca binaria em um vetor
    int esquerda = 0, direita = n - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (v[meio] == x) {
            return meio; // Encontrou o elemento
        } else if (v[meio] < x) {
            esquerda = meio + 1; // Buscar na metade direita
        } else {
            direita = meio - 1; // Buscar na metade esquerda
        }
    }
    
    return n; // Elemento não encontrado
}
