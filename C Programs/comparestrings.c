/*
	This program compares 
	two strings
*/


#include<stdio.h>
#include<string.h>
#define MAX 80

int main(int argc, char **argv){


	char name[MAX];
	char name_two[MAX];

	printf("What would you like to get for name? : ");
	fgets(name, MAX, stdin);

	printf("What would you like to get for name two? : ");
	fgets(name_two, MAX, stdin);


	if(strcmp(name, name_two) == 0){

		puts("They match.");

	}else{

		puts("They don't match");

	}

	return(0);
}