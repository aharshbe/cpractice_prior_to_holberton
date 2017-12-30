/*
    This program was created to
    help me calculate expenses
    while in school
*/


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char **argv){

float rent, food, credit_cards, loans, other, total;
int choice, numb;
int yes_no = 0;
char yes_no_one = 'p';

while(yes_no == 0){

        printf("What would you like to add a new expense for? \n"
               "(1) Rent \n(2) Food \n(3) Credit Card \n(4) Loan \n(5) Other \n(6) Exit \n");

        scanf(" %d", &choice);

        switch(choice){

        case(1):
            printf("Rent: ");
            scanf(" %f", &rent);
            total += rent;
            break;
        case(2):
            printf("Food: ");
            scanf(" %f", &food);
            total += food;
            break;
        case(3):
            printf("How many credit cards do you have? : ");
            scanf(" %d", &numb);
            for(int i = 0; i < numb; i++){

                printf("Credit Card #%d monthly payment is: ", i+1);
                scanf(" %f", &credit_cards);
                total += credit_cards;

            }
            break;
        case(4):
          printf("How many loans do you have? : ");
            scanf(" %d", &numb);
            for(int i = 0; i < numb; i++){

                printf("Loan #%d monthly payment is: ", i+1);
                scanf(" %f", &loans);
                total += loans;

            }
            break;
        case(5):
            printf("Other: ");
            scanf(" %f", &other);
            total += other;
            break;
        case(6):
            printf("Exiting...");
            exit(1);
        default:
            printf("Please either enter 1, 2, 3, 4, 5.\n");
            break;
        }

        printf("The total is: $%.2f\n", total);


            printf("-------------------------------------------\n");
            printf("Would you like to add another expense? (Y/N) ");

            yes_no = getch();
            putch(yes_no);
            printf("\n");
            printf("-------------------------------------------\n");

            if(toupper(yes_no) == 'Y'){

                yes_no = 0;
                continue;

            }else if(toupper(yes_no) == 'N'){

                yes_no = 1;
                break;

            }else{

                printf("!! ERROR: Please either enter 'Y' or 'N'\n");
                yes_no_one = 'p';

            }
        }

printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>\n\n");
printf("The final TOTAL is: $%.2f.\n", total);

return 0;

}
