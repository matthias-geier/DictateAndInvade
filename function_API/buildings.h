
#ifndef BUILDINGS_H
#define	BUILDINGS_H

#include <sqlite3.h>
#include <linked_list.h>
#include <string_s.h>

string_s building_column_names[] = {
    {"id"}, {"name"}, {"lvl"}
};
int building_column_amount = 3;

struct type_building {
    int id;
    char* name;
    int lvl;
};

typedef struct type_building building;

/*
 * converts an sqlite statement to a building type and attaches it to the
 * back of the datastructure(ex. linked_list)
 * 
 * @param *stmt:                pointer to sqlite statement
 * @param **datastructure:      void pointer to pointer to the building datastructure
 */
void building_convert_stmt(sqlite3_stmt* stmt, void** datastructure);



/*
 * retrieve all buildings from database and attach them to the linked list
 * 
 * @param **list:               pointer to pointer of the linked list (NULL pointer on empty list)
 * @return:                     status flag like SQLITE_OK
 */
int building_get_all(linked_list** list);



/*
 * print all details of a building
 * 
 * @param *b:                   pointer to the building
 */
void building_print_details(building* b);



/*
 * generate a query to update a building in the database or insert a new one if id = 0
 * 
 * @param **datastructure:      void pointer to pointer of the building struct
 * @return:                     pointer to char array holding the query
 */
char* building_insert_or_update_query(void** datastructure);


#endif	/* BUILDINGS_H */

