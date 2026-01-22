#include <stdio.h>

int main()
{
   int c, first, last, mid, n, x, array[100];

   printf("Enter number of elements:\n");
   scanf("%d",&n); 
   printf("Enter %d integers:\n", n);
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]); 

   printf("Enter the value to find:\n");
   scanf("%d", &x);

   first = 0;
   last = n - 1;
   
   while (first <= last) {
    mid = (first+last)/2;
      if (array[mid] == x) {
        printf("%d is present at position %d.\n", x, mid+1);
        break;  } 
        
        else if (x > array[mid]) {
        first = mid + 1; }

      else {
         last = mid - 1; }
   }

   if (first > last)
      printf("Not found! %d is not present in the list.\n", x);
   return 0;  
}
