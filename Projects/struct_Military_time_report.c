// ABC Computer Center Daily Monitoring Report
// determine payment by hours bu in militaty time format

#include <stdio.h>

struct inputs {
    char Computer_ID[50]; 
    int time_In, time_Out;
};

void computation(int time_In, int time_Out);

int main() {
    char again;
    struct inputs customer;

    do {
        printf("\nABC Computer Center Daily Monitoring Report");
        printf("\n-----------------------------------------------\n");

        printf("Computer_ID: ");
        scanf("%s", customer.Computer_ID);

        printf("\nInput time in military format (e.g., 1500 = 3:00PM)");
        printf("\nTime_In: ");
        scanf("%d", &customer.time_In);

        printf("Time_Out: ");
        scanf("%d", &customer.time_Out);

        if (customer.time_In > customer.time_Out) {
            printf("Invalid Input! Time in is later than time out.\n");
        } else {
            computation(customer.time_In, customer.time_Out);
        }

        printf("\n\nMonitor another computer user? (Y/N): ");
        scanf(" %c", &again);
        printf("\n-----------------------------------------------\n");

    } while (again == 'Y' || again == 'y');

    printf("\nThank you!\n");
    return 0;
}

void computation(int time_In, int time_Out) {
    int hr_In, min_In, hr_Out, min_Out;
    float hr_spent, min_spent, amount;
    const int per_hour = 12;

    hr_In = time_In / 100;
    min_In = time_In % 100;

    hr_Out = time_Out / 100;
    min_Out = time_Out % 100;

    // Validate hours and minutes
    if (hr_In < 0 || hr_In > 24 || min_In < 0 || min_In >= 60 ||
        hr_Out < 0 || hr_Out > 24 || min_Out < 0 || min_Out >= 60) {
        printf("Invalid time format!\n");
        return;
    }

    hr_spent = hr_Out - hr_In;
    min_spent = min_Out - min_In;

    // borrow 1 hour when minute becomes negative
    if (min_spent < 0) {
        hr_spent -= 1;
        min_spent += 60;
    }

    float min_spent_dec = min_spent / 60.0;
    amount = (hr_spent + min_spent_dec) * per_hour;

    printf("\nNumber of hours spent: %.0f hours and %.0f minutes", hr_spent, min_spent);
    printf("\nAmount to be paid: %.2f", amount);
}