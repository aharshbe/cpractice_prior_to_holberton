/* This program implements binary search
   to search through a given array of
   int values
*/

#include<stdio.h>

//This method is where binary search is created

int binary_search(int current, int middle, int looking_for){

	current = middle;

	if(current == looking_for){

		printf("Found it.\n");

	}else if(looking_for > current){

		current = current + 1;
		binary_search(current, middle, looking_for);

	}else if(looking_for < current){

		current = current - 1;
		binary_search(current, middle, looking_for);

	}else{

		printf("The value you're looking for does not exist.\n");
	}
}

int main(int argc, char *argv[]){

	//Defining variables
	int numbers[] = {1, 2, 3, 4, 5, 6};

	int sizeofnumbers = sizeof(numbers) / sizeof(int);

	int middleindex = sizeofnumbers / 2;

	int middle = numbers[middleindex];

	int looking_for = 2;

	int current = 0;

	binary_search(current, middle, looking_for);

	return 0;

}
