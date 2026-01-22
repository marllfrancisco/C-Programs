// Airline Seat Reservation Program by Group 2
/*NOTES:
    puts("") - print with an independent line (auto newline)  
    sscanf("") - multiple scans
*/

#include <stdio.h>
#include <string.h>

#define ROW_CONST 5
#define COL_CONST 4


struct Seats {
    int forrow;
    char letter;
    int taken; };

void seatmapalgo(struct Seats seats[ROW_CONST][COL_CONST]) {
    for (int i = 0; i < ROW_CONST; i++) {
        for (int j = 0; j < COL_CONST; j++) {
            seats[i][j].forrow = i + 1;
            seats[i][j].letter = 'A' + j;
            seats[i][j].taken = 0; }}}

void showseatmap(struct Seats seats[ROW_CONST][COL_CONST]) {
    puts("\nThe Seat Map as of now:");
    for (int i = 0; i < ROW_CONST; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < COL_CONST; j++) {
            if (seats[i][j].taken)
                printf("X\t");
            else
                printf("%c\t", seats[i][j].letter);
        } printf("\n");}}

int determineseat(struct Seats seats[ROW_CONST][COL_CONST]) {
    for (int i = 0; i < ROW_CONST; i++)
        for (int j = 0; j < COL_CONST; j++)
            if (!seats[i][j].taken)
                return 0; 
    return 1; }

void main() {
    int num, forrow, forcol;
    char letter;
    struct Seats seats[ROW_CONST][COL_CONST];
    char user[4];

    //The initialization of each seats
    seatmapalgo(seats);

    puts("Welcome to Group2 Airlines Seat Reservation!");

    while (!determineseat(seats)) {
        showseatmap(seats);
        puts("\nType a seat number and letter (Ex: 1A)(Capital Letter pls)");
        puts("Type Q to quit.");
        printf("Now Enter: ");
        scanf("%s", user);

        //The quit option
        if (user[0] == 'Q' || user[0] == 'q') {
            puts("Thank you for using our program!\n");
            break;}

        //The checking of the user input
        if (sscanf(user, "%d%c", &num, &letter) != 2 || num < 1 || num > ROW_CONST || letter < 'A' || letter > 'D') {
            puts("Invalid input. Please try again.");
            continue;}
    
        forrow = num - 1;
        forcol = letter - 'A';
        
        //The checking of the seat availability
        if (seats[forrow][forcol].taken) {
            printf("The Seat %d%c is already taken. Please choose another.\n", num, letter);
        } else {
            seats[forrow][forcol].taken = 1;
            printf("The Seat %d%c assigned successfully.\n", num, letter);}}

        if (determineseat(seats)) {
            puts("\nWe're sorry to say that all seats are now taken. Thank you for understanding.");
            showseatmap(seats);
            puts("Only press 'Q' to quit.");}}
