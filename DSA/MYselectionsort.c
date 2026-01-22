// C program for implementation of selection sort 
#include <stdio.h> 
  
  
void selectionSort(int arr[], int n) { 
    int i, j, min_idx, temp; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n - 1; i++) { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) {
            if (arr[min_idx] > arr[j]) { 
                min_idx = j; }
            }
        // Swap the found minimum element with the first 
        // element 
        temp = arr[min_idx]; 
        arr[min_idx] = arr[i]; 
        arr[i] = temp; 
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = { 64, 25, 12, 22, 11 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Sorted array: \n"); 
    selectionSort(arr, n); 
    printArray(arr, n); 
    return 0; 
}
