// Francisco, Marl Louie - Max Heap Program in Array

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// function prototypes to call
void heap_insert(int heap[], int *heap_size);
void find_max(int heap_size, int heap[]);
void find_min(int heap_size, int heap[]);
void heap_delete(int heap[], int *heap_size);

// swap two integers (parent and child)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// up heapify for INSERTION - maintains the max-heap property
void up_heapify(int heap[], int child) {
    int parent = (child - 1) / 2;           // Find parent index

    if (heap[parent] < heap[child]) {       // If max-heap property is violated (> for min-heap)
        swap(&heap[parent], &heap[child]);    // Swap parent and child
        up_heapify(heap, parent);           // recursive, the parent might violate heap property
    }
}

// down heapify for DELETION - maintains the max-heap property
void down_heapify(int heap[], int parent, int size) {
    int largest = parent; 
    int leftChild = (2 * parent) + 1;
    int rightChild = (2 * parent) + 2;

    // Compare left child
    if (leftChild < size && heap[leftChild] > heap[largest])
        largest = leftChild;                                    // Update largest if left child is greater

    // Compare right child
    if (rightChild < size && heap[rightChild] > heap[largest])
        largest = rightChild;                                   // Update largest if right child is greater

    // If the largest isn't the parent, swap and continue downward
    if (largest != parent) {
        swap(&heap[parent], &heap[largest]);
        down_heapify(heap, largest, size);
    }
}

void main(){
    int choice, val;
    int heap[100];      // fixed, unfortunately
    int heap_size = 0;

    printf("Welcome to the Max-Heap Program\nBy Francisco, Marl\n");

    while(1) {
        // MAIN MENU
        printf("\nMain Menu\n1. Insert\n2. Find Max Value\n3. Find Min Value\n4. Delete Node\n5. Exit\n");
        printf("\nSelect number of choice: ");
        scanf("%d", &choice);
    
        switch(choice) {
            // INSERT
            case 1:
                heap_insert(heap, &heap_size);
                break;

            // FIND MAX  
            case 2:
                find_max(heap_size, heap);
                break;

            // FIND MIN 
            case 3:
                find_min(heap_size, heap);
                break;

            // DELETE
            case 4:
                heap_delete(heap, &heap_size);
                break;

            // EXIT
            case 5:
                printf("Exiting program. Thank you!\n");
                exit(0);
                break;

            // Other number inputs
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

void display_heap(int heap[], int heap_size) {
        // display heap info 
        printf("\nHeap size: %d", heap_size);
        printf("\nHeap values: ");
        for(int i = 0; i < heap_size; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");
}

void heap_insert(int heap[], int *heap_size) {
    int hm, i, val;
    
    // display current heap
    display_heap(heap, *heap_size);
    printf("\nHow many elements will you add: ");
    scanf("%d", &hm);

    for (i = 0; i < hm; i++) {
        printf("Insert value (index %d): ", *heap_size);
        scanf("%d", &val);
        heap[*heap_size] = val;                // insert value at the end of the heap
        (*heap_size)++;                        // increase heap size recorder
        up_heapify(heap, *heap_size - 1);      // call up_heapify function
    }

    // display updated heap
    printf("\nValue inserted successfully :)");
    display_heap(heap, *heap_size);
}

void find_max(int heap_size, int heap[]) {
    printf("\n");
    if (heap_size == 0) {
        printf("Heap is empty.\n");
    } else {
        printf("Heap's Maximum value: %d\n", heap[0]);
    }
}

void find_min(int heap_size, int heap[]) {
    printf("\n");
    if (heap_size == 0) {
        printf("Heap is empty.\n");
    } else {
        int min = INT_MAX;
        for(int i = 0; i < heap_size; i++) {
            if(heap[i] < min) {
                min = heap[i];
            }
        }
        printf("Heap's Minimum value: %d\n", min);
    }
}

void heap_delete(int heap[], int *heap_size) {
    int val;

    if (heap_size == 0) {
        printf("Heap is empty. Cannot delete.\n");
    }

    // display current heap
    display_heap(heap, *heap_size);

    printf("\nEnter value to delete: ");
    scanf("%d", &val);

    // if val is not in heap
    int found = 0, i, index = -1;
    for(i = 0; i < *heap_size; i++) {
        if(heap[i] == val) {
            found = 1;
            index = i;              // Store the index of the element to delete
            break;                  // Exit loop once found
        }
    }

    if(found) {
        swap(&heap[index], &heap[*heap_size-1]);    // swap found element with last element
        *heap_size = *heap_size - 1;                // delete that last element
        down_heapify(heap, index, *heap_size);     // heapify from the swapped position
        
        // display updated heap
        printf("\nValue deleted successfully :)");
        display_heap(heap, *heap_size);
    } else {
        printf("\nValue not found in heap.\n");
    }
}