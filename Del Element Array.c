// Francisco - Deleting an element from an array
#include <stdio.h>

// function to delete an element at a given position
void del_element(int arr[], int n, int pos) {
    // shifting elements to the left from the position of deletion
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

// thee main function
int main() {
    int n, pos;

    // where the size of the array is taken
    printf("Input the size of array : ");
    scanf("%d", &n);

    // declare the array
    int arr[n];

    // where the elements of the array are taken
    printf("Input %d elements in the array in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // where the position to delete is taken
    printf("Input the pos where to delete: ");
    scanf("%d", &pos);

    // to call the function to delete an element
    del_element(arr, n, pos);

    // printing the new array after deletion
    printf("The new list is : ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}