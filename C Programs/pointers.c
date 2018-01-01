#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char **argv){

/* Pointers to ints */

int age = 20;

int * pAge = &age; //This line creates a pointer to the age variable

printf("You are %d years old.\n", *pAge);


/* Pointers to strings */

char name[] = "Austin S. Harshberger";

/*
    Must be careful because the previous
    array was defined based on its contents
*/

strcpy(name, "Austin Shane Harshberger");

char * pName = &name;

//For pointers it's easier you can just re-assign without copying

pName = "Joan A. Black";

printf("Your name is %s.\n", pName); //You don't need an dereference like you do with numbers

return 0;

}
