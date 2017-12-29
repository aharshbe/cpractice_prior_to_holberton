/*
    This program prompts the user to create
    a username and password. The password must
    contain a capital letter, lower case letter
    a number and a symbol to be valid. If the
    password is not valid, the user is prompted if
    they would like to try again.
*/


#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define DATA_LIMIT 25

int main(int argc,  char **argv){

char user[DATA_LIMIT], password[DATA_LIMIT];
int hasUpper, hasLower, hasDigit, hasPunc, isTrue, yes_no;

//Initially sets each variable to check true or false, i.e., 0 (false) or 1 (true) to false.
hasUpper = hasLower = hasDigit = hasPunc = 0;


do{

        printf("Please enter a username: ");
        scanf(" %s", user);
        printf("---------------------------------------------------\n");
        printf("**Suggestion, stronger passwords contain upper case, lower case and number values.\n");
        printf("---------------------------------------------------\n");
        printf("Please enter a password: ");
        scanf(" %s", password);
        printf("---------------------------------------------------\n");

        //Iterates through the password string to make sure there is...
        for(int i = 0; i < strlen(password); i++){

                //A digit i.e., 0-9
                if(isdigit(password[i])){
                    //change to true is there is a digit
                    hasDigit = 1;
                    //re-check for other constraints
                    continue;
                }

                //An upper case letter i.e., A-Z
                if(isupper(password[i])){

                    hasUpper = 1;
                    continue;
                }

                //A lower case letter i.e., a-z
                if(islower(password[i])){

                    hasLower = 1;
                    continue;
                }

                //A symbol character i.e., !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
                if(ispunct(password[i])){

                    hasPunc = 1;
                }

        }

        //Checks to make sure each constraint is marked true
        if(hasDigit && hasUpper && hasLower && hasPunc == 1){

            printf("Congratulations, %s your password passes muster.\n", user);
            isTrue = 1;

        }else{

            printf("\nConsider using a strong password that contains a capital letter, lower case letter, a number and a symbol. \n\n e.g., !\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ \n");
            printf("---------------------------------------------------\n");

            printf("Would you like to try again? (Y/N) ");
            yes_no = getch();
            putch(yes_no);
            printf("\n");

            if(yes_no == 'y' || yes_no == 'Y'){

                //Resetting all functions
                isTrue = hasUpper = hasLower = hasDigit = hasPunc = 0;

            }else if(yes_no == 'n' || yes_no == 'N'){

                printf("Okay, no problem.\n");
                isTrue = 1;

            }else{

                //Resetting all functions
                isTrue = hasUpper = hasLower = hasDigit = hasPunc = 0;

                printf("Please either enter y/n.\n\a");

            }


        }

        printf("---------------------------------------------------\n");

        printf("Your username is: %s\n", user);
        printf("Your password is: %s\n", password);

        printf("\n---------------------------------------------------\n");


}while(isTrue == 0);

return 0;


}
