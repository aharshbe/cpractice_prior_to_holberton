/*
    This program reads a sequential
    file and then adds text to that file
    using "r" mode with fopen();
*/



#include<stdio.h>
#include<stdlib.h>


//Creates a file pointer
FILE * fptr;

int main(int argc, char **argv){

     //Opens the file for viewing
    fptr = fopen("./first_file.txt", "r");

    //Creates a file line variable
    char fileLine[100];

    //Make sure the file pointer is received, if so...
    if(fptr != 0){

        //While the end of the file (feof()) of the pointer isn't located...
        while(!feof(fptr)){

            //Get the line up to 100 characters in each line of the file pointer location
            fgets(fileLine, 100, fptr);

            //If the end of the file hasn't been seen...
            if(!feof(fptr)){

                //Print the line to stanard output (the screen)
                puts(fileLine);

            }

        }

    }else{

        //Otherwise, print there was an error opening the file
        printf("\Error opening file.\n");

    }


    return(0);

}
