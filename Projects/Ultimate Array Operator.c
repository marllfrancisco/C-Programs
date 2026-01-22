// Ultimate Merger, Sort, and Search Program
// This program merges two arrays, allows searching (linear or binary),
// and sorting (bubble and selection) of the merged array.

#include <stdio.h>

int arrayN[5], arrayB[5], mergeArray[10], tryAgain, 
    arraySize = 0;

//This is for Merge Array Function
int isUnique (int arrVar){
    for (int i = 0; i < arraySize; i++){
        if (mergeArray[i] == arrVar){
            return 0;
        }
    }

    return 1;
}

void mainMerge(int arr[], int size){
    for (int i = 0; i < 5; i++){
        if (isUnique(arrayN[i])){
            mergeArray[arraySize] = arrayN[i];
            arraySize++;
        }
    }

    for (int i = 0; i < 5; i++){
        if (isUnique(arrayB[i])){
            mergeArray[arraySize] = arrayB[i];
            arraySize++;
        }
    }

    printf("\nMerged Array: \n");

    for (int i = 0; i < arraySize; i++){
        printf("%d  ", mergeArray[i]);
    }
}
//End of Merge Array Function
//--------------------------------------------------------
//This is for Search Array Function
void searchLinear(int arr[], int size) {
	int findValue, pos = -1, i;

	printf("\nEnter value to search: ");
	scanf("%d", &findValue);

	for (int i = 0; i < size; i++) {
		if (findValue == arr[i]) {
			pos = i + 1;
			break;
		}
	}

	if (pos == -1) {
		printf("\nValue not found.\n");
	} else {
		printf("\nValue found at position: %d\n", pos);
	}

    //sort to get the maximum and minimum values
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {  
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nThe minimum value is: %d", arr[0]);
    printf("\nThe maximum value is: %d\n", arr[size - 1]);
}

void searchBinary(int arr[], int size) {
	int search, first, middle, last;
    char sortConfirm;

    printf("\nBinary search requires a sorted array!\n");

        printf("\nDo you want to sort it?(y/n): ");
        scanf(" %c", &sortConfirm);

        if (sortConfirm == 'y' || sortConfirm == 'Y'){
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1 - i; j++) {
                    if (arr[j] > arr[j + 1]) {  // Swap only if needed
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            printf("\nSorted Array: \n");

            for (int i = 0; i < size; i++){
                printf("%d  ", arr[i]);
            }

            printf("\n");
        } else {
            printf("\nYou can proceed.\n");
        }

	printf("\nEnter the value to search: ");
	scanf("%d", &search);

	first = 0;
	last = size - 1;

	while (first <= last) {
		middle = (first + last) / 2;

		if (arr[middle] < search) {
			first = middle + 1;
		} else if (arr[middle] == search) {
			printf("\n%d is present at index %d.\n", search, middle);
            printf("\n%d is present at position %d in the array.\n", search, middle + 1);
			return;
		} else {
			last = middle - 1;
		}
	}

	printf("\nNot found! %d is not present in the list.\n", search);
}

void searchMain(int arr[], int size) {
	int pickSearch, pickLinearSearch;

	printf("\nPick the type of search (Linear - 1 / Binary - 2): ");
	scanf("%d", &pickSearch);

	if (pickSearch == 1) {
		searchLinear(mergeArray, arraySize);
	} else if (pickSearch == 2) {
		searchBinary(mergeArray, arraySize);
	} else {
		printf("\nInvalid Input.\n");
	}
}
//End of Search Array Function
//--------------------------------------------------------
//This is for Sort Array Function
void sortBubble(int arr[], int size) {
	int pickorder;
	
    printf("\nBubble Sorted Array\n");
    
    printf("\nPick the type of order (Ascending - 1 / Descending - 2): ");
    scanf("%d", &pickorder);

    if (pickorder == 1) {
        for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {  // Swap only if needed
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    } else if (pickorder == 2) {
        for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (arr[j] < arr[j + 1]) {  // Swap only if needed
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    } else {
        printf("\nInvalid Input.\n");
}

	for (int i = 0; i < size; i++) {
	        printf("%d  ", arr[i]);
	    }
	    printf("\n");
}

void sortSelection(int arr[], int size) {
    int position, pickorder;
    
	printf("\nSelection Sorted Array:\n");
    
    printf("\nPick the type of order (Ascending - 1 / Descending - 2): ");
    scanf("%d", &pickorder);

    if (pickorder == 1) {
        for (int i = 0; i < size - 1; i++) {
        position = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[position] > arr[j]) {
                position = j;
            }
        }

        if (position != i) {  // Swap only if needed
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }
        
    } else if (pickorder == 2) {
        for (int i = 0; i < size - 1; i++) {
        position = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[position] < arr[j]) {
                position = j;
            }
        }

        if (position != i) {  // Swap only if needed
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }
    } else {
        printf("\nInvalid Input.\n");
}

    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    
    printf("\n");
}

void sortMain(int arr[], int size) {
    int pickSort;

    printf("\nPick the type of sort (Bubble - 1 / Selection - 2): ");
    scanf("%d", &pickSort);

    if (pickSort == 1) {
        sortBubble(mergeArray, arraySize);
    } else if (pickSort == 2) {
        sortSelection(mergeArray, arraySize);
    } else {
        printf("\nInvalid Input.\n");
    }
    
}
//--------------------------------------------------------
//End of Sort Array Function
//--------------------------------------------------------
//Main Function
int main() {
    int seSo;
    char tryAgain;

        printf("\nEnter values for Array N:\n");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &arrayN[i]);
        }

        printf("\nEnter values for Array B:\n");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &arrayB[i]);
        }

        // Merge arrays before searching/sorting
        mainMerge(mergeArray, arraySize);
    
    do {
        printf("\n\nPick whether to SEARCH or SORT the array (SEARCH - 1 / SORT - 2): ");
        scanf("%d", &seSo);

        if (seSo == 1) {
            searchMain(mergeArray, arraySize);  // Assuming searchMain() operates on mainMerge
        } else if (seSo == 2) {
            sortMain(mergeArray, arraySize);
        } else {
            printf("Invalid Input.");
        }

        printf("\nDo you want to try again? (Y/N): ");
        scanf(" %c", &tryAgain);
    } while (tryAgain == 'Y' || tryAgain == 'y');

    printf("\nThank you for using our program!\n");

    return 0;
}