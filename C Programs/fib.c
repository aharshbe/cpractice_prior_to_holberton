#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

struct Person {

	int age;
	char *name;

};


struct Person *create_person(int age, const char *name){

	struct Person *person = malloc(sizeof(struct Person));

	assert(person != NULL);

	person->age = age;
	person->name = strdup(name);

	return person;
}

void destroy_person(struct Person *person){

	assert(person != NULL);

	free(person->name);
	free(person);

	printf("Person deallocated at %p.\n", person);
}

void print_person(struct Person *person){

	printf("The person is %d years old.\n", person->age);
	printf("The person's name is, %s.\n", person->name);

}

int main(void){

	struct Person *austin = create_person("10", "Austin");
	print_person(austin);
	destroy_person(austin);

	return 0;
}