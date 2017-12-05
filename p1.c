#include<stdio.h>
//Have to include ctype.h in order to use ialpha function
#include<ctype.h>


//Creating a  foward declartion for method to print out any given characters ACII notation
void ascii_translation(char ch);

//Creating a function which will return the ASCII symbol for any given array of characters passed
void ascii_translation_arr(char *ch_arr){



	for(int i = 0; i < sizeof(ch_arr) / sizeof(char); i++){

		if(isalpha(ch_arr[i])){

			printf("The ASCII symbol for %c is %i\n", ch_arr[i], ch_arr[i]);
		}
	}
}

//Creating a function which takes in the argc and argv variables to print out i.e., use any args passed at runtime
void take_args(int argc_1, char *argv_1[]);

int main(int argc, char *argv[]){

	//This is how you make all the main data types 
	short zero = 0;
	int one = 0;
	float two = 0.0;
	double three = 0.0;
	long four = 0;
	long long five = 0000000000000000;
	char first_initial = 'A';
	int phone_number[] = { 9, 0, 9, 7, 0, 3, 9, 5, 5, 7 };
	char name[] = {'A', 'u', 's', 't', 'i', 'n', '\0'};
	long phone_numbers[] = {9097039557, 9518054434, 9518059211};
	char *full_name[] = {"Austin", "Shane", "Harshberger"};

	//Printing out each data type
	printf("short is: %i and it is size: %i\n", zero, sizeof(zero));
	printf("int is: %i and it is size: %i\n", one, sizeof(one));
	printf("float is: %f and it is size: %i\n", two, sizeof(two));
	printf("double is: %f and it is size: %i\n", three, sizeof(three));
	printf("long is: %lld and it is size: %i\n", four, sizeof(four));
	printf("long long is: %ld and it is size: %i\n", five, sizeof(five));
	printf("A sigle char is: %c and it is size: %i\n", first_initial, sizeof(first_initial));
	//For the int array you have to print out each number using its index but I don't feel like doing so right now
	printf("int array is: %i and it is size: %i\n", phone_number[0], sizeof(phone_number));
	printf("char array or string is: %s and it is size: %i\n", name, sizeof(name));
	printf("phone numberes long array is: phone number 1: %ld phone number 2: %ld phone number 3: %ld and it is size: %i\n", phone_numbers[0], phone_numbers[1], phone_numbers[2], sizeof(phone_numbers));
	printf("Two dimentional char array is: %s %s. %s and it is size: %i\n", full_name[0], full_name[1], full_name[2], sizeof(full_name));

	//Pointer to each
	int *p_zero = zero;
	int *p_one = one;
	char *p_name = name;
	long* p_numebrs = phone_numbers;
	char* *p_full_name = full_name;

	//Printing out pointers
	printf("pointer to short is: %i and it is size: %i\n", p_zero, sizeof(p_zero));
	printf("pointer to int is: %i and it is size: %i\n", p_one, sizeof(p_one));
	printf("pointer to name is: %s and it is size: %i\n", p_name, sizeof(p_name));
	printf("pointer to numbers is: %ld and it is size: %i\n", p_numebrs[0], sizeof(p_numebrs));
	printf("pointer to ful name is: %s %s. %s and it is size: %i\n", p_full_name[0], p_full_name[1], p_full_name[2] , sizeof(p_full_name));

	//Make a for loop that iterates over the full name array and prints out all the elements
	for (int i = 0; i < sizeof(full_name) / sizeof(full_name[0]); ++i){

		printf("Index %i is: %s\n", i, full_name[i]);

	}

	//Iterate over phone number array to print the number all at once

	printf("Full phone number is: ");
	
	for(int i = 0; i < sizeof(phone_number) / sizeof(int); i++){

		printf("%i", phone_number[i]);
	}

	printf("\n");

	//Make a loop that iterates over numbers and prints out each number
	for(int i = 0; i < sizeof(phone_numbers) / sizeof(long); i++){

		printf("Index %i is: %ld\n", i, phone_numbers[i]);
	}

	//Calling the ASCII identifier function
	ascii_translation('a');

	//Calling the ASCII identifier function for arrays and passing in 'name'
	ascii_translation_arr(name);

	//Calling take args function
	take_args(argc, argv);

	
	return 0;

}

//Delcaring what the function does
void ascii_translation(char ch){

	if(isalpha(ch)){

		printf("The ASCII symbol for %c is: %i\n", ch, ch);
	}
}

//Delcaraing what the arg taker function does
void take_args(int argc_1, char *argv_1[]){

	if(argc_1 >= 1){

		for(int i = 1; i < argc_1; i++){

			printf("Arg %i is: %s\n", i, argv_1[i]);
		}
	}else {

		printf("Please enter more than one arg at runtime.\n\a");
	}
}