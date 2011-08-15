

#ifndef ARRAY_LIST_H
#define	ARRAY_LIST_H

#include <memory_management.h>
#include <logging.h>

#define ARRAY_LIST_INIT_SIZE 50
#define ARRAY_LIST_EXTEND_BY 50


/**
 * array list structure
 * 
 * array:                       pointer to void pointer array
 * num_elements:                max set element + 1
 * extend_by:                   number of elements for extension
 * max_elements:                array size
 * destroy_ptr:                 pointer to function with parameter void**
 */
struct list_array {
    void** array;
    int num_elements;
    int extend_by;
    int max_elements;
    void (*destroy_ptr)(void**);
};

typedef struct list_array array_list;



/**
 * returns the element at position pos or NULL if pos is larger than max_elements
 * 
 * @param list:                 pointer to array list
 * @param pos:                  position to fetch (arrays start with 0)
 * @return:                     void* to content or NULL
 */
void* array_list_get(array_list* list, int pos);



/**
 * sets position pos to content pointer. extends or shrinks the array on demand
 * 
 * @param list:                 pointer to array list
 * @param pos:                  position to set (arrays start with 0)
 * @param content:              void* to content
 */
void array_list_set(array_list* list, int pos, void* content);



/**
 * creates a new array list with predefined values or parameters
 * 
 * @param initial_size:         initial array size if > 0, else predefined
 * @param extend_by:            extension size if > 0, else predefined
 * @return:                     pointer to array list
 */
array_list* array_list_create(int initial_size, int extend_by);



/**
 * destroys the array list end the content with it (if function pointer
 * is provided XOR destroy_ptr is set ((destroy_ptr is fallback)) )
 * 
 * @param list:                 pointer to array list
 * @param processor:            pointer to destroy function or NULL
 */
void array_list_destroy(array_list* list, void (*processor)(void**));



/**
 * returns the position of max element + 1
 * 
 * @param list:                 pointer to array list
 * @return:                     size
 */
int array_list_size(array_list* list);



/**
 * for all (list items) do: callback function
 * convenience implementation
 * 
 * @param list:                 pointer to array list
 * @param callback_func:        pointer to function with parameters position and content void*
 */
void array_list_for_all(array_list* list, void (*callback_func)(int, void*));




#endif	/* ARRAY_LIST_H */

