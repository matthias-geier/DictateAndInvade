

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#include <memory_management.h>
#include <logging.h>


/**
 * linked list structure
 * 
 * value:                       content
 * next:                        pointer to next element or NULL
 * last:                        pointer to previous element or NULL
 * destroy_ptr:                 pointer to function with parameter void**
 */
struct list_double_linked {
    void* value;
    struct list_double_linked* next;
    struct list_double_linked* last;
    void (*destroy_ptr)(void**);
};

typedef struct list_double_linked linked_list;



/**
 * returns the first item in the linked list
 * 
 * @param entry:                any element in the list
 * @return:                     first element in the list
 */
linked_list* linked_list_begin(linked_list* entry);



/**
 * creates a new linked list with the given value
 * 
 * @param value:                pointer to content
 * @return:                     list element
 */
linked_list* linked_list_create(void* value);



/**
 * creates a new element and inserts it after the given element
 * 
 * @param entry:                list element
 * @param value:                pointer to content
 * @return:                     new list element
 */
linked_list* linked_list_create_and_insert_after(linked_list* entry, void* value);



/**
 * destroys a linked list entry and the content with it (if function pointer
 * is provided XOR destroy_ptr is set ((destroy_ptr is fallback)) )
 * 
 * @param entry:                list entry to destroy
 * @param *processor:           function pointer for content destruction or NULL
 * @returns:                    next item in line if not NULL, else previous item or NULL
 */
linked_list* linked_list_destroy(linked_list* entry, void (*processor)(void**));



/**
 * counts all elements in the list and returns the value
 * 
 * @param entry:                any element in the list
 * @return:                     element count
 */
int linked_list_size(linked_list* entry);



/**
 * for all (list items) do: callback function
 * convenience implementation
 * 
 * @param entry:                any element in the list
 * @param callback_func:        pointer to function with parameter linked_list*
 */
void linked_list_for_all(linked_list* entry, void (*callback_func)(linked_list*));



/**
 * sets entry content at position pos to value. if position is higher than
 * list length, nothing happens
 * 
 * @param entry:                any element in the list
 * @param pos:                  position in the list (first element is 0)
 * @param value:                content value
 */
void linked_list_set(linked_list* entry, int pos, void* value);



/**
 * retrieves entry content at the position pos. if position is higher than
 * list length, NULL is returned
 * 
 * @param entry:                any element in the list
 * @param pos:                  position in the list (first element is 0)
 * @return:                     pointer to entry or NULL
 */
linked_list* linked_list_get(linked_list* entry, int pos);

#endif	/* LINKED_LIST_H */

