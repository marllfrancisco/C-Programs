// My Pal's Birthday
// struct of struct - struct inside a struct

#include<stdio.h>
#include<conio.h>

int main( ) {

     struct date
     {
          int month, day, year;
     };

     struct record
     {
          char name[30];
          int age;
          struct date bdate;
     };

     struct record mypal;

     printf("Enter name: ");
     scanf(" %[^\n]", mypal.name); // no need for &

     printf("Enter age: ");
     scanf("%d", &mypal.age);

     printf("Enter birthdate month in number: ");
     scanf("%d",&mypal.bdate.month);

     printf("Enter birthdate day in number: ");
     scanf("%d",&mypal.bdate.day);

     printf("Enter birthdate year in number: ");
     scanf("%d",&mypal.bdate.year); 

     printf("\nHello %s!\n", mypal.name);
     printf("Your birthday is on %d-%d-%d!\n",mypal.bdate.month, mypal.bdate.day, mypal.bdate.year);
     printf("Wow you’ll be %d soon!", mypal.age+1);

     return 0;
}
