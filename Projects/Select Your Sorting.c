#include <stdio.h>

// Bubble Sort
void sortBubble(int mainMerge[], int arraySize) {
    printf("\nMerged Array:\n");
    for (int pick = 0; pick < arraySize - 1; pick++) {
        for (int i = 0; i < arraySize - 1 - pick; i++) {
            if (mainMerge[i] > mainMerge[i + 1]) {
                int temp = mainMerge[i];
                mainMerge[i] = mainMerge[i + 1];
                mainMerge[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < arraySize; i++) {
        printf("%d  ", mainMerge[i]);
    }
    printf("\n");
}

// Selection Sort
void sortSelection(int arr[], int arraySize) {
    int position, swap;
    for (int i = 0; i < (arraySize - 1); i++) {
        position = i;
        for (int j = i + 1; j < arraySize; j++) {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i) {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    for (int i = 0; i < arraySize; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

// Main Sorting Selector
void sortMain(int mainMerge[], int arraySize) {
    int pickSort;
    printf("\nPick the type of sort (Bubble - 1/Selection - 2): ");
    scanf("%d", &pickSort);

    if (pickSort == 1) {
        sortBubble(mainMerge, arraySize);
    } else if (pickSort == 2) {
        sortSelection(mainMerge, arraySize);
    } else {
        printf("\n\nInvalid Input.\n");
    }
}

// Main function
int main() {
    int arraySize;
    printf("Enter array size (max 10): ");
    scanf("%d", &arraySize);

    if (arraySize > 10 || arraySize < 1) {
        printf("Invalid size.\n");
        return 1;
    }

    int mainMerge[10];
    printf("Enter %d elements:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &mainMerge[i]);
    }

    sortMain(mainMerge, arraySize);
    return 0;
}