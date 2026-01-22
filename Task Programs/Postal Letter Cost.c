// Determining cost of a postal letter by its weight and code
/* NOTES: 
	%.2f - print only up to two decimal places
	Utilized if, elif, and else statements
*/ 

#include <stdio.h>

int main (){
	float code, weig, cost;

	printf("Enter the weight of letter: ");
	scanf("%f", &weig);
	printf("Enter code of letter (1-ordinary, 2-special): ");
	scanf("%f", &code);

	if(code == 1 && weig <= 1){
		cost = 20;
		printf("\nThe cost is: Php. %.2f", cost); 
	}else if(code == 2 && weig <= 1){
		cost = 40;
		printf("\nThe cost is: Php. %.2f", cost);
	}else if(code == 1 && weig > 1){
		cost = 20 + 15;
		printf("\nThe cost is: Php. %.2f", cost);
	}else {
		cost = 20 + 25;
		printf("\nThe cost is: Php. %.2f", cost);
	}
	return 0;
}

