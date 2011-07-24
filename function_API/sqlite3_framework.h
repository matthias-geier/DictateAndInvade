
#ifndef SQLITE3_FRAMEWORK_H
#define	SQLITE3_FRAMEWORK_H

#include <core.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define SQLITE3FILE             "db.sqlite"

#define SQL_STMT_COUNT          "SELECT count(*) FROM %s %s;"
#define SQL_STMT_SELECTALL      "SELECT * FROM %s %s;"
#define SQL_STMT_INSERT         "INSERT INTO %s (%s) VALUES (%s);"
#define SQL_STMT_UPDATE         "UPDATE %s SET %s WHERE %s;"

#define SQL_TAB_PLAYER          "player"
#define SQL_TAB_BUILDING        "buildings"


/*
 * global sql variables for sqlite3 transactions
 */
extern sqlite3* sql_struct;
extern sqlite3_stmt* sql_statement;

/*
 * opens a connection to the database and prepares
 * the statement. the database can be opened for
 * read and write access.
 * 
 * @param *querystring: string to be executed
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
int sql_finalize_and_close(void);



/*
 * retrieves one column and assumes it is a number.
 * valuable when retrieving a total row count.
 * 
 * @param *number:      pointer where the number is written to
 * @return:             status flag like SQLITE_DONE
 */
int sql_retrieve_number(int* number);



/*
 * do a simple step
 * 
 * @return:             status flag like SQLITE_DONE
 */
int sql_step(void);



/*
 * loops the retrieved rows and calls the processor function
 * with the current sqlite statement. the processor can add
 * the results to a given datastructure.
 * 
 * @param *processor:           function pointer to process the current row
 * @param **datastructure:      void pointer to pointer to the datastructure passed on to processor
 * @return:                     status flag like SQLITE_DONE
 */
int sql_loop_rows(void (*processor)(sqlite3_stmt*, void**), void** datastructure);



/*
 * insert parameters into select all query and return a pointer
 * remember to free the query string!
 * 
 * @param *from:                from string
 * @param *where:               where string
 * @return:                     char pointer to query
 */
char* sql_generate_selectall_query(char* from, char* where);



/*
 * generates an insert query and returns a pointer
 * remember to free the query string!
 * 
 * @param *into:                into string
 * @param *columns:             columns string
 * @param *values:              values string
 * @return:                     char pointer to query
 */
char* sql_generate_insert_query(char* into, char* columns, char* values);



/*
 * generates an update query and returns a pointer
 * remember to free the query string!
 * 
 * @param *update:              update string
 * @param *set:                 set string
 * @param *where:               where string
 * @return:                     char pointer to query
 */
char* sql_generate_update_query(char* update, char* set, char* where);

/*
 * calls the processor function to generate either an insert or
 * update query. executes the query with data from the provided
 * datastructure
 * 
 * @param *processor:           function pointer to transform the datastructure to a query
 * @param **datastructure:      void pointer to pointer to the datastructure passed on to processor
 * @return:                     status flag like SQLITE_DONE
 */
int sql_insert_or_update_datastructure(char* (*processor)(void**), void** datastructure);


#endif	/* SQLITE3_FRAMEWORK_H */

