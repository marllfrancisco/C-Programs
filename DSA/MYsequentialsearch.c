#include<stdio.h>
#include<conio.h>

int main() { 
    int array[5], n, i=0, pos, check;

for( i=0; i <= 4; i++)
{ printf("Please enter 5 integer values");
  scanf("%d",&array[i]);
}
 pos=0;
 printf("Enter any value");
 scanf("%d", &n);
  
for(i=0; i <= 5; i++){ 
    if (n == array[i]) { 
        pos = i + 1;
        check = 1;
        printf("Value found position = %d", pos);
        break; } 
        if (pos==0) { printf("Value not found"); }
 } 
}
