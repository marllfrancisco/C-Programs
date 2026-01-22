// All about passing arrays into functions

/*  FRANCISCO, MARL LOUIE T.
    MAGDAY, JOHN PAUL E.
    NAVARROSA, CEDRIC I.
    GROUP 2
    MULTIDIMENSIONAL ARRAY: SUM OF PRODUCTS */

#include <stdio.h>

// Global variables
int i, j, k;

// Function
void SumProd(int A[], int B[][3], int C[]) {
    for (i = 0; i < 3; i++) {
        C[i] = 0; 
        for (j = 0; j < 3; j++) {
            C[i] += A[j] * B[i][j]; 
        }
    }
}

int main() {
    int A[3], B[3][3], C[3];
    char anot;

    // Input
    do {
        printf("Welcome to Array Sum of Products :> \n");
        
        printf("Please enter 3 numbers for Array A: ");
        for (i = 0; i < 3; i++) {
            scanf("%d", &A[i]);
        }

        printf("Please enter 9 numbers for Array B: ");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                scanf("%d", &B[i][j]);
            }
        }

        // Call function w parameters
        SumProd(A, B, C);

        // Output
        printf("\nArray A \n");
        for (i = 0; i < 3; i++) printf("%d ", A[i]);

        printf("\n\nArray B \n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d ", B[i][j]);
            }
            printf("\n");
        }

        printf("\nArray C \n");
        for (i = 0; i < 3; i++) printf("%d ", C[i]);

        // Another run
        printf("\nWanna start another (y/n)? ");
        scanf(" %c", &anot); 

        printf("\n");
    } while (anot == 'Y' || anot == 'y');

    return 0;
}

