//To understand STRING ARRAY and TWO DIMENSIONAL ARRAY

#include <stdio.h>

int main() {
    // Integer array 
    int it[3][3] = {
        {1, 2, 3}, //6
        {4, 5, 6}, //15
        {7, 8, 9} }; //24
    
    int cs[3] = {2, 4, 6};

    // String array 
    const char *basta[] = {"Hello", "World", "C Programming"};      //Need ng asterisk for the string variable

    // Calculate the number of elements in the string array
    int num_basta = sizeof(basta) / sizeof(basta[0]);

    printf("Size daw: %zu \n", sizeof(it));
    printf("Size daw: %zu \n", sizeof(cs));
    printf("Laki ng int: %zu bytes\n", sizeof(int));
    printf("Yung divide keme: %d \n", num_basta); 
    printf("Trial array: %d \n", it[2][0]);
    printf("String naman: %s \n", basta[0]);        // Manipulate these indexes para magets





/*
    // Print each element of the integer array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Integer Array Element [%d][%d]: %d\n", i, j, it[i][j]);
        }
    }

    // Print each element of the string array
    for (int i = 0; i < num_basta; i++) {
        printf("String %d: %s\n", i + 1, basta[i]);
    }
*/
    return 0;
}
