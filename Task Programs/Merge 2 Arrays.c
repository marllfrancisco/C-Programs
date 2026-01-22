/*  FRANCISCO, MARL LOUIE T.
    MAGDAY, JOHN PAUL E.
    NAVARROSA, CEDRIC I.
    GROUP 2
    Merging 2 Arrays */

#include <stdio.h>

// recall
void MERGE(int N[], int B[], int MERGE_ARRAY[], int *size);

int main() {
    int i, N[5], B[5], MERGE_ARRAY[10], merge_size = 0, tryyy;
	
    // Input 
    do{
    printf("Welcome to Array Merger :3 \n");
    printf("Please enter 5 numbers for Array N: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &N[i]);
    }

    
    printf("Please enter 5 numbers for Array B: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &B[i]);
    }

    // Call MERGE function
    MERGE(N, B, MERGE_ARRAY, &merge_size);

    // Output
    printf("\nArray N - ");
    for (i = 0; i < 5; i++) printf("%d, ", N[i]);
	
    printf("\nArray B - ");
    for (i = 0; i < 5; i++) printf("%d, ", B[i]);
	
    printf("\nMERGED ARRAY - ");
    for (i = 0; i < merge_size; i++) printf("%d ", MERGE_ARRAY[i]);
    
    printf("\nWanna try again? (yes-1/no-0) ");
    scanf(" %d", &tryyy);
    printf("\n");
	}while (tryyy == 1);
    return 0;
}

// Function to merge two arrays 
void MERGE(int N[], int B[], int MERGE_ARRAY[], int *size) {
    int i, j, k = 0, uniqN, uniqB;

    for (i = 0; i < 5; i++) {
    	uniqN = 1;
        for (j = 0; j < k; j++) {
            if (MERGE_ARRAY[j] == N[i]) {
                uniqN = 0;
                break;  // Break kapag may duplicate
            }
        }
        if (uniqN) {
            MERGE_ARRAY[k++] = N[i];  // Add lang kapag unique
        }    
    }
    for (i = 0; i < 5; i++) {
        uniqB = 1;
        for (j = 0; j < k; j++) {
            if (MERGE_ARRAY[j] == B[i]) {
                uniqB = 0;
                break;  
            }
        }
        if (uniqB) {
            MERGE_ARRAY[k++] = B[i];  
        }
    }

    *size = k;  // Store final array size
}

