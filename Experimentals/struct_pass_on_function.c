// Observe how struct is passed on a function

#include<stdio.h>
#include<conio.h>

struct record //global template of structure record
{
     char name[30];
     int age;
};

void print_struct(struct record paramrec); //function prototype with structure as parameter

int main( )
     {
     struct record argrec;
     argrec.age = 23;
     print_struct(argrec); //function call passing structure argrec
     return 0;
}

void print_struct(struct record paramrec){
     printf("%d", paramrec.age); //prints 23 on the screen
}