
#ifndef SQLITE3_FRAMEWORK_H
#define	SQLITE3_FRAMEWORK_H

#include <sqlite3.h>

#define SQLITE3FILE             "db.sqlite"

#define SQL_STMT_COUNT          "SELECT count(*) FROM %s %s;"
#define SQL_STMT_SELECTALL      "SELECT * FROM %s %s;"

#define SQL_TAB_PLAYER          "player"
#define SQL_TAB_BUILDING        "buildings"


/*
 * global sql variables for sqlite3 transactions
 */
sqlite3* sql_struct;
sqlite3_stmt* sql_statement;

/*
 * opens a connection to the database and prepares
 * the statement. the database can be opened for
 * read and write access.
 * 
 * @param querystring:  string to be executed
 * @param flag:         SQLITE_OPEN_READONLY or SQLITE_OPEN_READWRITE
 * @return:             status flag like SQLITE_OK
 */
int sql_open_and_prepare(const char* querystring, int flag);



/*
 * finalizes the database transaction and closes the
 * connection
 * 
 * @return:             status flag like SQLITE_OK
 */
int sql_finalize_and_close();



/*
 * retrieves one column and assumes it is a number.
 * valuable when retrieving a total row count.
 * 
 * @param *number:      pointer where the number is written to
 * @returns:            status flag like SQLITE_DONE
 */
int sql_retrieve_number(int* number);



/*
 * loops the retrieved rows and calls the processor function
 * with the current sqlite statement. the processor can add
 * the results to a given datastructure.
 * 
 * @param *processor:           function pointer to process the current row
 * @param *datastructure:       void pointer to the datastructure passed on to processor
 * @returns:                    status flag like SQLITE_DONE
 */
int sql_loop_rows(void (*processor)(sqlite3_stmt*, void**), void** datastructure);



/*
 * insert parameters into select all query and return a pointer
 * 
 * @param *from:                from string
 * @param *where:               where string
 * @returns:                    char pointer to query
 */
char* sql_generate_selectall_query(char* from, char* where);


#endif	/* SQLITE3_FRAMEWORK_H */

