
#include <stdio.h>
#include <sqlite3_framework.h>
#include <sqlite3.h>

void test_db() {
    sqlite3* s;
    sqlite3_stmt* statement;
    int status=0;
    status = sqlite3_open_v2(SQLITE3FILE, &s, SQLITE_OPEN_READONLY, 0);
    printf("Open status: %d\n", status);
    if (status != SQLITE_OK) {
        printf("SQLite status is NOK\n");
        return;
    }
    
    status = sqlite3_prepare_v2(s, "SELECT * FROM buildings;",100, &statement, 0);
    printf("Prepare status: %d\n", status);
    if (status != SQLITE_OK) {
        printf("SQLite status is NOK\n");
        return;
    }
    
    printf("Returned values:\n");
    while((status = sqlite3_step(statement)) == SQLITE_ROW) {
        printf("Building %d: %s (Lvl %d)\n", sqlite3_column_int(statement, 0), sqlite3_column_text(statement, 1), sqlite3_column_int(statement, 2));
    }
    
    status = sqlite3_finalize(statement);
    printf("Finalize status: %d\n", status);
    if (status != SQLITE_OK) {
        printf("SQLite status is NOK\n");
        return;
    }
    
    status = sqlite3_close(s);
    printf("close status: %d\n", status);
}