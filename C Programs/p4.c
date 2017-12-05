#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>


//Setting up struct for a card

struct Card {

	long number;
	int exp_date;
	char *name_of_user;
	double bal;
	double amount_owed;
	char *issuer;
	char *bank;
	int cvv;
	char *type;
};

//Setting up function to create a new card

struct Card *New_Card(long number, int exp_date, char *name_of_user, 
						double bal, double amount_owed, char *issuer, 
						char *bank, int cvv, char *type){

	//Allocating memory to the New_Card object
	struct Card *new_card = malloc(sizeof(struct Card));

	//Checking to make sure the allocation is referencable
	assert(new_card != NULL);

	//Creating values
	new_card->number = number;
	new_card->exp_date = exp_date;
	new_card->name_of_user = strdup(name_of_user);
	new_card->bal = bal;
	new_card->amount_owed = amount_owed;
	new_card->issuer = strdup(issuer);
	new_card->bank = strdup(bank);
	new_card->cvv = cvv;
	new_card->type = strdup(type);

	return new_card;

}

//Setting up function to destroy card after it's done being used

void Destroy_Card(struct Card *new_card){

	//Make sure there is a new_card object to destroy
	assert(new_card != NULL);

	//Free up allocation space
	free((*new_card).name_of_user);
	free((*new_card).issuer);
	free((*new_card).bank);
	free((*new_card).type);
	free(new_card);

	//Print confirmation that new card memory can now be reallocation
	printf("************************************************\n");
	printf("Previous card memory can now be reallocated.\n");
	printf("************************************************\n");

}


//Setting up print function for card
void Print_Card(struct Card *new_card){

	printf("The card's number is: %ld.\n", (*new_card).number);
	printf("The card's expiraition date is: %d.\n", new_card->exp_date);
	printf("The name on the card is: %s.\n", new_card->name_of_user);
	printf("The card's balance is: %.2f.\n", (*new_card).bal);
	printf("The total currently owed on the card is: %.2f.\n", (*new_card).amount_owed);
	printf("The card's issuer is: %s.\n", new_card->issuer);
	printf("The card's bank is: %s.\n", (*new_card).bank);
	printf("The card's CVV is: %d.\n", new_card->cvv);
	printf("The card's type is: %s.\n", new_card->type);

}

//Creating main method
int main(int argc, char *argv[]){

	//Setting up new object
	struct Card *credit_card = New_Card(4564123498675456, 2018, "Austin S. Harshberger", 2346594.00, 845.98, 
										"AMEX", "USAA", 4556, "Credit Card");

	//Print out the credit card
	Print_Card(credit_card);

	//Destroy credit card
	Destroy_Card(credit_card);

	return 0;
}