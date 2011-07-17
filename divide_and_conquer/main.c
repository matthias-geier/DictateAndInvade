#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <linked_list.h>
#include <sqlite3_framework.h>
#include <buildings.h>

double my_test_number = 0;

/*
 *
 */
void signal_callback_handler(int signum) {
    // FIXME: different signum cases with different handling
    
    // FIXME: replace with logger
    printf("Application terminated with signal: %d\n", signum);
    exit(signum);
}

void list_callback(linked_list* meow) {
    int* val = (int*)meow->value;
    printf("%d\n", *val);
}

/*
 * 
 */
int main(int argc, char** argv) {
    linked_list* list = NULL;
    int status;
    int x = 1; int y = 28; int z = 23;
    
    // trap signals
    // FIXME: add all signal traps that can occur
    signal(SIGHUP, signal_callback_handler);
    signal(SIGINT, signal_callback_handler);
    signal(SIGKILL, signal_callback_handler);
    
    /*linked_list* llx = linked_list_create((void*)&x);
    linked_list_create_and_insert_after(llx, (void*)&y);
    linked_list_create_and_insert_after(llx, (void*)&z);
    linked_list_for_all(llx, &list_callback);*/
    
    //call_lua_stack();
    
    printf("list ptr before: %d\n", list);
    status = building_get_all(&list);
    printf("list ptr after: %d\n", list);
    printf("Returned status: %d\n", status);
    if (status == 0) {
        linked_list* cur = list;
        while(cur != NULL) {
            building_print_details((building*)cur->value);
            cur = cur->next;
        }
    }
    
    return (EXIT_SUCCESS);
}

