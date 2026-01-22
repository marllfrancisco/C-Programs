#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *next;
} Node;

int main(void) {
    Node *P;
    Node *Q;

    P = malloc(sizeof(Node));
    Q = malloc(sizeof(Node));
    if (!P || !Q) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    P->info = 5;
    P->next = NULL;
    Q->info = 6;
    Q->next = NULL;

    /* Now make P point to Q; both P and Q point to the same node */
    P = Q;
    P->info = 1; /* modifies the node pointed to by both P and Q */

    printf("%d %d\n", P->info, Q->info); /* prints "1 1" */

    free(Q); /* free the single allocated node */
    return 0;
}