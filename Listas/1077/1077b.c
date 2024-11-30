
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Pilha {
    char x;
    struct Pilha *next;
} No;

void Push(char y, No *head) {
    No *new = (No*) malloc(sizeof(No));
    new->x = y;
    new->next = head->next;
    head->next = new;
}

char Pop(No *head) {
    No *q = head->next;
    char z = q->x;
    head->next = q->next;
    free(q);
    return z;
}

char Peek(No *head) {
    if (head->next) return head->next->x;
    return '\0';
}

int Precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int IsRightAssociative(char op) {
    return op == '^';
}

void FtoP(char *Eq) {
    No head;
    head.next = NULL;
    int k = 0;
    char result[301] = {0};

    for (int i = 0; Eq[i] != '\0'; i++) {
        char c = Eq[i];
        if (isalnum(c)) {
            result[k++] = c;
        } else if (c == '(') {
            Push(c, &head);
        } else if (c == ')') {
            while (head.next && Peek(&head) != '(') {
                result[k++] = Pop(&head);
            }
            Pop(&head);  // Remove '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (head.next &&
                   Precedence(Peek(&head)) >= Precedence(c) &&
                   (!IsRightAssociative(c) || Precedence(Peek(&head)) > Precedence(c))) {
                result[k++] = Pop(&head);
            }
            Push(c, &head);
        }
    }

    while (head.next) {  // Esvaziar pilha restante
        result[k++] = Pop(&head);
    }

    printf("%s\n", result);
}

int main() {
    int N;
    char Eq[301];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        fgets(Eq, sizeof(Eq), stdin);
        Eq[strcspn(Eq, "\n")] = '\0';
        FtoP(Eq);
    }

    return 0;
}


