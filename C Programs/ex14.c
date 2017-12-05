#include<stdio.h>
#include<ctype.h>

//Example of forward declaration of a function but not actually creating one yet
int can_print_it(char ch);
void print_letters(char arg[]);

//Example of both declaring and creating the function
void print_arguments(int argc, char *argv[]){

	int i = 0;

	for (i = 1; i < argc; i++){
		print_letters(argv[i]);
	}
}

//Another example
void print_letters(char arg[]){

	int i = 0;

	for (i = 0; arg[i] != '\0'; i++){
		
		char ch = arg[i];

		if (can_print_it(ch)){

			printf("'%c' == %d", ch, ch);
		}
	}

	printf("\n");
}

//Another example
int can_print_it(char ch){

	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[]){

	//Invoking a method by providing given arguments
	print_arguments(argc, argv);

	return 0;
}