/* Square root and Product Array
GROUP 2 | BSIT 1-1
Cruz, Francisco, Magday */
#include <stdio.h>
#include <math.h>

int main() {
    int X[20], Y[20], Z[20];  
    int N = 0, sumZ = 0, i, value; 
    const int SIZE = 20, SENTINEL = -1;

    printf("Enter values for array X (end with %d):\n", SENTINEL);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &value);
        if (value == SENTINEL) {
            break;
        }
        X[i] = value;
        N++;
    }

    printf("Enter values for array Y (end with %d):\n", SENTINEL);
    for ( i = 0; i < N; i++) {
        scanf("%d", &value);
        if (value == SENTINEL) {
            break;
        }
        Y[i] = value;
    }

    for ( i = 0; i < N; i++) {
        Z[i] = X[i] * Y[i];
        sumZ += Z[i];  
    }

    double result = sqrt(sumZ);  

    printf("\nArray X: ");
    for ( i = 0; i < N; i++) {
        printf("%d ", X[i]);
    }

    printf("\nArray Y: ");
    for ( i = 0; i < N; i++) {
        printf("%d ", Y[i]);
    }

    printf("\nArray Z (Products): ");
    for ( i = 0; i < N; i++) {
        printf("%d ", Z[i]);
    }

    printf("\nSquare root of the sum of items in Z: %.2f\n", result);

    return 0;
}
