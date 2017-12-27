#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

//Ask the user for a selection
printf("What would you like to see? Please select a number below.\n");
printf("(1) Harry Potter Movies\n");
printf("(2) Lord of the Rings Movies\n");
printf("(3) Star Wars Movies\n");
printf("(4) Twilight Movies\n");
printf("(5) Quit\n");

int their_choice;

do{
    printf("What is your choice?: ");
    scanf("%d", &their_choice);

    switch(their_choice){

        case(1):
            printf("You chose Harry Potter Movies\n");
            break;
        case(2):
            printf("You chose Lord of the Rings Movies, not as good of a choice.\n");
            break;
        case(3):
            printf("You chose Star wards movies, meh.\n");
            break;
        case(4):
            printf("You chose Twilight Movies, that is for sure the next best from Harry Potter.\n");
            break;
        case(5):
            exit(1);
        default:
            printf("Please choose one of the given options, 1, 2, 3, 4, or 5 to quit.\n");
            break;

    }
//Continues the loop if one of the given choices is not chosen.
}while (their_choice < 1 || their_choice > 5);

return 0;

}
