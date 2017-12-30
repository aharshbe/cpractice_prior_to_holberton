/*
    This program creates an actual
    random number that changes based
    on the current time of day vs.
    a randomly generated number based
    on the size of an int (32767)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(int argc, char **argv){

//To produce a totally random number you must use the current time
time_t t; //creates a new time object
srand(time(&t)); //uses srand (seed random number) passing in the current time's address in memory

printf("Here is a completely random number: %d.\n", (rand() % 5)+ 1); //by moding 5 and adding one it produces a number between 1 - 6

return 0;



}
