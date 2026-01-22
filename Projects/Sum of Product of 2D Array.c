#include <stdio.h>

int main(){
	int ARRAY_A[3], ARRAY_B[3][3], ARRAY_C[3] = {0};
	
	printf("Enter a 3 numbers: \n");
		for(int i = 0; i < 3; i++){
			scanf("%d", &ARRAY_A[i]);
		}
	
	printf("Enter a 9 number: \n");
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				scanf("%d", &ARRAY_B[i][j]);
			}
		}
	
	printf("\nARRAY_A\n");
		for(int i = 0; i < 3; i++){
			printf("%d  ", ARRAY_A[i]);
		}
	
	printf("\n\nARRAY_B\n");
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				printf("%d  ", ARRAY_B[i][j]);
			}
		}
	
	
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			ARRAY_C[i] += (ARRAY_A[j] * ARRAY_B[i][j]);
		}
	}
	
	printf("\n\nResult: ARRAY_C\n");
		for(int i = 0; i < 3; i++){
			printf("%d ", ARRAY_C[i]);
		}
	
	return 0; 
}