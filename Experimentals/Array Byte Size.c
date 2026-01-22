// Byte Size of Array
/* NOTES:
    sizeof() - total bytes of an array
    %zu - bytes
    %i - integer
*/

#include <stdio.h>

int main() {
    int ddd, size;

    printf("Input size of array: ");
    scanf("%d", &size);
    
    int arr[size];

    printf("\nSize of arr: %zu bytes\n", sizeof(arr));
    printf("Number of elements: %zu\n", sizeof(arr) / sizeof(arr[0]));
    
    printf("\nJust Int: ");
    scanf("%i", &ddd);
    printf("Just Int Result: %i\n", ddd);
    return 0;
}
