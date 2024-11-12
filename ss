#include <stdio.h>
#include <stdlib.h>

typedef struct filas{
        int Per;
        struct Fila *seg;
} Fila;
     
void Push(Fila *p, int x){
    Fila *new;
    new = malloc(sizeof(Fila));
    new-> Per = x;
    new->seg = p->seg;
    p-> new;
}

void RemoveePop (int x, Fila) {
célula *p, *q;
p = lst;
q = lst->seg;
while (q != NULL && q->conteúdo != x) {
p = q;
q = q->seg;
}
if (q != NULL) {
p->seg = q->seg;
free (q);
}
}


    
    
int main() {
    
    //criar uma lista 'FILA'
    int N, M;
    char str[10000];
    char str2[1000];
    char Pessoas[50000];
    char Pessoass[50000];
    
    scanf("%d", &N);
    #include <stdio.h>
 
int main() {#include <stdio.h>
 
int main() {
    
    //criar uma fila 'FILA'
    //criar uma função pop para ela dentro de um for que funciona M vezes
    //imprimir a fila
    
    return 0;
}#include <stdio.h>
 
int main() {
    
    //criar uma fila 'FILA'
    //criar uma função pop para ela dentro de um for que funciona M vezes
    //imprimir a fila
    
    return 0;
}
    
    //criar uma fila 'FILA'
    //criar uma função pop para ela dentro de um for que funciona M vezes
    //imprimir a fila
    
    return 0;
}#include <stdio.h>
 
int main() {
    
    //criar uma fila 'FILA'
    //criar uma função pop para ela dentro de um for que funciona M vezes
    //imprimir a fila
    
    return 0;
}
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int count =0;
    
    char *token = strtok(str, " ");

        // Dividir a lista de compras em itens
        while (token != NULL) {
            Pessoas[count++] = token;
            token = strtok(NULL, " ");
        }
    
    for(int i = 0; i<=N; i++){
        Push(Pessoas[i], )
    }
    
    scanf("%d", &M);
    
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    int count2 =0;
    
    char *token = strtok(str2, " ");

        // Dividir a lista de compras em itens
        while (token != NULL) {
            Pessoass[count2++] = token;
            token = strtok(NULL, " ");
        }
    
    for(int i = 0; i->M; i++){
        RemoveePop(Pessoass[i], )
        
    }
    
    //criar uma função pop para ela dentro de um for que funciona M vezes
    //imprimir a fila
    
    return 0;
            }

            
//como funciona as listas com e sem cabeça?
//nova = (celula *) malloc (sizeof(celula))
//(celula *) pra que serve isso?
