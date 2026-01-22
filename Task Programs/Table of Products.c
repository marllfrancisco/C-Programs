// Multiplication Table Determinator
// Entering num then printing all its product mul times
/* NOTES:
	for loop - has index variable
	do-while loop - conditional, returns to do{ when while (1)
*/

#include <stdio.h>

main (void) {
	//declarations
	int x, num, mul, pro, again;
	
	//input
	do{
	    printf("Welcome to MTD (Multipication Table Determinator)\n\n");	//add a space
		printf("Enter the number we want to multiply: ");	//no need to put \n
		scanf("%d", &num);
		printf("Enter how many times we had to multiply: ");
		scanf("%d", &mul);
	
	//process, output
		for(x=1; x<=mul; x++){	//x - starting point, mul - ending point
			pro = num * x; 	//x gradually increases by 1 'coz of x++
			printf("%d * %d = %d\n", num, x, pro); 	
			}
		
	//choice process
		printf("Do you want to try again? (Yes-1, No-0): ");
		scanf("%d", &again);
		
	}while(again == 1);	//returns to the do{
	printf("Program Done!");	//last statement
		
	return 0;
}
