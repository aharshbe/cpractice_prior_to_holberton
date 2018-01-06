/*
	This program copies one 
	string into another
*/


#include<stdio.h>
#include<string.h>
#define MAX 80

void string_copy(char string[MAX]);

int main(int argc, char **argv){

	char string[MAX];
	printf("Enter a string you'd like to copy. : ");

	fgets(string, MAX, stdin);

	printf("*********************************\n");

	//Calling copy function
	string_copy(string);

	return 0;

}


void string_copy(char string[MAX]){

	char second_string[MAX];

	strcpy(second_string, string);

	printf("The second string was copied.\n");
	printf("*********************************\n");

	printf("The first string was: %s", string);
	printf("The second string is: %s\n", second_string);

}