#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*

	This program creates a car object
	which can be created singly or as
	a part of an iterated series of objects

*/

//Creating struct for car object

struct Car {

	char *name;
	double price;
	char *licence_plate;

};

//Creating make new car method

struct Car *New_Car(char *name, double price, char *licence_plate){

	//Allocating memory for car object
	struct Car *car = malloc(sizeof(struct Car));

	//Making sure memory was allocated
	assert(car != NULL);


	//Creating variable derefernce to struct
	(*car).name = strdup(name);
	(*car).price = price;
	(*car).licence_plate = strdup(licence_plate);

	//Returning car object
	return car;

}

//Creating destroy new car method

void Destroy_Car(struct Car *car){

	//Make sure there is a car to destroy
	assert(car != NULL);

	/*Freeing allocated memory of string variables
	because of strdup
	*/
	free((*car).name);
	free((*car).licence_plate);

	//Free allocated memory for car
	free(car);

	//Letting user know the car memory was deallocated
	printf("******\n");
	printf("Car memory deallocated at memory position: %p.\n", car);
	printf("******\n");

}

//Creating print method

void Print_Car(struct Car *car){

	//Printing out car information
	printf("The car name is: %s.\n", (*car).name);
	printf("The car price is: %.2f.\n", (*car).price);
	printf("The car licence plate is: %s.\n", (*car).licence_plate);

}

//Creating main method

int main(int argc, char *argv[]){

	//Creting new car object
	struct Car *my_car = New_Car("Ford, Pinto", 23005.97, "5FL56NP");

	//Printing car
	Print_Car(my_car);

	//Deallocating memory for car
	Destroy_Car(my_car);

	//Attempting to create an array of cars
	int i;

	for(i = 1; i < 5; i++){

		struct Car *my_car_i = New_Car("i_Car", i+2000, "iCarL");
		printf("New car %i created at space %p in memoery.\n", i, my_car_i);
		Print_Car(my_car_i);
		printf("****\n");
		/*
		  If the car is destroyed it's hard to tell
		  that a new car was created based on its
		  memory location.

		  Destroy_Car(my_car_i);
		*/
		
	}

	//Returning 0 to indicate no error
	return 0;

}