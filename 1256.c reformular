#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int          key;
    struct node *next;
} node;

void push (node *head, int n) {
    while (head->next != NULL)
        head = head->next;

    head->next = (node *) malloc (sizeof (node));
    head->next->key = n;
    head->next->next = NULL;
}

void printList (node *head) {
    while (head != NULL) {
        printf ("%d -> ", head->key);
        head = head->next;
    }
    printf ("\\\n");
}

node * initHash (int tableSize) {
    node *temp = (node *) malloc (tableSize * sizeof(node));

    for (int i = 0; i < tableSize; i++) {
        temp[i].next = NULL;
        temp[i].key = i;
    }

    return temp;
}

int hash (int n, int tableSize) {
    return n % tableSize;
}

int main () {
    int n, tableSize, numberOfKeys, x;
    node *hashTable;
    scanf ("%d", &n);
    
    while (n--) {
        scanf ("%d %d", &tableSize, &numberOfKeys);
        
        hashTable = initHash (tableSize);

        for (int i = 0; i < numberOfKeys; i++) {
            scanf ("%d", &x);
            push (hashTable + hash(x, tableSize), x);
        }

        for (int i = 0; i < tableSize; i++)
            printList(hashTable + i);

        if (n)
            printf ("\n");
    }
    
    return 0;
}
