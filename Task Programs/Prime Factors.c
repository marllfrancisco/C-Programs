//GROUP 2
/* NOTES:
    continue - exits the do-while loop, or any loop
	modulus - determine the prime factors (means the numero is divisible by tagadivide)
*/
#include <stdio.h>

int main() {
    int numero, tagadivide;
    char pumili;

    do {
        printf("Enter a non-negative number: ");
        scanf("%d", &numero);
        
        if (numero < 0) {
            printf("Error. Negative number detected. Please run the program again.\n");
            continue; 
        }
        
        printf("Prime factors of %d are: ", numero);

        if (numero == 1 || numero == 0) {
                    printf("1");
        } else  {
        	        printf("1 ");
            for (tagadivide = 2; numero > 1; tagadivide++) {
                while (numero % tagadivide == 0) {
                    printf("%d ", tagadivide);
                    numero /= tagadivide;
                }
            }
        }

        printf("\n\nDo you wish to continue? (y/n): ");
        scanf(" %c", &pumili);
    } while (pumili == 'y' || pumili == 'Y');
    printf("Program ended. See you!\n");
    
    return 0;
}
