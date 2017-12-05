#include<stdio.h>

int main(void){


int distance = 100;
float power = 2.345f;
double super_power = 56798.4532;
char middle_initial = 'S';
char first_name[] = "Austin";
char last_name[] = "Harshberger";

printf("You are %d miles away.\n", distance);
printf("You have %f levels of power.\n", power);
printf("You have %f awesome super powers.\n", super_power);
printf("I have an initial %c.\n", middle_initial);
printf("I have a first name %s.\n", first_name);
printf("I have a last name %s.\n", last_name);
printf("My full name is %s %c. %s.\n", first_name, middle_initial, last_name);

int bugs = 100;
double bug_rate = 1.2;

printf("You have %d bugs at a the imaginary rate of %f.\n", bugs, bug_rate);

/*
How to break it:
ex7.c:26:53: warning: integer overflow in expression [-Woverflow]
 long universe_of_defects = 10240000L * 10240000000L * 98810240L * 454454510240L
*/

long universe_of_defects = 1024L * 1024L * 1024L * 1024L;
printf("The entire universe has %ld bugs.\n", universe_of_defects);

unsigned long u_universe_of_defects = 1024L * 1024L * 1024L * 1024L;
printf("The entire universe has %ld (u) bugs.\n", u_universe_of_defects);

double expected_bugs = bugs * bug_rate;
printf("You are expected to have %f bugs.\n", expected_bugs);

//How you indicate exponents
double part_of_universe = expected_bugs / universe_of_defects;
printf("This is the only a %e portion of the universe.\n", part_of_universe);

//This makes no sense, just a demo of something weird
char nul_byte = '\0';

int care_percentage = bugs * nul_byte;
printf("Which means you should care %d%%.\n", care_percentage);

//Attempting to printf the nul_byte as a string
// printf("%s\n", nul_byte);

/*
Debugger output:
ex7.c:43:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
 printf("%s\n", nul_byte);
*/

	return 0;
}