#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct node of the linked list
typedef struct node {   // thia is like a blueprint
    int digit;
    struct node *link;
} Node;

// funtion to create a new node
Node* createNode(int digit) {
    Node *newNode = (Node*)malloc(sizeof(Node));    // actually a pointer w DYNAMIC SIZE
    newNode->digit = digit;
    newNode->link = NULL;   // null at first 
    return newNode;
}

// function to insert digit at the front (this is reversed insertion)
Node* insertHead(Node *head, int digit) {   // num[i] into digit
    Node *newNode = createNode(digit);  // pointer from CREATENODE (digit)
    newNode->link = head;   // labeling as the head 
    return newNode;
}

// function to convert a string number into a linked list (head = units place)
Node* stringToList(const char *num) {
    Node *head = NULL;  // address of head start as NULL
    int len = strlen(num);  // length of the number
    for (int i = 0; i < len; i++) {      // iterate from first char to last
        head = insertHead(head, num[i] - '0');  // insert at head
    }
    return head; 
}

// Add two linked list numbers
Node* addLists(Node* list1, Node* list2) {
    Node *result = NULL;
    Node *tail = NULL;
    int carry = 0;

    while(list1 != NULL || list2 != NULL || carry > 0) {    // keep adding as they have values
        int temp1 = (list1 != NULL) ? list1->digit : 0;    // copy digit to temp int, 0 if no value
        int temp2 = (list2 != NULL) ? list2->digit : 0;

        int sum = temp1 + temp2 + carry;
        carry = sum / 10;   // divide to 10 for carry
        int digit = sum % 10;   // mod for final digit

        Node *newNode = createNode(digit);  // new node for result
        if(result == NULL) {    // for the first node
            result = newNode;   // head of sum list
        } else {    // for following nodes 
            tail->link = newNode;   // link old node to new
        }
        tail = newNode; // labelling as tail

        // we move to the next node/digit
        if(list1 != NULL) 
            list1 = list1->link;
        if(list2 != NULL) 
            list2 = list2->link;
    }
    return result;
}

// function print in normal way 
void printFwd(Node* head) { // recursive function to assess the last node first
    if(head == NULL) return;
    printFwd(head->link);
    printf("%d", head->digit);
}

// function print in stored linked list form 
void printRev(Node* head) {
    while(head != NULL) {
        printf("%d", head->digit);  // print then move to next
        head = head->link;
    }
}

// function to free memory
void freeList(Node *head) {
    while (head) {
        Node *tem = head;
        head = head->link;
        free(tem);
    }
}

// the main function
int main() {
    char try;

    do{
        char num1[256], num2[256];

        printf("Enter first number: ");
        scanf("%s", num1);  // as string 

        printf("Enter second number: ");
        scanf("%s", num2);

        Node* list1 = stringToList(num1);   // convert from string to list
        Node* list2 = stringToList(num2);
        Node* sumlist = addLists(list1, list2); // head of the result list (in addLists)

        printf("\nList 1         : ");
        printFwd(list1);

        printf("\nList 2         : ");
        printFwd(list2);

        printf("\nSum            : ");
        printFwd(sumlist);

        printf("\nResult (stored): ");
        printRev(sumlist);
        printf("\n");

        // cleanup
        freeList(list1);
        freeList(list2);
        freeList(sumlist);

        printf("\nDo you want to try again? (Y/N): "); 
        scanf(" %c", &try);
    } while (try == 'Y' || try == 'y');     // to rerun the program w/o exiting

    printf("\nThank you for using my program!\n");
    return 0;
}
