/*
This program calculates the total 
amount of money one is progjected to spend
on Christmas gifts.
*/

#include<stdio.h>
#define MAX_DATA 80

int main(void){

	//Declaring variables to be used
	int i = 0;
	int numfamily;
	float giftamount, total;
	char familymember[MAX_DATA];

	printf("How many family members do you have?: ");
	scanf("%d", &numfamily);

	for(i = 1; i < numfamily; i++){

		printf("What is the name of the %d family memeber?: ", i);
		scanf("%s", familymember);
		printf("How much do you plan on spending for %s?: ", familymember);
		scanf("%f", &giftamount);
		total = giftamount + total;
		printf("The total so far is: %.2f.\n", total);

	}

	printf("The total you will spend on gifts this year is: %.2f.\n", total);
	return 0;
}