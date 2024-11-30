#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Pilha {
    int x;
    struct Pilha *next;
} No;

void Push(int y, No *head) {
    No *new;
    new = (No*) malloc(sizeof(No));
    new->x = y;
    new->next = head->next;
    head->next = new;
}

int Pop(No *head) {
    int z;
    No *q;
    q = head->next;
    z = q->x;  // Corrigido para acessar q->x
    head->next = q->next;
    free(q);
    return z;  // Corrigido para retornar z
}

void FtoP(char *Eq) {
    No head;
    head.next = NULL;  // Corrigido para inicializar head
    int k = 0;
    char result[301] = {0};  // Corrigido para inicializar result com zeros
    
    for (int i = 0; Eq[i] != '\0'; i++) {  // Corrigido para usar Eq[i] != '\0'
        if (isalnum(Eq[i])) {
            result[k++] = Eq[i];
        }
        if (Eq[i] == '(') {
            Push(Eq[i], &head);  // Corrigido para passar o endereço de head
        }
        if (Eq[i] == ')') {
            while (Pop(&head) != '(') {
                result[k++] = Pop(&head);
            }
        }
        if (Eq[i] == '*' || Eq[i] == '+' || Eq[i] == '/' || Eq[i] == '-' || Eq[i] == '^') {
            Push(Eq[i], &head);  // Corrigido para passar o endereço de head
        }
    }
    printf("%s\n", result);  // Corrigido para imprimir result
}

int main() {
    int N;
    char Eq[301];
    
    scanf("%d", &N);
    getchar();
    
    for (int i = 0; i < N; i++) {
        fgets(Eq, sizeof(Eq), stdin);  // Corrigido para usar Eq
        FtoP(Eq);
    }
    
    return 0;
}
