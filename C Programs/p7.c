#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>

	/* This application creates a database which
	   attempts to replicate an address book
	*/

//Defining max values for arrays and rows for database
#define MAX_DATA 512
#define MAX_ROWS 100

//Creating a struct of an address or data to be saved to database
struct Address {

	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
	char phone_number[MAX_DATA];

};

//Creating a struct of a database which takes in an Address with a specific number of rows
struct Database {

	struct Address rows[MAX_ROWS];

};

/*Creating a struct of a connection to the database which looks 
for a file and then creates a new database object
*/
struct Connection {

	FILE *file;
	struct Database *db;

};

//Creates a method which allows for easy error reporting to the console without the use of printf
void die(const char *message){

	if(errno){

		perror(message);

	}else{

		printf("ERROR: %s\n", message);

	}

	exit(1);
}

//Creates a method to print out the variables saved in the address for the given row of the database
void Address_print(struct Address *addr){

	printf("%d %s %s %s\n", addr->id, addr->name, addr->email, addr->phone_number);

}

//Creates a method which loads the database
void Database_load(struct Connection *conn){

	//Reads the database file
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	
	//Spits out an error if there is no database file
	if(rc != 1)
		die("Failed to load database.");

}

//Creates an actual instance of a database, including opening it and the file associated
struct Connection *Database_open(const char *filename, char mode){

	//Allocates memory to the database connection
	struct Connection *conn = malloc(sizeof(struct Connection));

	if(!conn)
		die("Memmory error");

	//Allocated memory to the database itself
	conn->db = malloc(sizeof(struct Database));

	if(!conn->db){
		die("Memory error");

	}

	//If 'c' is passed, it writes a new file with the given filename variable
	if(mode == 'c'){
		conn->file = fopen(filename, "w");

	//Otherwise it just reads the database file itself
	}else{
		conn->file = fopen(filename, "r+");

		//Using the load method to load the database
		if(conn->file){
			Database_load(conn);

		}
	}

	if(!conn->file)
		die("Failes to open file");

	return conn;
}

//Method to free up allocated space to the database and connection
void Database_close(struct Connection *conn){

	if(conn){
		if(conn->file)
			fclose(conn->file);
		if(conn->db)
			free(conn->db);
		free(conn);
	}
}

//Writes new data to the database 
void Database_write(struct Connection *conn){

	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die("Failed to write database");

	rc = fflush(conn->file);
	if(rc == -1)
		die("Cannot flush database");

}

//Creates the database
void Database_create(struct Connection *conn){

	int i = 0;

	for(i = 0; i < MAX_ROWS; i++){

		//Make a prototype to initialize it
		struct Address addr = {.id = i,.set = 0};
		//then just assign it
		conn->db->rows[i] = addr;

	}
}

//Create blueprint for database and what it takes in
void Database_set(struct Connection *conn, int id, const char *name, const char *email, const char *phone_number){

	//Creates rows for database unless there is already a row with the same id
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
		die("Already set delete it first");

	//Copies data to the given row id
	addr->set = 1;
	//WARNING: bug, read the "How to break it" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	//demonstrate the strncpy bug
	if(!res)
		die("Name copy failed");

	res = strncpy(addr->email, email, MAX_DATA);
	if(!res)
		die("Email copy failed");

	res = strncpy(addr->phone_number, phone_number, MAX_DATA);
	if(!res)
		die("Phone number copy failed");

		

}

//Get method to retrieve a specific row should you provide its id
void Database_get(struct Connection *conn, int id){

	struct Address *addr = &conn->db->rows[id];

	if(addr->set) {
		Address_print(addr);
	}else{
		die("ID is not set");
	}
}

//Creates method to delete a given row provided the id is given
void Database_delete(struct Connection *conn, int id){

	struct Address addr = {.id = id,.set = 0 };
	conn->db->rows[id] = addr;

}

//Creates method to list out database rows
void Databse_list(struct Connection *conn){

	int i = 0;
	struct Database *db = conn->db;

	for(i = 0; i < MAX_ROWS; i++){

		struct Address *cur = &db->rows[i];

		if(cur->set){
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[]){

	//Lets user know what parameters to give the command line to create a database entry
	if(argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	//Sets variables
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.");

	//Switch statement to check for what action the user wants to take, then creates that action
	switch(action){
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if(argc != 4)
				die("Need an id to get");

			Database_get(conn, id);
			break;

		case 's':
			if(argc !=7)
				die("Need is, name, email, phone number to set");

			Database_set(conn, id, argv[4], argv[5], argv[6]);
			Database_write(conn);
			break;

		case 'd':
			if(argc != 4)
				die("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Databse_list(conn);
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}

	//Closes the database
	Database_close(conn);

	//Returns no errors
	return 0;
}