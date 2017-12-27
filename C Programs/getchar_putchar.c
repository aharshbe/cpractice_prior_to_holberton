#include<stdio.h>
#include<stdlib.h>


int main(int argc, char **argv){

int i;

//Char array containing 80 bytes
char msg[25];
printf("Type up to 25 characters then press enter.\n");
//Iterating through array
for(i = 0; i < 25; i++){

    //Output a single character
    msg[i] = getchar();

    //Breaks loop if the user hits enter which is a new line character
    if(msg[i] == '\n'){

        //Prints out each character backwards then breaks out of the loop
        i--;
        break;

    }

}

//Printing a new line using putchar() function
putchar('\n');

for(; i >= 0; i--){

    putchar(msg[i]);
}

putchar('\n');

return 0;

}
