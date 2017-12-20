#include<stdio.h>

int main(void){


 int numbers[] = {1, 2, 3};


    for(int i = 0; numbers[i] != '\0'; i++){

        printf("%i\n", numbers[--i]);
    }





}
