#include<stdio.h>

//This is the same as ex11 except it is done using if-statement instead, I didn't complete because I prefer the switch-satement for this instance

int main(int argc, char *argv[]){

	if(argc != 2){

		printf("error, try again.\n\a");

		return 1;
	}

	char ch;


for (int i = 0; argv[1][i] != '\0'; i++){

	ch = argv[1][i];

	if (argv[1][i] == 'a'){

		printf("%c\n", ch);

	}else if (argv[1][i] == 'A'){
		
		printf("%c\n", ch);

	}else{

		printf("%c is not a vowel.\n", ch);
	}
}



	return 0; 
}