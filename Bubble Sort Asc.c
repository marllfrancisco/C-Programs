// Francisco - Bubble Sort in ascending order
#include <stdio.h>

// function for bubble sorting
void bubbleSort(int arr[], int n) {
    // declare indeces and temp variable for swapping
    int i, j, temp;

    // the nested loop to assess each element
    for (i = 0; i < n - 1; i++) {   
        for (j = 0; j < n - i - 1; j++) { // conditioned to - i - 1 since last i elements are already sorted
            if (arr[j] > arr[j + 1]) {  // '>' for ascending order
                // swapping happens here (via temporary variable)
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// main function
int main() { 
    int n;

    // where the size of the array is taken
    printf("Input the size of array : ");
    scanf("%d", &n);

    // declare the array
    int arr[n];

    // where the elements of the array are taken
    printf("Input %d elements in the array : \n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // function call to sort the array
    bubbleSort(arr, n);

    // printing the sorted array
    printf("\nElements of array in sorted ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}