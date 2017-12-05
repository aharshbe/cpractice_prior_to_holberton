#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//Defining the class of a person and what a person containts
struct Person {

	char *name;
	int age;
	int height;
	int weight;
};

/*Creating a function which serves a an object of a person from the class blueprint defined above
(the function which creates said person must containt the same contents)
*/
struct Person *Person_create(char *name, int age, int height, int weight){

	//Requesting a chunk of memory from the OS's heap in order to create a person object called 'who' based on the class's size in memory
	struct Person *who = malloc(sizeof(struct Person));
	//Make sure you have a valud piece of memory back from malloc
	assert(who != NULL);

	/*Strdup is used to duplicate the string for the name, operates similar to malloc 
	but also copies the string into the mem. it creates, it's a validation proceedure
	*/

	/*De-referencing (->) each content trait from the person class and adding it 
	as a reference point to the 'who' person object, then setting that to the variables defined in the method insntiation of Person_create
	*/

	(*who).name = strdup(name);
	(*who).age = age;
	(*who).height = height;
	(*who).weight = weight;
	

	/*

	One can also create pointers the shorcut way like below:

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	*/

	return who;
}

//Creating a function which serves to release memory allocated by malloc so as to remove any possibility of causing a memory leak
void Person_destroy(struct Person *who){

	//Making sure a valid pointer reference can be obtained before freeing up memory
	assert(who != NULL);

	//Freeing said memory
	free(who->name);
	free(who);

}


//Creating a function which prints off the contents of the 'who' person object
void Person_print(struct Person *who){

	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);

}

//Main method

int main(int argc, char *argv[]){

	//Make two people objects using the person_create function defined above
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	//Print them out and where they are in memeory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memoery location %p:\n", frank);
	Person_print(frank);

	//Showing that varibles can still be manipulated using point math
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	//Second example of frank of how you can modify a pointer !using the shortcut (->)
	(*frank).age += 20;
	(*frank).weight += 20;
	Person_print(frank);

	//Destroy both person objects to free up memory alllocated by malloc() and strdup()
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}