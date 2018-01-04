//This program demonstrates how to create structures in C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Car {

    char name[80];
    float price;
    char license_plate[10];

};


int main(int argc, char **argv){


struct Car new_car;

/*
    Need to use strcpy to
    copy arrays without pointers
*/

strcpy(new_car.name,"Ford");
new_car.price = 34569.00;
strcpy(new_car.license_plate, "F3454ZD");

printf("The car's type is: %s\n", new_car.name);
printf("The car costs: $%.2f\n", new_car.price);
printf("The car's license plate is: %s\n", new_car.license_plate);

return 0;



}
