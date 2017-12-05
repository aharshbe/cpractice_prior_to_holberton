#include<stdio.h>

int main(int argc, char* argv[]){

//How to count backwards using decrement
int i = 25;

while (i > 0){

	printf("%d", i);

	i--;
}

// need this to add a final newline
printf("\n");

//How to count forwards using increment
int j = 0;

while (j < 25){

	printf("%d", j);

	j++;
}

// need this to add a final newline
printf("\n");


//Create cool loop to print alphabet from the given letter
char c = 'C';

while (c <= 'Z'){

	printf("%c", c);
	c++;

}

printf("\n");


//Create cool loop to print alphabet from the given letter backwards
while (c >= 'C'){

	//Check to make sure the character is alphabetic
	if(isalpha(c)){
	
	printf("%c", c);
}
	c--;
}

printf("\n");


	return 0;
}