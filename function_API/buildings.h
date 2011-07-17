
#ifndef BUILDINGS_H
#define	BUILDINGS_H

#include <sqlite3.h>
#include <linked_list.h>

struct type_building {
    int id;
    char* name;
    int lvl;
};

typedef struct type_building building;


void building_convert_stmt(sqlite3_stmt* stmt, void** datastructure);

int building_get_all(linked_list** list);

void building_print_details(building* b);

#endif	/* BUILDINGS_H */

