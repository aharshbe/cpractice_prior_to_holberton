
/* This program implements binary search
   to search through a given array of
   int values
*/

#include<stdio.h>

int bin_search(int target, int middle, int data[32]){

	//Printing out current location of search
	printf("Middle is: %d, Target is: %d.\n", middle, target);

	//Iterating through search data
	for(int i = 0; i < sizeof(data) /  sizeof(int); i++){

		if(middle > target){

			--middle;
			printf("Middle > Target and is now: %d.\n", middle);
			bin_search(target, middle, data);

		}else if(middle < target){

			++middle;
			printf("Middle < Target and is now: %d.\n", middle);
			bin_search(target, middle, data);

		}else if(middle == target){

			printf("Target found, it is: %d.\n", target);

		}

	}
}

int main(int argc, char *argv[]){

	//Creating array of data to search through
	int data[] = {1, 2, 3, 4, 5, 6, 45, 46, 56, 57, 58, 60, 72, 75, 86, 90};

	//Creating variables
	int target = 46;
	int sizeofdata = sizeof(data) / sizeof(int);
	int middle = data[sizeofdata / 2];

	//Calling binary search method
	bin_search(target, middle, data);

	return 0;
}
