/*
    This program creates a sequential
    file and then adds text to that file
    using fprintf();
*/


#include<stdio.h>
#include<stdlib.h>

FILE *fptr; //Defines a file pointer


int main(int argc, char **argv){

    //Creates a directory to store the file and notates the "write" mode
    fptr = fopen("./first_file.txt", "w");

    //Verifies the pointer was created
    if(!fptr){

        puts("Error--file could not be opened.");
        exit(1);

    }

    //Uses fprintf() to add text to the file using the file pointer, fptr
    fprintf(fptr, "This is the first line of text I've writted to a sequential file using C.\n");



    //Closes the file after finishing adding text
    fclose(fptr);

    return 0;

}
