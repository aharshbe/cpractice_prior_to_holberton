#include<stdio.h>
#include<string.h>

/*

I've got an array and it's called 'animals'.

char *animals = {"Walrus", "Lion", "Monkey"};


In order for C to create this notion of an array, it creates a memory address which points to the first
item in the 'array', which in this case is the letter 'W' in 'Walrus', since I created a two dimentional array
Walrus is actually just an 'array' of characters which are actually just numbers to c. 

You can easily print out an element in an array by accessing its index, which is just the difference between
the first item in the array and the given element. For exmaple:

If I want to access, 'Lion', I would type:

printf("%s\n", animals[1]) which is the same as saying, go find the address where the first string 'Walrus' is stored, then add one to the address in memeory to return 'Lion', which is what I'm looking for. Then since I'm using the print function, please display it to standard output.

Another abstraction on this notion of arrays is pointers. Pointer point to the actual address in memory that the given variable represents. For example:

If I created a point to Lion by typing: *pointer_lion = animals[1]; I could then just tell the computer to print 'pointer_lion' and out it comes.

*/

int main(int argc, char *argv[]){

	//Creating an array
	char *animals[] = {"Walrus", "Lion", "Monkey"};

	//Printing out 'Lion' from the array using its index.
	printf("%s\n", animals[1]);

	//Printing out the memory address for animals
	printf("%p\n", &animals);

	//Print out lion again using the value of the address animal in memory plus the number of char in Walrum + a space
	printf("%s\n", *animals+7);

	//Print out Monkey
	printf("%s\n", *animals+12);

	//Creating a point to lion
	char *pointer_lion = animals[1];

	//Printing pointer aka Lion
	printf("%s\n", pointer_lion);

	int storing_size_of_lion_space = strlen(animals[1]) + 1;

	printf("%i\n",storing_size_of_lion_space);

	//Printing pointer + size of lion and space to get Monkey
	printf("%s\n", pointer_lion+storing_size_of_lion_space);

	return 0;
 }