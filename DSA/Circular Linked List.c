// Francisco - Circular Linked List
#include <stdio.h>
#include <stdlib.h>

// linked list w prev and next
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} Node;

// function to create a circular doubly linked list node
Node* circdoubly(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (!temp) { perror("malloc"); exit(EXIT_FAILURE); }
    temp->data = data;
    temp->next = temp;  // point to itself muna
    temp->prev = temp;
    return temp;
}

// function to append a node
Node* appendnode(Node *tail, int data) {
    Node *newNode = circdoubly(data);   // create new node from circdoubly

    if (tail == NULL) {
        return newNode; // 1st node is the tail
    } 
    else {
        Node *head = tail->next; // current head
        tail->next = newNode;   // link from old tail to new node
        newNode->prev = tail;   // link new node back to old tail 
        newNode->next = head;   // link new node to head (old node)
        head->prev = newNode;   // link head back to new node

        return newNode; // newNode becomes new tail
    }
}

// function to input data, return updated tail
Node* inputdata(Node *tail, int *num) {
    int data;

    printf("Input the number of nodes : ");
    if (scanf("%d", num) != 1 || *num <= 0) {
        printf("Invalid number of nodes.\n");
        *num = 0;
        return tail;
    }

    for (int i = 0; i < *num; i++) {
        printf("Input data for node %d : ", i + 1);
        if (scanf("%d", &data) != 1) { 
            printf("Invalid input.\n"); 
            exit(EXIT_FAILURE); }   // exit on alphabet & symbols input

        tail = appendnode(tail, data);  // update tail each time
    }
    return tail;
}

// function to output the list
void outputlist(Node *tail, int num) {
    if (tail == NULL || num <= 0) {
        printf("List is empty.\n");
        return;
    }

    Node *current = tail->next; // start at head

    for (int i = 0; i < num; i++) {
        printf("Data %d = %d\n", i + 1, current->data);
        current = current->next; // move to next node
    }
    printf("\n");
}

// thee main function
int main(void) {
    char try;

    do{
        int num = 0;
        Node *tail = NULL;

        tail = inputdata(tail, &num); // updated tail; num set by inputdata
        printf("\nData list output:\n");
        outputlist(tail, num);

        printf("Do you want to try again? (Y/N): "); 
        scanf(" %c", &try);
    } while (try == 'Y' || try == 'y');     // to rerun the program w/o exiting

    printf("\nThank you for using my program!\n");
    return 0;
}
