/*
    This program creates a sequential
    file, and asks if the user would
    like to read, write or append text
    it then gives the user the option
    to repeate actions if they wish to
    view what they wrote or add more
    text
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define clear() printf("\033[H\033[J") //Defines clear function to keep things tighty


FILE *fptr; //Defines a file pointer
char text_entry[1000];

//function that verifies the pointer was created
void func(){

    if(!fptr){

        puts("Error--file could not be opened.");
        exit(1);

    }
}

int main(int argc, char **argv){

    char they_chose = 'y';
    char del;

    do{

        char rwa;
        clear();
        puts("What would you like to do? \nRead = 'r' \nWrite = 'w' \nAppend = 'a' \nDelete all text = 'd' \nQuit = 'q'");
        puts("****************************");

        scanf(" %c", &rwa);
        getchar();
        puts("****************************\n");


        switch(rwa){

        case('r'):
            fptr = fopen("./second_file.txt", "r");

            func();
             //Creates a file line variable
        char fileLine[100];

        //Make sure the file pointer is received, if so...
        if(fptr != 0){

             puts("\n***Start of file*****\n");

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

            puts("\n***End of file*****\n");

        }else{

            //Otherwise, print there was an error opening the file
            printf("\Error opening file.\n");

        }

            break;
        case('w'):
            fptr = fopen("./second_file.txt", "w");
            func();
            char text_entry[1000];
            puts("What would you like to write?\n");
            gets(text_entry);
            //Uses fprintf() to add text to the file using the file pointer, fptr
            fprintf(fptr, "%s\n", text_entry);
            puts(""); //Adding return to keep clean
            break;
        case('a'):
            fptr = fopen("./second_file.txt", "a");
            func();
            puts("What would you like to append?\n");
            gets(text_entry);
            //Uses fprintf() to add text to the file using the file pointer, fptr
            fprintf(fptr, "%s\n", text_entry);
            puts(""); //Adding return to keep clean
            break;
        case('d'):
            puts("!!WARNING!!\n\nAre you sure? You can't revcover it's contents later. (y/n)");
            scanf(" %c", &del);
            puts("");

            if(toupper(del == 'y')){

                 puts("Deleting file... (will exit when complete.)\n");
                 fptr = fopen("./second_file.txt", "w");
                 func();
                 fprintf(fptr, "");
                 printf("Text in dile: %s, deleted.\n", "second_file.txt");
                 puts("");
                 exit(0);

            }else if(toupper(del == 'n')){

                puts("No problem, your file will remain intact.\n");
                exit(0);

            }else{
                   puts("Please either enter 'y' for yes or 'n' for no and try again.");
                   exit(1);
            }
            break;
        case('q'):
            puts("Qutting...");
            exit(1);
        default:
            puts("Please either choose, 'r' for read, 'w' for write or 'a' for append.");
            break;

        }

        puts("Would you like to read, write or append another item to your file?");
        puts("****************************");

        scanf(" %c", &they_chose);

        if(they_chose == 'y'){

            they_chose = 'y';

        }else if(they_chose == 'n'){

            they_chose = 'n';

        }else{

            puts("Please either enter 'y' for yes or 'n' for no and try again.");
            exit(1);

        }

        //Closes the file after finishing adding text
        fclose(fptr);

    }while(they_chose != 'n');

    return 0;

}

