//Allocating memory from head

#include<stdio.h>
#include<stdlib.h>

int main(){

int * temp;

temp = (int *)malloc(10 * sizeof(int));

if(temp == 0){

    printf("Oops\n");

}else{

    puts("It worked.");

}

temp = 5;
printf("%d\n", temp);

return 0;


}
