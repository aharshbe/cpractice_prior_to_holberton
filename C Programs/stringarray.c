/*
    This program creates an array of
    strings using pointers. It requests
    a number of names from the user and
    then prints them out.
*/


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

//Creates a matrix that holds up to 80 characters and up to 20 names
char * name[80][20];
int num;

printf("How many names would you like to enter? : ");
scanf(" %d", &num);

//Flushes stdin so that scanf doesn't interrupt gets.
fflush(stdin);

for(int i = 0; i < num; i++){

    printf("Enter a name for position %d: ", i+1);
    gets(name[i]);

}

printf("-------------------\n");

for(int i = 0; i < num; i++){

    printf("Name at %d is: %s.\n", i+1, name[i]);

}

return 0;



}
