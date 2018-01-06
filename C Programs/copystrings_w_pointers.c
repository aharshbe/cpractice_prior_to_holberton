/*
	This program copies a string
	using pointers instead of
	regular arrays
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80

int main(int argc, char **argv){

	char *string, *string_copy;
	string_copy = string = malloc(MAX);

	printf("Pick a string to copy: ");
	gets(string); 

	/*
		can use gets but should probably
		use fgets():

		fgets(string, MAX, stdin)

		to avoid any warnings
	*/

	strcpy(string_copy, string);

	printf("string 1: %s \nstring 2: %s\n\n", string, string_copy);

	return 0;

}