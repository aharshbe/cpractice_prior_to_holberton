#include<stdio.h>
#include<stdlib.h>


FILE * fptr;

int main(int argc, char **argv){


char letter;
int i;

fptr = fopen("./alpha.txt", "r+");

if(fptr == 0){

    puts("Error opening file.");
    exit(1);

}

printf("Which # letter would you like to change (1-26)? ");

scanf(" %d", &i);

//Seeks that position from the beginning of the file
fseek(fptr, (i-1), SEEK_SET); //Subtract one from position because array starts at 0

//Write an * over the letter in that position
fputc('*', fptr);

//Now jump to the beginning of the array and print it out

fseek(fptr, 0, SEEK_SET);
printf("Here is the file now:\n");

for(i = 0; i < 26; i++){

letter = fgetc(fptr);
printf("The next letter is %c\n", letter);


}

fclose(fptr);

return 0;




}
