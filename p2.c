#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>


struct Animal{

	char *name;
	int age;
	char *home;
};


struct Animal *Animal_Create(char *name, int age, char *home){

	//Creating setters
	struct Animal *Bear = malloc(sizeof(struct Animal));
	assert(Bear != NULL);

	//Pointers can be created either of the two ways below, the first option is a shortcut, the second is the more offical way

	/*
	Bear->name = strdup(name);
	Bear->age = age;
	Bear->home = strdup(home);
	*/

	(*Bear).name = strdup(name);
	(*Bear).age = age;
	(*Bear).home = strdup(home);

	return Bear;

}


void Animal_Destroy(struct Animal *Bear){

	assert(Bear != NULL);

	free(Bear->name);
	free(Bear->home);
	free(Bear);
}


void Print_Bear(struct Animal *Bear){

	printf("The Bear's name is: %s.\n", Bear->name);
	printf("The Bear is: %d years old.\n", Bear->age);
	printf("The bear lives in: %s.\n", Bear->home);

}

int main(int argc, char *argv[]){

	//Name a new instance of a bear
	struct Animal *Franky = Animal_Create("Franky", 103, "Alaska");

	//Printing out the bear & it's location in memeory
	printf("The bear is located at %p is memeory.\n", Franky);
	Print_Bear(Franky);

	//Destroying the bear to save memory
	Animal_Destroy(Franky);

	return 0;
}