/*
	This program swaps
	two numbers of the
	users choice
*/

#include<stdio.h>

//Prototyping function
void swap(int *one, int *two);

int main(int argc, char **argv){

	//Creating save functions for later
	int number1 = 0;
	int number2 = 0;

	//Asking user for input
	printf("\nPick a number: ");
	scanf(" %i", &number1);
	printf("Pick another number: ");
	scanf(" %i", &number2);

	//Calling swap function
	swap(number1, number2);

	return 0;

}

//Declaring swap function
void swap(int *one, int *two){

	int o = one;
	int t = two;

	/*
		Initializing tmp variable to 
		one's original value and then
		swap them
	*/
	
	int tmp = one;
	one = two;
	two = tmp;

		puts("\n*******Swapped********\n");


	printf("One was %i and is now %i\nTwo was %i and is now %i\n\n", o, one, t, two);

}