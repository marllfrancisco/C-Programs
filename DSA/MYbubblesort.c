// C program for implementation of Bubble sort
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already in place, so the loop will only num n - i - 1 times
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            }
        }
}
int main() {
    int arr[] = { 2, 6, 9, 7, 0, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    

    // Calling bubble sort on array arr
    bubbleSort(arr, n);

   
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
