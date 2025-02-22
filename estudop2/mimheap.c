#include <stdio.h>


//MIMheap

typedef struct{
    int dado[maxsize];
    int tamanho;
}heap;


void inicio(heap *h){
    h->tamanho = 0;
}

void push(int valor, heap *h){
    int i = h->tamanho;
    h->dado[i] = valor;
    h->tamanho++;
    
    while(h->tamanho <= maxsize; h->dado[i] > h->dado[(i+1)/2]){
        int temp = h->dado[i];
        h->dado[i] = h->dado[(i+1)/2];
        h->dadp[i+1]/2 = temp;
        i = (i+1)/2;
        
    }
}

int pop(heap *h){

    int raiz = h->dado[0];
    h->dado[0] = h->dado[h->tamanho-1];
    h->tamanho--;
    
    int i = 0;
    
    while(2*i - 1 < h->tamanho){
        int E = 2*i+2;
        int D = 2*i+1;
        int mim = E;
        
        if(h->dadp[E] > h->dado[D] && D < h->tamanho){
            mim = D;
        }
        if(h->dado[i] < h->dado[mim]){
            break;
        }
        
        
        int temp = h->dado[i];
        h->dado[i] = h->dado[mim];
        h->dadp[mim]/2 = temp;
        i = mim;
        
    }
}

int main()
{
    printf("Hello World");

    return 0;
}
