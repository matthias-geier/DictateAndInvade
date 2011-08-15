


#include <linked_list.h>


linked_list* linked_list_begin(linked_list* entry) {
    linked_list* current = entry;
    while(current->last != NULL) {
        current = current->last;
    }
    return current;
}

linked_list* linked_list_create(void* value) {
    linked_list* entry = (linked_list*)core_malloc(sizeof(linked_list));
    
    core_log("Creating linked list entry %d with initial content %d", entry, value);
    
    entry->value = value;
    entry->next = NULL;
    entry->last = NULL;
    entry->destroy_ptr = NULL;
    
    return entry;
}

linked_list* linked_list_create_and_insert_after(linked_list* entry, void* value) {
    linked_list* current = linked_list_create(value);
    
    core_log("Creating linked list entry %d with initial content %d and insert it after entry %d", current, value, entry);
    
    if (entry->next != NULL) {
        current->next = entry->next;
        current->last = entry;
        entry->next->last = current;
        entry->next = current;
    }
    else {
        entry->next = current;
        current->last = entry;
    }
    
    return current;
}

linked_list* linked_list_destroy(linked_list* entry, void (*processor)(void**)) {
    core_log("Destroying linked list entry %d", entry);
    
    linked_list* last = entry->last;
    linked_list* next = entry->next;
    if (last != NULL && next != NULL) {
        last->next = next;
        next->last = last;
    }
    else if (last != NULL) {
        last->next = NULL;
    }
    else if (next != NULL) {
        next->last = NULL;
    }
    
    if (processor != NULL) {
        void* value = entry->value;
        (*processor)(&value);
    }
    else if (entry->destroy_ptr != NULL) {
        void* value = entry->value;
        (*(entry->destroy_ptr))(&value);
    }
    
    core_free(entry);
    
    return (next != NULL) ? next : last;
}

int linked_list_size(linked_list* entry) {
    int count = 1;
    linked_list* begin = linked_list_begin(entry);
    while(begin->next != NULL) {
        begin = begin->next;
        count += 1;
    }
    return count;
}

void linked_list_for_all(linked_list* entry, void (*callback_func)(linked_list*)) {
    linked_list* begin = linked_list_begin(entry);
    do {
        (*callback_func)(begin);
        begin = begin->next;
    } while(begin != NULL);
}

void linked_list_set(linked_list* entry, int pos, void* value) {
    int i;
    linked_list* begin = linked_list_begin(entry);
    
    // ends with element 1 in the first loop
    for (i=1; i<=pos; i++) {
        begin = begin->next;
        if (begin == NULL) {
            break;
        }
    }
    
    if (begin != NULL) {
        begin->value = value;
    }
}

linked_list* linked_list_get(linked_list* entry, int pos) {
    int i;
    linked_list* begin = linked_list_begin(entry);
    
    // ends with element 1 in the first loop
    for (i=1; i<=pos; i++) {
        begin = begin->next;
        if (begin == NULL) {
            break;
        }
    }
    
    return begin;
}


