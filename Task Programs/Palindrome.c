// Determine if a string is a palindrome (ex: elle)

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() {
    char str[100], reversed[100], try;

    do {
        
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);

        // Remove trailing newline character if present
        //str[strcspn(str, "\n")] = '\0';

        strcpy(reversed, str);
        strrev(reversed);
        
        if (strcmp(str, reversed) == 1) {
            printf("It's a palindrome.\n");
        } else {
            printf("It's not a palindrome.\n");
        }

        printf("\nWanna try again (y/n): ");
        scanf("%c", &try);
        getchar();  // <-- This consumes the newline left by scanf()

    } while (try == 'y' || try == 'Y');
    
    return 0;
}