// Program that determines if a student passed or failed;
// depending on the answer value (1-5) 
// Student scores are stored in array

#include <stdio.h>

void input() {
    int answer, score;
    int TP[5];  // Array to store total scores of each student

    for (int i = 0; i < 5; i++) {
        score = 0;
        printf("Hi Student %d, enter your answer:\n", i + 1);

        for (int j = 0; j < 5; j++) {
            do {
                printf("Question %d (Enter choice 1-5): ", j + 1);
                scanf("%d", &answer);
                if (answer < 1 || answer > 5)
                    printf("Invalid choice. Please enter a number from 1 to 5.\n");
            } while (answer < 1 || answer > 5);

            // Convert answer to points
            score += answer * 2;
        }

        TP[i] = score;  // Store total score in the array

        printf("Total Score for Student %d: %d - ", i + 1, TP[i]);

        if (TP[i] >= 30)
            printf("PASSED\n");
        else
            printf("FAILED\n");

        printf("\n");
    }

    //(Optional) If you want to display all stored scores afterward:
    printf("All Students' Total Scores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: %d\n", i + 1, TP[i]);
    }
    
}

int main() {
    input();
    return 0;
}