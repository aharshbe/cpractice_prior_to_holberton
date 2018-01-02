#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//Struct for car

struct Car {

char *name;
int year;
float price;

};


//Create car

struct Car *New_Car(char *name, int year, float price){

struct Car *new_car = malloc(sizeof(struct Car));

if(!new_car){

    puts("Car didn't allocate");

}

new_car->name = strdup(name);
new_car->year = year;
new_car->price = price;


/*
    Pointers can also be written like:
    (*new_car).name = strdup(name);
    (*new_car).year = year;
    (*new_car).price = price;
*/

return new_car;


};


//Destroy new car

void destroy_car(struct Car *new_car){

    if(!new_car){

        puts("Car doesn't exist");

    }

    free(new_car->name);
    free(new_car);

    puts("Memory deallocated");

}

void print_car(struct Car *new_car){

    printf("The car's name is: %s\n", new_car->name);
    printf("The car's year is %d\n", new_car->year);
    printf("The car's price is: $%.2f\n", new_car->price);


}

int main(int argc, char **argv){


    struct Car *new_car = New_Car("Ford", 1978, 12456.00);
    print_car(new_car);
    destroy_car(new_car);

    return(0);



}
