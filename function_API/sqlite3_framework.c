
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3_framework.h>


int sql_open_and_prepare(const char* querystring, int flag) {
    int status = 0;
    status = sqlite3_open_v2(SQLITE3FILE, &sql_struct, flag, NULL);
    printf("SQL open status: %d\n", status);
    if (status != SQLITE_OK) {
        return status;
    }
    
    status = sqlite3_prepare_v2(sql_struct, querystring, 2000, &sql_statement, NULL);
    printf("SQL prepare status: %d\n", status);
    
    return status;
}

int sql_finalize_and_close() {
    int status = 0;
    status = sqlite3_finalize(sql_statement);
    printf("SQL finalize status: %d\n", status);
    if (status != SQLITE_OK) {
        return status;
    }
    
    status = sqlite3_close(sql_struct);
    printf("SQL close status: %d\n", status);
    
    return status;
}

int sql_retrieve_number(int* number) {
    int status = 0;
    while((status = sqlite3_step(sql_statement)) == SQLITE_ROW) {
        *number = sqlite3_column_int(sql_statement, 0);
    }
    return status;
}

int sql_loop_rows(void (*processor)(sqlite3_stmt*, void**), void** datastructure) {
    int status = 0;
    while((status = sqlite3_step(sql_statement)) == SQLITE_ROW) {
        printf("sql loop rows enter datastructure %d\n", datastructure);
        (*processor)(sql_statement, datastructure);
        printf("sql loop rows leave datastructure %d\n", datastructure);
    }
    return status;
}

char* sql_generate_selectall_query(char* from, char* where) {
    char* query;
    int total = 0;
    
    total += strlen(SQL_STMT_SELECTALL);
    total += strlen(from);
    total += strlen(where);
    
    query = (char*)malloc(sizeof(char) * total);
    sprintf(query, SQL_STMT_SELECTALL, from, where);
    
    return query;
}
