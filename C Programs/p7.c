#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {

	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
	char phone_number[MAX_DATA];

};


struct Database {

	struct Address rows[MAX_ROWS];

};

struct Connection {

	FILE *file;
	struct Database *db;

};

void die(const char *message){

	if(errno){

		perror(message);

	}else{

		printf("ERROR: %s\n", message);

	}

	exit(1);
}

void Address_print(struct Address *addr){

	printf("%d %s %s %s\n", addr->id, addr->name, addr->email, addr->phone_number);

}

void Database_load(struct Connection *conn){

	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	
	if(rc != 1)
		die("Failed to load database.");

}

struct Connection *Database_open(const char *filename, char mode){

	struct Connection *conn = malloc(sizeof(struct Connection));

	if(!conn)
		die("Memmory error");

	conn->db = malloc(sizeof(struct Database));

	if(!conn->db){
		die("Memory error");

	}

	if(mode == 'c'){
		conn->file = fopen(filename, "w");

	}else{
		conn->file = fopen(filename, "r+");

		if(conn->file){
			Database_load(conn);

		}
	}

	if(!conn->file)
		die("Failes to open file");

	return conn;
}

void Database_close(struct Connection *conn){

	if(conn){
		if(conn->file)
			fclose(conn->file);
		if(conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn){

	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die("Failed to write database");

	rc = fflush(conn->file);
	if(rc == -1)
		die("Cannot flush database");

}

void Database_create(struct Connection *conn){

	int i = 0;

	for(i = 0; i < MAX_ROWS; i++){

		//Make a prototype to initialize it
		struct Address addr = {.id = i,.set = 0};
		//then just assign it
		conn->db->rows[i] = addr;

	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email, const char *phone_number){

	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
		die("Already set delete it first");

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

void Database_get(struct Connection *conn, int id){

	struct Address *addr = &conn->db->rows[id];

	if(addr->set) {
		Address_print(addr);
	}else{
		die("ID is not set");
	}
}

void Database_delete(struct Connection *conn, int id){

	struct Address addr = {.id = id,.set = 0 };
	conn->db->rows[id] = addr;

}

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

	if(argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.");

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

	Database_close(conn);

	return 0;
}