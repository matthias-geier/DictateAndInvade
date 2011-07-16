
#include <stdlib.h>
#include <linked_list.h>

/*
 * 
 */
linked_list* linked_list_begin(linked_list* entry) {
    linked_list* current = entry;
    while(current->last != NULL) {
        current = current->last;
    }
    return current;
}

/*
 * 
 */
linked_list* linked_list_create(void* value) {
    linked_list* entry = (linked_list*)malloc(sizeof(linked_list));
    entry->value = value;
    entry->next = NULL;
    entry->last = NULL;
    return entry;
}

/*
 * 
 */
linked_list* linked_list_create_and_insert_after(linked_list* entry, void* value) {
    linked_list* current = linked_list_create(value);
    
    if (entry->next != NULL) {
        current->next = entry->next;
        current->last = entry;
        entry->next->last = current;
        entry->next = current;
    }
    else {
        entry->next = current;
    }
    
    return current;
}

/*
 * 
 */
void linked_list_destroy(linked_list* entry) {
    linked_list* last = entry->last;
    linked_list* next = entry->next;
    if (last != NULL && next != NULL) {
        last->next = next;
        next->last = last;
    }
    else if (last != NULL) {
        last->next = NULL;
    }
    if (next != NULL) {
        next->last = NULL;
    }
    free(entry);
}

/*
 * 
 */
int linked_list_size(linked_list* entry) {
    int count = 1;
    linked_list* begin = linked_list_begin(entry);
    while(begin->next != NULL) {
        begin = begin->next;
        count += 1;
    }
    return count;
}

/*
 * 
 */
void linked_list_for_all(linked_list* entry, void(*callback_func)(linked_list*)) {
    linked_list* begin = linked_list_begin(entry);
    do {
        (*callback_func)(begin);
        begin = begin->next;
    } while(begin != NULL);
}

