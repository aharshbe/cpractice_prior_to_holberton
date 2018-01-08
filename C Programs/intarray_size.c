/*
    This program calculates the size of
    an int array without using the sizeof()
    function.
*/


#include<stdio.h>
#include<stdlib.h>

struct int_arr{

    int number;
    int size;

}intarr;

int main(int argc, char **argv){

int y_n = 'N';

do{

    printf("Pick a number: ");
    scanf(" %d", &intarr.number);
    printf("Add another? (y/n): ");

    scanf(" %c", &y_n);
    toupper(y_n);

    ++intarr.size;


}while(y_n != 'n');


printf("The size of the intarr array is %d\n", intarr.size);


return(0);


}
