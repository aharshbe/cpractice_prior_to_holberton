//This C application creates a database of passeword entries


#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<assert.h>
#include<stdlib.h>

//Creating CPP (pre-processors)

#define MAX_DATA 512
#define MAX_ROWS 100

//Creating password structure
struct Passwords {

	int id;
	int set;
	char user_name[MAX_DATA];
	char password[MAX_DATA];
	char notes[MAX_DATA];

};


//Creating database structure
struct Database {

	struct Passwords rows[MAX_ROWS];

};


//Creating connetion to the database
struct Connection {

	FILE *file;
	struct Database *db;

};

//Creting a error message function to exit application and print an error
void error_message(const char *message){

	if(errno){
		perror(message);

	}else{
		printf("Error: %s.\n", message);
	}

	exit(1);
}

//Creating function to print out a password
void Password_print(struct Passwords *pwd){

	printf("ID: %d.\n", pwd->id);
	printf("User Name: %s.\n", pwd->user_name);
	printf("Password: %s.\n", pwd->password);
	printf("Notes: %s.\n", pwd->notes);

}

//Creating database load function
void Database_load(struct Connection *conn){

	//Reading database
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		error_message("Failes to load database.");

}

//Creating database connection
struct Connection *Database_open(const char *filename, char mode){

	//Alllocating memeory to connection object
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)
		error_message("Memeory error.");

	//Allocation memeory to database object
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db)
		error_message("Memeory error.");

	//If the file hasn't opened before, open with write, otherwise open with read/write
	if(mode == 'c'){
		conn->file = fopen(filename, "w");
	}else{
		conn->file = fopen(filename, "r+");

		if(conn->file){
			Database_load(conn);
		}
	}

	if(!conn->file)
		error_message("Failed to open file");

	return conn;
}

//Creating method to close database
void Database_close(struct Connection *conn){

	//If there's a connection
	if(conn){
		//If there's a connection to file, close file
		if(conn->file)
			fclose(conn->file);
		//If there's a connection to dabatase, close database
		if(conn->db)
			free(conn->db);
		//Deallocate memeory to connection
		free(conn);
	}
}

//Creating method to wrte database 
void Database_write(struct Connection *conn){

	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		error_message("Failed to write database");

	rc = fflush(conn->file);
	if(rc == -1)
		error_message("Cannot flush database");

}

//Create the database
void Database_create(struct Connection *conn){

	int i = 0;

	for(i = 0; i < MAX_ROWS; i++){
		//Make prototype to initalize it
		struct Passwords pwd = {.id = i,.set = 0};
		//Then just assign it
		conn->db->rows[i] = pwd;
	}
}

//Method to set database
void Database_set(struct Connection *conn, int id, const char *user_name,
	const char *password, const char notes[]){

	struct Passwords *pwd = &conn->db->rows[id];
	if(pwd->set)
		error_message("Already set row, please delete first.");

	pwd->set = 1;
	char *res = strncpy(pwd->user_name, user_name, MAX_DATA);
	if(!res)
		error_message("User name copy failed.");

	res = strncpy(pwd->password, password, MAX_DATA);
	if(!res)
		error_message("Password copy failed.");

	res = strncpy(pwd->notes, notes, MAX_DATA);
	if(!res)
		error_message("Notes copy faile.,");

}

//Method to get database
void Database_get(struct Connection *conn, int id){

	struct Passwords *pwd = &conn->db->rows[id];

	if(pwd->set){
		Password_print(pwd);

	}else {
		error_message("ID is not set");
	}
}

//Method to delete database entry
void Database_delete(struct Connection *conn, int id){

	struct Passwords pwd = {.id = id,.set = 0};
	conn->db->rows[id] = pwd; 

}

//Method to list database 
void Database_list(struct Connection *conn){

	int i = 0;
	struct Database *db = conn->db;

	for(i = 0; i < MAX_ROWS; i++){
		struct Passwords *cur = &db->rows[i];

		if(cur->set){
			Password_print(cur);
		}

	}

}

//Main method

int main(int argc, char *argv[]){

	if(argc < 3)
		error_message("Please enter: database <dbfile name> <db action> [action params]");

		char *filename = argv[1];
		char action = argv[2][0];
		struct Connection *conn = Database_open(filename, action);
		int id = 0;

		if(argc > 3) id = atoi(argv[3]);
		if(id >= MAX_ROWS) error_message("There's not that many records.");

		switch(action){

			case 'c':
				Database_create(conn);
				Database_write(conn);
				break;

			case 'g':
				if(argc != 4)
					error_message("Need an id to get");

				Database_get(conn, id);
				break;

			case 's':
				if(argc != 7)
					error_message("Need id, user_name, password, and notes to set");

				Database_set(conn, id, argv[4], argv[5], argv[6]);
				Database_write(conn);
				break;

			case 'd':
				if(argc != 4)
					error_message("Need id to delete row.");

				Database_delete(conn, id);
				Database_write(conn);
				break;

			case 'l':
				Database_list(conn);
				break;
			default:
				error_message("Invalid action: c=create, g=get, s=set, d=del, l=list");

		}

		Database_close(conn);

		return 0;
	}

