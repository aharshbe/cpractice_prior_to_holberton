/*
    This program will output a random
    number from 0 32767
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char **argv){

int yes_no = 0;

/*
    Variables to produce different ranges
    int zero_to_ten = (rand() % 5) + 6);
    int zero_to_six = (rand() % 5) + 2);
*/

while(yes_no == 0){

    printf("Here is a random number between 0 and 32767: %d\n", rand());
    printf("Would you like another random number? (Y/N): ");
    yes_no = getch();
    putch(yes_no);
    printf("\n");
    printf("-------------\n");

    if(toupper(yes_no) == 'Y'){

        yes_no = 0;
        continue;

    }else if(toupper(yes_no) == 'N'){

        printf("Okay maybe next time.\n");
        yes_no = 1;
        break;

    }else{

        printf("-------------\n");
        printf("!!!! Please either enter (Y/N)\n");
        yes_no = 0;
        continue;

    }

}


return 0;


}
