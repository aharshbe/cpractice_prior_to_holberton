#include<stdio.h>

int main(int argc, char *argv[]){

	//Create two arrays that we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John",
		"Lisa"
	};

	//Safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//First way using index
	for(i = 0; i < count; i++){

		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	//Set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	//Second way using pointers
	for (i = 0; i < count; i++){

		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));

	}

	printf("---\n");
	
//Third way, pointers and just arrays
	for(i = 0; i < count; i++){

		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);

	}

	printf("---\n");

	//Fourth way with pointers in a stupid comlex way
	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++){

		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
		
	}

	return 0;
}