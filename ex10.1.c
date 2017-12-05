#include<stdio.h>
#include<string.h>
//Must include string.h if you want to use strlen()

int main(int argc, char *argv[]){

if (argc != 2){

	printf("Please input at least one other arguement.\n\a");
	return 1;
}

char ch;

//Checks to see if the null terminator is present, could also be achieved by using strlen()
for (int i = 0, z = 10; argv[1][i] !='\0'; i++){

	ch = argv[1][i];


	switch(ch){


		case 'A':
		//Switching from upper to lower using ASCII math (there's a bug with capital A that I can't work out)
		printf("making lowercase: %c\n", ch + 32);
		case 'a':
		printf("making uppercase: %c\n", ch - 32);
		break;

		case 'E':
		printf("making lowercase: %c\n", ch + 32);
		case 'e':
		printf("%c\n", ch);
		break;

		case 'I':
		case 'i':
		printf("%c\n", ch);
		break;

		case 'O':
		case 'o':
		printf("%c\n", ch);
		break;

		case 'U':
		case 'u':
		printf("%c\n", ch);
		break;

		case 'Y':
		case 'y':
		if (i > 2){

		printf("%c\n", ch);
		
	}else {

		printf("%c is not a vowel in this case.\n", ch);
	}
		break;

		default:
		printf("%c is not a vowel.\n", ch);

	}

//Shows that you can declar multiple int variables in a single loop
printf("%d\n", z);

}




	return 0;
}