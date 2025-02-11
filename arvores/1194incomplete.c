#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct ArvoreB{//estrutura de dados da arvoreB
    char let;
    struct ArvoreB *E;
    struct ArvoreB *D;
} ArvoreB;



ArvoreB *Arv(char preF, char inF, int start, int end){//função que monta a arvore baseada na inf e pre

	if(start == end){
	break;
	}
	
	int indice = 0;
	    
	ArvoreB *node = NewNode(preF[indice++]);//começa a criação com a raiz da arvore vulgo primeiro elemento preF
	    
	int RaizInf = indRI(char inF, int start, ArvoreB *no->let, inf end);//localização da raiz na infixa
	node->E = Arv(char preF, char inF, int start, int RaizInf-1);//chamada recursiva para a esquerda
	node->D = Arv(char preF, char inF, int RaizInf+1, int end);//chamada recursiva para a direita 
	    
	    
	return node; //retorna a raiz
    
}

int indRI(char *str, int inicio, int fim, char letra)
{

	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra)
			return i;

	return -1;

}

void showposfixa(noArv *no)
{

	if (no == NULL)
		return;

	showposfixa(no->esquerda);
	showposfixa(no->direita);
	printf("%c", no->letra);

} 


noArv* novoNo(char letra)
{

	noArv *no = (noArv *) malloc(sizeof(noArv));
	no->letra = letra;
	no->esquerda = no->direita = NULL;

	return no;
}

int main(){
    
    
    
    
    
}
