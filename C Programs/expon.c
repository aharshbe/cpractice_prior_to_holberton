#include<stdio.h>
#include<math.h>


int main(int argc, char **argv){


	// printf("Pick a value: ")
	// scanf(" %.2lf", &value);

	// printf("Raide by: ");
	// scanf(" %2lf", &expon);


	float value = 2;
	float expon = 2;

	float result = pow(value, expon);

	printf(" %.2lf\n", result);

	return(0);
}