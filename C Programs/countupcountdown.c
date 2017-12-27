#include<stdio.h>

int main(int argc, char **argv){

int ctr = 0;
int ctr1 = 5;
int num = 5;

/* increment */
printf("increment\n");
printf("____________\n");

for(int i = 0; i < 5; i++){

    ctr += num;
    printf("Counter is: %d\n", ctr);

}

printf("\n///////////////\n\n");


/*
   decrement;
   can also be
   done with a
   for loop
*/
printf("decrement\n");
printf("____________\n");

while(ctr1 > 0){

    ctr1 -= 1;
    printf("Counter is %d\n", ctr1+1);

}


return 0;

}
