/*
    This program creates a structure
    of a car using pointers and
    heap memory vs. local memory
    from the stack
*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Creates structure for the car
struct Car {

    float price;
    char *name;
    char *license_plate;


};

//Creates method to create a new car object
struct Car *New_Car(float price, char *name, char *license_plate){

    puts("Car being created...");


    struct Car *new_car = malloc(sizeof(struct Car));

    //Makes sure the car object had allocated memory & exists
    if(!new_car){

        puts("Error, car not created.");
    }


    //Creates pointer variables for each individual part of the structure
    new_car->price = price;
    new_car->name = strdup(name);
    new_car->license_plate = strdup(license_plate);

    puts("Done.\n");
    puts("************************");


    return new_car;


}

//Creates a method to free allocated memory once it is finished being used
void Destroy_Car(struct Car *new_car){

    if(!new_car){

        puts("Car doesn't exist so can't destroy");

    }

    puts("************************");
    printf("Car deallocated from memory at space %p.\n", new_car);
    free(new_car->name);
    free(new_car->license_plate);
    free(new_car);

}

//Creates a method that prints the car's values
void Print_Car(struct Car *new_car){

    printf("The car costs $%.2f\n", new_car->price);
    printf("The car's type is: %s\n", new_car->name);
    printf("THe car's license plate is: %s\n", new_car->license_plate);

}

//Main method
int main(int argc, char **argv){

    //Instantiates new car object
    struct Car *new_car = New_Car(234556.00, "Ford", "F34DCZ4");

    //Calls previously defined methods
    Print_Car(new_car);
    Destroy_Car(new_car);
    //Prints a space
    puts("");


    return(0);

}
