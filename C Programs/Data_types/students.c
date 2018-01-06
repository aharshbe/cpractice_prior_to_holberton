/*
	This program uses the header file
	students.h to create a new students type.
	
	It then asks the user a number of
	times to enter the students dorm, 
	and name based on the number of students the 
	user selects. It then prints out the 
	students details.
*/

#include "students.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char **argv){

	int num_choice = 0;

	printf("How many students would you like to create? : ");
	scanf(" %d", &num_choice);

	//Have to call getchar because of the use of fgets() below
	getchar();
	printf("\n");

	//Creates an array of students
	students students_arr[num_choice];

	//Iterates over studnets in array to get their namne and dorm number
	for(int i = 0; i < num_choice; i++){

		//Allocates memeory to students name
		students_arr[i].name = calloc(80, sizeof(char)*num_choice);

		printf("What is the name of student %i? : ", i+1);
		//Chose gets so I don't have to deal with extra return character i.e., \n
		gets(students_arr[i].name);

		//Allocates memeory to stduents dorm
		students_arr[i].dorm = calloc(80, sizeof(char)*num_choice);

		printf("What is the dorm number of the student? : ");
		gets(students_arr[i].dorm);

		puts("*********************************************\n");	

	}

	puts("******************Current dorm info******************\n");


	//Iterates through array and prints student information
	for(int k = 0; k < num_choice; k++){

		printf("Studnet %i's name is %s and they will be in dorm %s.\n", k+1, students_arr[k].name, students_arr[k].dorm);
	}

	//Frees any allocated space that was used by calloc();
	for(int j = 0; j < num_choice; j++){

		free(students_arr[j].name);
		free(students_arr[j].dorm);

	}


	return 0;

}