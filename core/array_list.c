

#include <array_list.h>

void* array_list_get(array_list* list, int pos) {
    return (pos < list->max_elements) ? *(list->array + pos) : NULL;
}

void array_list_set(array_list* list, int pos, void* content) {
    int num_elements = list->num_elements;
    
    core_log("Setting array list %d content on position %d to %d", list, pos, content);
    
    // increase or decrease element number when necessary
    if (pos + 1 > list->num_elements) {
        core_log("Increasing array list %d element count from %d to %d", list, list->num_elements, pos + 1);
        list->num_elements = pos + 1;
    }
    else if (pos + 1 == list->num_elements && content == NULL) {
        int find_pos = pos;
        while (find_pos-1 >= 0) {
            find_pos -= 1;
            if (*(list->array + find_pos) != NULL) {
                break;
            }
        }
        core_log("Decreasing array list %d element count by %d", list, pos - find_pos);
        list->num_elements = find_pos + 1;
    }
    
    // increase or decrease array size when necessary
    if (pos + 1 + list->extend_by > list->max_elements) {
        // increase
        int i;
        int n_size = pos + 1 + list->extend_by + 10; // add 10 for safety
        void** arr = (void**)core_malloc(sizeof(void*) * n_size);

        core_log("Allocating larger array %d of size %d", arr, n_size);

        // copy elements
        for (i=0; i<n_size; i++) {
            //core_log("--Item at %d: %d", i, *(list->array + i));
            *(arr + i) = (i<num_elements) ? *(list->array + i) : NULL;
        }

        core_free(list->array);
        list->array = arr;
        list->max_elements = n_size;
    }
    else if (list->num_elements <= list->max_elements - list->extend_by * 2 - 10) {
        // decrease
        int i;
        int n_size = list->num_elements + list->extend_by + 10; // add 10 for safety
        void** arr = (void**)core_malloc(sizeof(void*) * n_size);

        core_log("Allocating smaller array %d of size %d", arr, n_size);

        // copy elements
        for (i=0; i<n_size; i++) {
            *(arr + i) = *(list->array + i);
        }

        core_free(list->array);
        list->array = arr;
        list->max_elements = n_size;
    }
    
    // set content
    *(list->array + pos) = content;
}

array_list* array_list_create(int initial_size, int extend_by) {
    int i;
    int i_size = (initial_size > 0) ? initial_size : ARRAY_LIST_INIT_SIZE;
    int e_by = (extend_by > 0) ? extend_by : ARRAY_LIST_EXTEND_BY;
    array_list* list = (array_list*)core_malloc(sizeof(array_list));
    
    core_log("Creating array list %d of initial size %d and extend by %d", list, i_size, e_by);
    
    list->num_elements = 0;
    list->extend_by = e_by;
    list->max_elements = i_size;
    list->destroy_ptr = NULL;
    list->array = (void**)core_malloc(sizeof(void*) * i_size);
    
    // initialize with NULL
    for (i=0; i<i_size; i++) {
        *(list->array + i) = NULL;
    }
    
    return list;
}

void array_list_destroy(array_list* list, void (*processor)(void**)) {
    int i;
    
    core_log("Destroying array list %d", list);
    
    for (i=0; i<list->num_elements; i++) {
        void* element = *(list->array + i);
        if (element != NULL) {
            if (processor != NULL) {
                (*processor)(&element);
            }
            else if (list->destroy_ptr != NULL) {
                (*(list->destroy_ptr))(&element);
            }
            *(list->array + i) = NULL;
        }
    }
    
    list->num_elements = 0;
    
    core_free(list->array);
    core_free(list);
}

int array_list_size(array_list* list) {
    return list->num_elements;
}

void array_list_for_all(array_list* list, void (*callback_func)(int, void*)) {
    int i;
    
    for (i=0; i<list->num_elements; i++) {
        void* element = *(list->array + i);
        if (element != NULL) {
            (*callback_func)(i, element);
        }
    }
}
