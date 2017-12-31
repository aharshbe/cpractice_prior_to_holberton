/*
    This program asks the user for
    a customer ID, it then searches
    for the ID in an array, and uses
    the corresponding element ID to
    access further data, in this case
    a customer balance, like for a credit
    card.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

//Creating data set
int customer_ID[] = { 234, 566, 7423, 23, 2, 75 };
float customer_BAL[] = { 94.56, 870.56, 16543.00, 234.00, 23.00, 0.00 };
int customer_lookup; //Defining lookup for later initialization
int found, counter = 0;

printf("What customer ID are you looking for? : ");
scanf(" %d", &customer_lookup); //Asking user for input

//Iterating through dataset to look for the given id.
for(counter = 0; counter < sizeof(customer_ID) / sizeof(int); counter++){

    //Checking to see if the ID entered matches and ID in the dataset
    if(customer_lookup == customer_ID[counter]){
        //If the data matches what was entered by the user
        printf("Customer found!\n");
        found = 1;
        break;

    }else{

        found = 0;

    }
}


if(found){
    //Match the found id's element with the element in balance array and print result
    printf("The customer owes, $%.2f\n", customer_BAL[counter]);

}else{
    //Prompt user that the id they entered was not found
    printf("------------------------------------\n");
    printf("\nAre you sure you entered the correct customer ID? Customer ID not found, try again.\n");

}

return 0;

}
