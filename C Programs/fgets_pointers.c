#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){

char name[21]; //Need to be one greater than target to account for null terminator (string)

char * pName = name; //points to the first element in memory of the array vs. all elements

printf("What is your name? (can't be larger than 20 characters)\n : ");

fgets(pName, 21, stdin); //Asks user for input to fill pName but limits the input by 80 bytes as defined

//Checks to make sure the name entered is not greater than or = to 20
if(strlen(pName) >= 20){

    printf("\nTry again with no middle name, your name is too long.\n");

}else{

printf("Nice to meet you, %s (%d)\n", pName, strlen(pName));

}

return 0;

}
