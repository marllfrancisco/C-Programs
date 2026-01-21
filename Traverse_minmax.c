// Francisco - Find the MIN and MAX value (not the lowest index or highest index )
#include <stdio.h>

// function to find the minimum and maximum elements in an array
void Min_Max(int arr[], int num, int *min, int *max) { // using pointers to return min and max
    for (int i = 1; i < num; i++) {
        if (arr[i] < *min) {    
            *min = arr[i];      // if current element is less than min, update min
        }
        if (arr[i] > *max) {
            *max = arr[i];      // if current element is greater than max, update max
        }
    }
}   

// the main function that calls Min_Max
int main() {
    // size of the array 
    int num;

    // where the size of the array is taken
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &num);

    // declare the array
    int arr[num]; 

    // where the elements of the array are taken
    printf("Input %d elements in the array : \n", num);
    for (int i = 0; i < num; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // where min and max are initialized as the first element of the array
    int min = arr[0], max = arr[0];

    // function call to find the min and max
    Min_Max(arr, num, &min, &max);

    // finally printing the minimun and maximum elements
    printf("\nMaximum element is : %d\n", max);
    printf("Minimum element is : %d\n", min);

    return 0;
}