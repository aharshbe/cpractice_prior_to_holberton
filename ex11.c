#include<stdio.h>

int main(int argc, char *argv[]){


	int numbers[4] = { 0 };
	char name[7] = { 'a' };

	printf("numbers: %d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name: %c, %c, %c, %c\n", name[0], name[1], name[2], name[3]);
	printf("name as string: %s\n", name);

	//Set-up numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	//set up the name
	name[0] = 'A';
	name[1] = 'u';
	name[2] = 's';
	name[3] = 't';
	name[4] = 'i';
	name[5] = 'n';
	name[6] = '\0';

	//Print out each again but now intialized	
	printf("numbers: %d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name: %c, %c, %c, %c, %c, %c, %c\n", name[0], name[1], name[2], name[3], name[4], name[5], name[6]);
	printf("name as string: %s\n", name);

	//Another way to use name
	char *another = "Austin\n";
	printf("another: %s", another);

	//Attempting extra credit?

	/*This (below) for some reason prints the reverse result? Not sure how?*/

	long long austin = 'AUST';
	printf("%lld\n", austin);

	char *arr_austin = austin;
	printf("%s\n", &arr_austin);

	return 0;









	return 0;
}