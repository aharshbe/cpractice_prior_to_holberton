#include<stdio.h>
#include<stdlib.h>


int main(int argc, char **argv){

printf("What is your initials?\n");

printf("First name first initial: ");
int first_i = getch();
putch(first_i);
printf("\n");

printf("Last name first initial: ");
int last_i = getch();
putch(last_i);
printf("\n");

printf("Your initials are: ");
printf("\n");

putch(first_i);
printf(".");
putch(last_i);
printf(".");

return 0;

}
