#include<stdio.h>

int main(int argc, char *argv[]){


int numb;

printf("How many beads would you like?");

scanf(" %d", &numb);

printf("Ahh, I see, you'd like %d bead%s", numb, numb <= 1 ? "" : "s");

return 0;



}
