#include <stdio.h>

int mergeArray[10], arraySize = 0;;
 
int uniqueValue(int arrayValue) {
	for(int i = 0; i < 5; i++){
		if (mergeArray[i] == arrayValue){
			return 0;    //return false
		}   
	}
	return 1;  //return true
}
	
void MERGE(int arrayN[], int arrayB[]) {	
	for (int i = 0; i < 5; i++){
		if (uniqueValue(arrayN[i])){
			mergeArray[arraySize] = arrayN[i];
			arraySize++;
		}
	}
	
	for (int i = 0; i < 5; i++){
		if (uniqueValue(arrayB[i])){
			mergeArray[arraySize] = arrayB[i];
			arraySize++;
		}
	}
}


int main(){
	int arrayN[5], arrayB[5];
	
	printf("Enter a value for Array N:\n");
		for(int i = 0; i < 5; i++){
			scanf("%d", &arrayN[i]);
	}
	
	printf("\nEnter a value for Array B:\n");
		for(int i = 0; i < 5; i++){
			scanf("%d", &arrayB[i]);
	}
	
	MERGE(arrayN, arrayB);

	printf("\n\nArray N: \n");
		for(int i = 0; i < 5; i++){
			printf("%d   ", arrayN[i]);
	}
	
	printf("\n\nArray B: \n");
		for(int i = 0; i < 5; i++){
			printf("%d   ", arrayB[i]);
	}	
	
	printf("\n\nMerged Array: \n");
		for(int i = 0; i < arraySize; i++){
			printf("%d   ", mergeArray[i]);
	}
	
	return 0;
}
