
#include <stdlib.h>
#include <stdio.h>
#include <buildings.h>
#include <sqlite3_framework.h>
#include <sqlite3.h>
#include <string.h>


void building_convert_stmt(sqlite3_stmt* stmt, void** datastructure) {
    const unsigned char* name;
    linked_list* current;
    linked_list* latest;
    linked_list* datafirst = (linked_list*)(*datastructure);
    building* b = (building*)malloc(sizeof(building));
    printf("Entering building converter (datastructure %d, datafirst %d)\n", datastructure, datafirst);
    
    b->id = sqlite3_column_int(stmt, 0);
    name = sqlite3_column_text(stmt, 1);
    b->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(b->name, name);
    b->lvl = sqlite3_column_int(stmt, 2);
    
    building_print_details(b);
    
    latest = linked_list_create((void*)b);
    if (datafirst == NULL) {
        printf("Entering datafirst == null;; latest: %d\n", latest);
        datafirst = latest;
    }
    else {
        printf("Entering datafirst != null\n");
        current = datafirst;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = latest;
        latest->last = current;
    }
    
    *datastructure = (void*)datafirst;
    
    printf("Leaving building converter (datastructure %d, datafirst %d)\n\n", datastructure, datafirst);
}

int building_get_all(linked_list** list) {
    int status = 0;
    char* query = sql_generate_selectall_query(SQL_TAB_BUILDING, "");
    status = sql_open_and_prepare(query, SQLITE_OPEN_READONLY);
    free(query);
    if (status != SQLITE_OK) {
        return status;
    }
    
    status = sql_loop_rows(&building_convert_stmt, (void**)list);
    printf("datastructure after looping %d\n", list);
    
    if (status != SQLITE_DONE) {
        printf("SQL row looping returned status: %d\n", status);
    }
    
    status = sql_finalize_and_close();
    return status;
}

void building_print_details(building* b) {
    printf("Building (id: %d) %s is of Level %d\n", b->id, b->name, b->lvl);
}

char* building_insert_or_update_query(void** datastructure) {
    int total = 1;
    int i;
    char* chunk1;
    char* chunk2;
    char* num;
    char* query;
    building* b = (building*)*datastructure;
    
    // do update
    if (b->id > 0) {
        // fill chunk2 with where string
        num = (char*)malloc(sizeof(char) * 11);
        snprintf(num, 10, "%d", b->id);
        total += strlen(building_column_names[0].value);
        total += 1; // the equals
        total += strlen(num);
        chunk2 = (char*)malloc(sizeof(char) * total);
        sprintf(chunk2, "%s=%s", building_column_names[0].value, num);
        printf("chunk2 (len %d): %s\n", strlen(chunk2), chunk2);
        free(num);
        
        // fill chunk1 with set string
        num = (char*)malloc(sizeof(char) * 11);
        snprintf(num, 10, "%d", b->lvl);
        total = 1;
        total += strlen(num);
        for(i=1; i<building_column_amount; i++) {
            total += strlen(building_column_names[i].value);
            if (i>1) {
                total += 2; // add comma + space when having more than one entry
            }
        }
        total += strlen(b->name);
        total += 2; // high commata for name
        total += 2; // equals twice
        chunk1 = (char*)malloc(sizeof(char) * total);
        sprintf(chunk1, "%s=\"%s\", %s=%s", building_column_names[1].value, b->name, building_column_names[2].value, num);
        printf("chunk1 (len %d): %s\n", strlen(chunk1), chunk1);
        free(num);
        
        query = sql_generate_update_query(SQL_TAB_BUILDING, chunk1, chunk2);
    }
    // do insert
    else {
        // fill chunk2 with values string
        num = (char*)malloc(sizeof(char) * 11);
        snprintf(num, 10, "%d", b->lvl);
        total += strlen(b->name);
        total += 2; // comma + space
        total += 2; // high commata for name
        total += strlen(num);
        chunk2 = (char*)malloc(sizeof(char) * total);
        sprintf(chunk2, "\"%s\", %s", b->name, num);
        printf("chunk2 (len %d): %s\n", strlen(chunk2), chunk2);
        free(num);
        
        // fill chunk1 with columns string
        total = 1;
        for(i=1; i<building_column_amount; i++) {
            total += strlen(building_column_names[i].value);
            if (i>1) {
                total += 2; //add comma + space when having more than one entry
            }
        }
        chunk1 = (char*)malloc(sizeof(char) * total);
        sprintf(chunk1, "%s, %s", building_column_names[1].value, building_column_names[2].value);
        printf("chunk1 (len %d): %s\n", strlen(chunk1), chunk1);
        
        query = sql_generate_insert_query(SQL_TAB_BUILDING, chunk1, chunk2);
    }
    free(chunk1);
    free(chunk2);
    return query;
}
