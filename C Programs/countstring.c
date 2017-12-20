/* This proram will count the number of
   characters in a given string.
*/


#include<stdio.h>
#define MAX_DATA 80

int main(int argc, char *argv[]){

	//Creating placeholder for string
	char string[MAX_DATA];
	printf("Please enter a word/string below.\n");
	printf("_: ");
	scanf("%s", string);

	int i = 0;

	while(string[i] != '\0'){

		i++;
	}

	printf("There are %d characters in %s.\n", i, string);

	return 0;

}

