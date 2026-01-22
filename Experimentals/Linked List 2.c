// ...existing code...
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeEntry {
    int info;
    struct NodeEntry *next;
} NodeEntry;

typedef NodeEntry *node;

int main(void) {
    node P, Q, P_old;

    P_old = (node) malloc(sizeof(NodeEntry));
    if (!P_old) { perror("malloc"); return 1; }
    P_old->info = 3;
    P_old->next = NULL;

    Q = (node) malloc(sizeof(NodeEntry));
    if (!Q) { perror("malloc"); free(P_old); return 1; }
    Q->info = 2;
    Q->next = NULL;

    /* allocate a new node and assign to P */
    P = (node) malloc(sizeof(NodeEntry));
    if (!P) { perror("malloc"); free(P_old); free(Q); return 1; }

    /* copy Q's info into P, then set Q->info = 0 */
    P->info = Q->info;
    P->next = NULL;
    Q->info = 0;

    printf("%d %d\n", P->info, Q->info); /* expected output: "2 0" */

    free(P);
    free(Q);
    free(P_old);
    return 0;
}