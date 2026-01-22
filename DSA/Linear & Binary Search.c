// Francisco, Marl Louie - Linear & Binary Search in 1 Program
// Hi sir, I merged the 2 programming projects into 1 program hehe :>
// REQUIRED: 1. linear search function, 2. binary search function
// Added: selection sort

#include <stdio.h>
#include <stdlib.h>

// function prototypes to call
int linear_search(int arr[], int target, int size);
void selection_sort(int arr[], int size);
int binary_search(int arr[], int target, int size);

void main(){
    int size, choice, value, found;

    printf("Welcome to the Searching Program\nBy Francisco, Marl\n");
    // STEP 1. INPUT ARRAY SIZE
    printf("\nInput the array size: ");
    scanf("%d", &size);
    int arr[size];

    // STEP 2. INPUT ARRAY ELEMENTS
    printf("\nInput %d index values in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        scanf("%d", &arr[i]);
    }

    while(1) {
        // STEP 3. SELECT IN MAIN MENU
        printf("\nMain Menu\n1. Linear/Sequential Search\n2. Binary Search\n3. Exit\n");
        printf("\nInput number of choice: ");
        scanf("%d", &choice);
    
        switch(choice) {
            // STEP 4.1. LINEAR SEARCH
            case 1:
                // display array first
                printf("\nArray: \n");
                for (int i = 0; i < size; i++) {
                    printf("%d  ", arr[i]);
                }

                // input value to search
                printf("\n\nLinear Search is to search an index in an array sequentially.");
                printf("\nInput value to search: ");
                scanf("%d", &value);

                // call linear search function
                found = linear_search(arr, value, size);
                
                // display result (if found or not)
                if (found != -1) {
                    printf("\n%d is present at index %d.", arr[found], found);
                    printf("\n%d is present at position %d in the array.\n", arr[found], found + 1);
                } else {
                    printf("\nValue %d is not found.\n", value);
                }
                // to end in case 1 right here right now
                break;

            // STEP 4.2. BINARY SEARCH
            case 2:
                // sorted first in selection sort
                printf("\nThe array is sorted first using Selection Sort.");
                selection_sort(arr, size);

                // now input value to search
                printf("\n\nBinary Search is to repeatedly dividing the search interval in half.");
                printf("\nInput value to search: ");
                scanf("%d", &value);

                // call binary search function
                found = binary_search(arr, value, size);

                // display result (if found or not)
                if (found != -1) {
                    printf("\n%d is present at index %d.", arr[found], found);
                    printf("\n%d is present at position %d in the array.\n", arr[found], found + 1);
                } else {
                    printf("\nValue %d is not found.\n", value);
                }
                // end case 2
                break;

            // STEP 3.3. EXIT
            case 3:
                printf("Exiting the program. Thank you!\n");
                exit(0);
                break;

            // Other number inputs
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

// "function that takes an array and a target value as input" -------------------------------------
// but, int size is needed to limit the loop within the array bounds
int linear_search(int arr[], int target, int size) {
    for (int i = 0; i < size; i++) {
// "returns the index of the target if found;" ----------------------------------------------------
        if (arr[i] == target) {
            return i;
        }
    }
// "or -1 if not found" ---------------------------------------------------------------------------
    return -1;
}

// selection sort function to sort array before binary search
void selection_sort(int arr[], int size) {
    int position;
    
    for (int i = 0; i < size - 1; i++) {
        position = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[position] > arr[j]) {
                position = j;
            }
        }

        if (position != i) {  // swap only if position is changed 
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }

    printf("\nSorted Array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
}

// "binary search function for sorted arrays" (already sorted thanks to selection sort) -----------
int binary_search(int arr[], int target, int size) {
    int first, middle, last;

    first = 0;
    last = size - 1;

    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] < target) {
            first = middle + 1;
        } else if (arr[middle] == target) {
            return middle;
        } else {
            last = middle - 1;
        }
    }
    return -1;
}
