/*MILITARY TIME
GROUP 2 | BSIT 1-1
Cruz, Francisco, Magday */
#include <stdio.h>

int MILITARY_TIME(int mtime) {
    int hrs = mtime / 100;
    int min = mtime % 100;
    
    if (hrs == 0) return 12;
    if (hrs > 12) return hrs - 12;
    return hrs;
}

int main() {
    int mtime;
    do {
        printf("Military Time Input (ex 2000): ");
        scanf("%d", &mtime);
    } while (mtime < 0 || mtime > 2359 || (mtime % 100) > 59);
    
    int hrs_12 = MILITARY_TIME(mtime);
    int min = mtime % 100;
    
    if (mtime >= 1200) {
        printf("\nIt is %d:%02d PM\n", hrs_12, min);
    } else {
        printf("\nIt is %d:%02d AM\n", hrs_12, min);
    }
    
    return 0;
}