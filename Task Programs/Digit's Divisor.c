/*  Entering a digit, then finding all its Proper Divisor;
    Summation of all of the digit's proper divisor;
    Determining its category: DEFICIENT, PERFECT, ABUNDANT  
*/
#include <stdio.h>

int main() {
    int n, sum;
    char choice;

    do {
        printf("Enter a positive integer (N): ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Please enter a positive integer. Try again.\n\n");
            continue;
        }

        sum = 0;
        printf("Proper divisors of %d are: ", n);
        for (int i = 1; i <= n / 2; i++) { 
            if (n % i == 0) {
                printf("%d ", i);
                sum += i;
            }
        }
        printf("\nSum of proper divisors: %d\n", sum);

        if (sum < n) {
            printf("%d < %d is DEFICIENT\n", sum, n);
        } else if (sum == n) {
            printf("%d = %d is PERFECT\n", sum, n);
        } else {
            printf("%d > %d is ABUNDANT\n", sum, n);
        }

        printf("\nDo you want to check another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");
    return 0;
}
