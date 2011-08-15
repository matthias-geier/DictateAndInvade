
#include <u_array_list.h>

void u_array_list(void) {
    array_list* arr;
    int i;
    int* a = (int*)core_malloc(sizeof(int)); *a = 5;
    int* b = (int*)core_malloc(sizeof(int)); *b = 3;
    int* c = (int*)core_malloc(sizeof(int)); *c = 1;
    int* d = (int*)core_malloc(sizeof(int)); *d = 10;
    int* e = (int*)core_malloc(sizeof(int)); *e = 11;
    
    core_log("Unit tests: Array list");
    
    core_log("-Create, destroy, default init/extend sizes");
    arr = array_list_create(-1, -1);
    assert(arr->max_elements == ARRAY_LIST_INIT_SIZE);
    assert(arr->extend_by == ARRAY_LIST_EXTEND_BY);
    array_list_destroy(arr, NULL);
    
    core_log("\n\n-Create, custom init/extend sizes");
    arr = array_list_create(5, 5);
    assert(arr->max_elements == 5);
    assert(arr->extend_by == 5);
    
    core_log("\n--Set content, view extension");
    array_list_set(arr, 0, (void*)a);
    assert(*((int*)array_list_get(arr, 0)) == 5);
    assert(array_list_size(arr) == 1);
    assert(arr->max_elements == 16);
    
    array_list_set(arr, 1, (void*)b);
    assert(*((int*)array_list_get(arr, 1)) == 3);
    assert(array_list_size(arr) == 2);
    assert(arr->max_elements == 16);
    
    array_list_set(arr, 2, (void*)c);
    assert(*((int*)array_list_get(arr, 2)) == 1);
    assert(array_list_size(arr) == 3);
    assert(arr->max_elements == 16);
    
    array_list_set(arr, 24, (void*)e);
    assert(*((int*)array_list_get(arr, 24)) == 11);
    assert(array_list_size(arr) == 25);
    assert(arr->max_elements == 40);
    
    array_list_set(arr, 3, (void*)d);
    assert(*((int*)array_list_get(arr, 3)) == 10);
    assert(array_list_size(arr) == 25);
    assert(arr->max_elements == 40);
    
    array_list_set(arr, 24, NULL);
    assert(array_list_get(arr, 24) == NULL);
    assert(array_list_size(arr) == 4);
    assert(arr->max_elements == 19);
    
    array_list_set(arr, 5, (void*)e);
    assert(*((int*)array_list_get(arr, 5)) == 11);
    assert(array_list_size(arr) == 6);
    assert(arr->max_elements == 19);
    
    core_log("\n--Loop");
    array_list_for_all(arr, &u_array_list_forall);
    
    core_log("\n-Destruction");
    array_list_destroy(arr, NULL);
    
    core_free(a);
    core_free(b);
    core_free(c);
    core_free(d);
    core_free(e);
    
    assert(core_mallocd == 0);
    
    a = (int*)core_malloc(sizeof(int)); *a = 5;
    b = (int*)core_malloc(sizeof(int)); *b = 3;
    c = (int*)core_malloc(sizeof(int)); *c = 1;
    d = (int*)core_malloc(sizeof(int)); *d = 10;
    e = (int*)core_malloc(sizeof(int)); *e = 11;
    
    core_log("\n\n-Create, destroy, destructor by parameter");
    arr = array_list_create(-1, -1);
    assert(arr->max_elements == ARRAY_LIST_INIT_SIZE);
    assert(arr->extend_by == ARRAY_LIST_EXTEND_BY);
    array_list_set(arr, 0, (void*)a);
    array_list_set(arr, 1, (void*)b);
    array_list_set(arr, 2, (void*)c);
    array_list_set(arr, 3, (void*)d);
    array_list_set(arr, 4, (void*)e);
    array_list_destroy(arr, &u_array_list_destructor1);
    
    assert(core_mallocd == 0);
    
    a = (int*)core_malloc(sizeof(int)); *a = 5;
    b = (int*)core_malloc(sizeof(int)); *b = 3;
    c = (int*)core_malloc(sizeof(int)); *c = 1;
    d = (int*)core_malloc(sizeof(int)); *d = 10;
    e = (int*)core_malloc(sizeof(int)); *e = 11;
    
    core_log("\n\n-Create, destroy, destructor by struct pointer");
    arr = array_list_create(-1, -1);
    arr->destroy_ptr = &u_array_list_destructor2;
    assert(arr->max_elements == ARRAY_LIST_INIT_SIZE);
    assert(arr->extend_by == ARRAY_LIST_EXTEND_BY);
    array_list_set(arr, 0, (void*)a);
    array_list_set(arr, 1, (void*)b);
    array_list_set(arr, 2, (void*)c);
    array_list_set(arr, 3, (void*)d);
    array_list_set(arr, 4, (void*)e);
    array_list_destroy(arr, NULL);
    
    assert(core_mallocd == 0);
    
    a = (int*)core_malloc(sizeof(int)); *a = 5;
    b = (int*)core_malloc(sizeof(int)); *b = 3;
    c = (int*)core_malloc(sizeof(int)); *c = 1;
    d = (int*)core_malloc(sizeof(int)); *d = 10;
    e = (int*)core_malloc(sizeof(int)); *e = 11;
    
    core_log("\n\n-Create, destroy, destructor by priority");
    arr = array_list_create(-1, -1);
    arr->destroy_ptr = &u_array_list_destructor2;
    assert(arr->max_elements == ARRAY_LIST_INIT_SIZE);
    assert(arr->extend_by == ARRAY_LIST_EXTEND_BY);
    array_list_set(arr, 0, (void*)a);
    array_list_set(arr, 1, (void*)b);
    array_list_set(arr, 2, (void*)c);
    array_list_set(arr, 3, (void*)d);
    array_list_set(arr, 4, (void*)e);
    array_list_destroy(arr, &u_array_list_destructor1);
    
    assert(core_mallocd == 0);
    
    core_log("Unit tests: Array list //END");
}

void u_array_list_destructor1(void** content) {
    core_log("Destructor 1: %d", *content);
    core_free(*content);
}

void u_array_list_destructor2(void** content) {
    core_log("Destructor 2: %d", *content);
    core_free(*content);
}

void u_array_list_forall(int pos, void* content) {
    int* item = (int*)content;
    core_log("--Item at %d: %d", pos, *item);
}
