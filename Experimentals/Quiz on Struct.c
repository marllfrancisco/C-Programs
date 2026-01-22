#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANSWER_LENGTH 100

typedef struct { // Struct to store question and correct answer
    char question[MAX_ANSWER_LENGTH];
    char correctAnswer[MAX_ANSWER_LENGTH];
} Question;

void shuffleQuestions(Question questions[], int numQuestions) { // Function to shuffle the array of questions
    srand(time(NULL));  // Seed the random number generator with the current time
    for (int i = numQuestions - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Random index from 0 to i
        // Swap questions[i] and questions[j]
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    int score = 0;  // Tracks score for correct answers on the first attempt
    char answer[MAX_ANSWER_LENGTH];
    int numQuestions = 14;  																//INPUT THE TOTAL NUMBER OF QUESTIONS

    // Array of questions																	//INPUT THE QUESTIONS AND ASNWERS
    Question questions[] = {
        {"Group or community that shares common experiences to shape understanding", "Culture"},
        {"Individual's conviction about the world, shaped by culture", "Beliefs"},
        {"Universal standards, right or wrong, objective", "Morals"},
        {"Gestures, Non-verbals", "High-Context Cultures"},
        {"Process of learning one's own customs, conventions, practices in society", "Enculturation"},
        {"Adapting to the new culture, subconsciously", "Acculturation"},
        {"He is the author of The Developmental Model of Intercultural Sensitivity in 1986", "Milton J. Bennett, Ph.D."},
        {"The 1st step of Experiences of Differences", "Denial"},
        {"The 3rd step of Experiences of Differences", "Minimalization"},
        {"The 4th step of Experiences of Differences", "Acceptance"},
        {"The last step of Experiences of Differences", "Integration"},
        {"What is linked at the 1st step of Experiences of Differences", "Ethnocentrism"},
        {"Framework to explain people experiences and engage cultural differences", "The Developmental Model of Intercultural Sensitivity"},
        {"4 Socio-Cultural Aspects of Communication (CI, GR, AI, SC)", "Cultural Identity, Gender Roles, Age Identity, Social Class"},
        
    };

    // Shuffle the questions array
    shuffleQuestions(questions, numQuestions);

    printf("Welcome to the Quiz Program!\n");
    printf("Answer the following questions:\n");

    // Loop through the shuffled questions
    for (int i = 0; i < numQuestions; i++) {
        int firstAttempt = 1;  // Flag to track if it's the user's first attempt at this question

        while (1) {
            printf("\n%s ", questions[i].question);
            fgets(answer, sizeof(answer), stdin);  // Get user input
            answer[strcspn(answer, "\n")] = '\0';  // Remove newline character

            if (strcmp(answer, questions[i].correctAnswer) == 0) {
                if (firstAttempt) {
                    score++;  // Only increase score if it's the first attempt
                }
                printf("Correct!\n");
                printf("//----------------------------------------------------------------------------------------\n");
                break;  // Exit the loop and move to the next question
            } else {
                printf("Wrong! Try again.\n");
                firstAttempt = 0;  // Mark that the user failed on the first attempt
                printf("X-----------------------------------------------------------------------------------------\n");
            }
        }
    }

    // Display the final score
    printf("\nYour final score is: %d/%d\n", score, numQuestions);

    if (score == numQuestions) {
        printf("Excellent! You got all the answers right on the first attempt!\n");
    } else if (score >= 11) {													//CUSTOMIZABLE 
        printf("Good job! You got most of them right on the first attempt.\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}

