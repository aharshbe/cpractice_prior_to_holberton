/*	
	This program uses pointer logic
	to print out all the characters
	in a given string
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv){

	char *string;
	/*
		Allocating memory to string,
		you can alternatively us malloc();
		but calloc() initialized at 0
		which is ideal for security and to 
		prevent overflows while malloc() doesn't
	*/
	string = calloc(80, sizeof(string));

	//Asking for input
	printf("Please choose a string to print: ");
	fgets(string, 80, stdin);


	//Just a check to make sure the string isn't NULL
	if(string == NULL){

		return 1;
	}

	/*
		If you use a comma after 
		declaring int i, you can 
		delcare another variable
	*/

	for(int i = 0, n = strlen(string); i < n; i++){

		printf("%c\n", *(string+i));
	}

	//Free mem allocation for string after program exits
	free(string);
	return 0;
}