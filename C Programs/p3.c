#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>


//Creting struct for toy
struct Toy {

	float price;
	char *name;
	bool paid_w;
};

//Creating create function
struct Toy *New_Toy(float price, char *name, bool paid_w){

	struct Toy *item1 = malloc(sizeof(struct Toy));

	assert(item1 != NULL);

	item1->price = price;
	item1->name = strdup(name);
	item1->paid_w = paid_w;

	return item1;
}

//Creating destroy method
void Destroy_Toy(struct Toy *item1){

	assert(item1 != NULL);
	
	free(item1->name);
	free(item1);

	printf("Toy destroyed.\n\a");
}

//Creating print method
void Print_Toy(struct Toy *item1){

	printf("The toys's name is: %s.\n", item1->name);
	printf("The toy costed a total of $%.2f\n", item1->price);
	printf("The buyer paid with cash: %s.\n", item1->paid_w?"True":"False");
}


//Creating main method
int main(int argc, char *argv[]){

	//Creating a new toy object
	struct Toy *new_toy = New_Toy(50.99, "Little Boe Peep", 0); 
	//Printing out the toy
	Print_Toy(new_toy);
	//Destroy toy
	Destroy_Toy(new_toy);

	return 0;
}