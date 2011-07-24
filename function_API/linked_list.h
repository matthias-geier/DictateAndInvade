/* 
 * File:   linked_list.h
 * Author: mayu
 *
 * Created on July 10, 2011, 6:04 PM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#include <core.h>

struct list_double_linked {
    void* value;
    struct list_double_linked* next;
    struct list_double_linked* last;
};

typedef struct list_double_linked linked_list;

linked_list* linked_list_begin(linked_list* entry);
linked_list* linked_list_create(void* value);
linked_list* linked_list_create_and_insert_after(linked_list* entry, void* value);



/*
 * destroys a linked list entry and the content with it (if function pointer
 * is provided)
 * 
 * @param entry:                list entry to destroy
 * @param *processor:           function pointer for content destruction or NULL
 * @returns:                    next item in line
 */
linked_list* linked_list_destroy(linked_list* entry, void (*processor)(void**));

int linked_list_size(linked_list* entry);
void linked_list_for_all(linked_list* entry, void(*callback_func)(linked_list*));

#endif	/* LINKED_LIST_H */

