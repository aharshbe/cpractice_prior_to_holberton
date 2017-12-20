/* This program implements a
   linear search algorithm to
   find the largest number
 */

#include<stdio.h>
#include<string.h>
#include<time.h> //for clock function to time algorithm
#define MAX_DATA 80

int main(int argc, char *argv[]){

	int starting[MAX_DATA];
	int numberof, choice;

	//Creating variables for clock function
	clock_t start, end;
	double cpu_time_used;

	printf("How many numbers would you like to enter? :_ ");
	scanf("%d" , &numberof);
	printf("Great, you chose, %d numbers. Now let's enter them.\n", numberof);

	for(int i = 0; i < numberof; i++){

		printf("Please enter a number: ");
		scanf("%d", &choice);
		starting[i] = choice;
	}

	for(int j = 0; j < numberof; j++){

		if(starting[j] != '\0'){
			
			printf("Number at index %d is: %d.\n", j, starting[j]);

		}else{

			printf("%d.", starting[j]);

		}
	}

	//Find the largest number.

	int l, k;

	l = 0;

	for(k = 0; k < numberof; k++){

		start = clock();

		if(starting[k] > starting[l]){

			l = k;

		}else{

		printf("Still looking ...\n");

		}

		end = clock();
	
	}

	printf("Largest is: %d.\n", starting[l]);

	//Calculates the time used and prints it out
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time used: %fs.\n", cpu_time_used);

	return 0;
			
}