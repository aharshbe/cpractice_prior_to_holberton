/*
    This program will demonstrate
    an alternative to get strings
    from users without using scanf().
    The benefit also being that you can
    ask for input that contains spaces,
    such as a full name.
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 80


int main(int argc, char **argv){


char full_name[MAX];
char first_two[MAX];
char initializer;
int counter = 0;

printf("What is your full name? \nPlease correctly punctuate your first and last names)\n: ");
gets(full_name);
printf("------------------------------------\n");

puts(full_name);
printf("------------------------------------\n");

printf("Your full name is, %s.\n", full_name);
printf("------------------------------------\n");

for(int i = 0; i < strlen(full_name); i++){

    /* For testing */
    //printf("%c\n", full_name[i]);

    if(isupper(full_name[i])){

        /*
            This line stores the initializer variable
            as the element at index 0 of first_two
            it then assigns the element at index 0 to be
            the element at full_name resulting in the desired
            outcome
        */

        initializer = first_two[counter] = full_name[i];

        /* For testing */
        //printf("it's upper. [%c]\n", first_two[counter]);

        counter++;

    }

}

 /* For testing */
//printf("Counter is: %d.\n", counter);

//Prints out the initials based on the name they entered
printf("Your initials are: %c.%c.\n", first_two[0], first_two[1]);
return 0;


}
