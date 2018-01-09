/*
	OUTPUT:
	Size of data types in C on my machine:
	***************************************
	long: 8 bytes or 64 bits
	int: 4 bytes or 32 bits
	float: 4 bytes or 32 bits
	short: 2 bytes or 16 bits
	double: 8 bytes or 64 bits
*/

#include<stdio.h>

int main(int argc, char **argv){

    puts("Size of data types in C on my machine:");
    puts("***************************************");
    printf("long: %d bytes or %d bits\n", sizeof(long), sizeof(long)*8);
    printf("int: %d bytes or %d bits\n", sizeof(int), sizeof(int)*8);
    printf("float: %d bytes or %d bits\n", sizeof(float), sizeof(float)*8);
    printf("short: %d bytes or %d bits\n", sizeof(short), sizeof(short)*8);
    printf("double: %d bytes or %d bits\n", sizeof(double), sizeof(double)*8);

    return 0;

}
