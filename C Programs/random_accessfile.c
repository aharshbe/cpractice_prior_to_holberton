#include<stdio.h>
#include<stdlib.h>

FILE * fptr;

int main(int argc, char **argv){


fptr = fopen("./alpha.txt", "w+");

char letter;

if(fptr == 0){

    puts("Error opening file.");
    exit(1);

}


for(letter = 'A'; letter <= 'Z'; letter++){


    fputc(letter, fptr);

}

puts("Just wrote the letters A through Z");


//Now reads the file backwards

for(int i = 26; i > 0; i--){

    letter = fgetc(fptr);
    //Reads a ltter, then backs up 2
    fseek(fptr, -2, SEEK_CUR);
    printf("The next letter is %c.\n", letter);

}

fclose(fptr);

return 0;

}
