#include <stdio.h>
#include <string.h>
#include <ctype.h>    // Needed for character classification functions
#include <math.h>     // For abs(), floor(), ceil(), pow(), fmod(), sqrt(), fabs()
#include <stdlib.h>   // For atoi()

int main() {
    char first[20], second[15];
    char third[20] = "God Loves U";
    char fourth[20] = "GOD BLESS U";

    // a. strrev(fourth)
    strrev(fourth);
    printf("a. strrev(fourth): %s\n", fourth);

    // b. strupr(third)
    strupr(third);
    printf("b. strupr(third): %s\n", third);

    // c. strncat(fourth, third, 5)
    strncat(fourth, third, 5);
    printf("c. strncat(fourth, third, 5): %s\n", fourth);

    // d. strlwr(fourth)
    strlwr(fourth);
    printf("d. strlwr(fourth): %s\n", fourth);

    // e. strncpy(first, fourth, 5)
    strncpy(first, fourth, 5);
    first[5] = '\0'; // Manually add null terminator
    printf("e. strncpy(first, fourth, 5): %s\n", first);

    // f. strcpy(second, third)
    strcpy(second, third);
    printf("f. strcpy(second, third): %s\n", second);

    // g. strlen(third)
    printf("g. strlen(third): %lu\n", strlen(third));

    // h. strncat(third, fourth, 4)
    strncat(third, fourth, 4);
    printf("h. strncat(third, fourth, 4): %s\n", third);

    // i. strlen(third)
    printf("i. strlen(third): %lu\n", strlen(third));

    // j. strncpy(first, third, 3)
    strncpy(first, third, 3);
    first[3] = '\0'; // Manually add null terminator
    printf("j. strncpy(first, third, 3): %s\n", first);

    char c = 'C', m = '?', i = 't', b = '5';

    printf("a. isdigit(b): %s\n", isdigit(b) ? "TRUE" : "FALSE");
    printf("b. isalpha(c): %s\n", isalpha(c) ? "TRUE" : "FALSE");
    printf("c. isspace(m): %s\n", isspace(m) ? "FALSE" : "FALSE");
    printf("d. isupper(c): %s\n", isupper(c) ? "TRUE" : "FALSE");
    printf("e. isalnum(b): %s\n", isalnum(b) ? "TRUE" : "FALSE");
    printf("f. ispunct(m): %s\n", ispunct(m) ? "TRUE" : "FALSE");
    printf("g. islower(i): %s\n", islower(i) ? "TRUE" : "FALSE");
    printf("h. isdigit(c): %s\n", isdigit(c) ? "TRUE" : "FALSE");
    printf("i. isalpha(b): %s\n", isalpha(b) ? "TRUE" : "FALSE");
    printf("j. isalnum(i): %s\n", isalnum(i) ? "TRUE" : "FALSE");

    printf("a. abs(5): %d\n", abs(5));
    printf("b. floor(5.5): %.1f\n", floor(5.5));
    printf("c. ceil(5): %.1f\n", ceil(5));
    printf("d. fmod(pow(7,2),2): %.1f\n", fmod(pow(7,2),2));
    printf("e. sqrt(floor(49.12)): %.1f\n", sqrt(floor(49.12)));
    printf("f. fabs(pow(9,2)): %.1f\n", fabs(pow(9,2)));
    printf("g. atoi(\"451\"): %d\n", atoi("451"));
    printf("h. ceil(pow(5,3)): %.1f\n", ceil(pow(5,3)));
    printf("i. fabs(-44.98): %.2f\n", fabs(-44.98));
    printf("j. ceil(fmod(5,15)): %.1f\n", ceil(fmod(5,15)));

    return 0;
}

