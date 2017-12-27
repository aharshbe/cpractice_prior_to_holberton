#include<stdio.h>
#include<stdlib.h>

char yes_no;

int main(int argc, char **argv){

printf("Do you have a middle name? (Y/N)\n");
char yes_no = getchar();
char first, last, middle, n1, n2, n3;


switch(yes_no){

case('y'):
    printf("First: ");
    first = getchar();
    n1 = getchar();
    printf("Middle: ");
    middle = getchar();
    n2 = getchar();
    printf("Last: ");
    last = getchar();
    n3 = getchar();
    printf("%c.%c.%c.\n", n1, n2, n3);
    break;

case('Y'):
    printf("First: ");
    getchar();
    first = getchar();
    printf("Middle: ");
    getchar();
    middle = getchar();
    printf("Last: ");
    getchar();
    last = getchar();
    printf("%c.%c.%c.\n", first, middle, last);
    break;

case('n'):
    printf("First: ");
    getchar();
    first = getchar();
    printf("Last: ");
    getchar();
    last = getchar();
    printf("%c.%c.\n", first, last);
    break;

case('N'):
    printf("First: ");
    getchar();
    first = getchar();
    printf("Last: ");
    getchar();
    last = getchar();
    printf("%c.%c.\n", first, last);
    break;

default:
    printf("Please either choose, 'y' or 'n'.\n");
    break;


}

return 0;


}
