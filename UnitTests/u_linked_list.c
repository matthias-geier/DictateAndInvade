
#include <u_linked_list.h>

void u_linked_list(void) {
    linked_list* list;
    int* a = (int*)core_malloc(sizeof(int)); *a = 5;
    int* b = (int*)core_malloc(sizeof(int)); *b = 3;
    int* c = (int*)core_malloc(sizeof(int)); *c = 1;
    int* d = (int*)core_malloc(sizeof(int)); *d = 10;
    int* e = (int*)core_malloc(sizeof(int)); *e = 11;
    
    core_log("Unit tests: Linked list");
    
    core_log("-Create, set, loop, destroy");
    list = linked_list_create(a);
    assert(*((int*)list->value) == 5);
    assert(list->next == NULL);
    assert(list->last == NULL);
    
    list = linked_list_create_and_insert_after(list, b);
    assert(*((int*)list->value) == 3);
    assert(list->next == NULL);
    assert(list->last != NULL);
    
    list = linked_list_create_and_insert_after(list, e);
    assert(*((int*)list->value) == 11);
    assert(list->next == NULL);
    assert(list->last != NULL);
    
    list = linked_list_begin(list);
    assert(*((int*)list->value) == 5);
    assert(list->next != NULL);
    assert(list->last == NULL);
    
    list = linked_list_get(list, 1);
    assert(*((int*)list->value) == 3);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    list = linked_list_create_and_insert_after(list, c);
    assert(*((int*)list->value) == 1);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    list = linked_list_create_and_insert_after(list, d);
    assert(*((int*)list->value) == 10);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    list = linked_list_get(list, 2);
    assert(*((int*)list->value) == 1);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    linked_list_for_all(list, &u_linked_list_forall);
    
    list = linked_list_destroy(list, NULL);
    assert(*((int*)list->value) == 10);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    linked_list_set(list, 1, c);
    list = list->last;
    assert(*((int*)list->value) == 1);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    list = linked_list_create_and_insert_after(list->last, b);
    assert(*((int*)list->value) == 3);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    linked_list_for_all(list, &u_linked_list_forall);
    
    assert(linked_list_size(list) == 5);
    
    core_log("--Destroy by parameter");
    list = linked_list_destroy(list, &u_linked_list_destructor1);
    assert(*((int*)list->value) == 1);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    assert(linked_list_size(list) == 4);
    
    core_log("--Destroy by destruct pointer");
    list->destroy_ptr = &u_linked_list_destructor2;
    list = linked_list_destroy(list, NULL);
    assert(*((int*)list->value) == 10);
    assert(list->next != NULL);
    assert(list->last != NULL);
    
    core_log("--Destroy by priority");
    list->destroy_ptr = &u_linked_list_destructor2;
    list = linked_list_destroy(list, &u_linked_list_destructor1);
    assert(*((int*)list->value) == 11);
    assert(list->next == NULL);
    assert(list->last != NULL);
    
    list = linked_list_begin(list);
    while (list != NULL) {
        list = linked_list_destroy(list, &u_linked_list_destructor1);
    }
    
    assert(core_mallocd == 0);
    
    /*a = (int*)core_malloc(sizeof(int)); *a = 5;
    b = (int*)core_malloc(sizeof(int)); *b = 3;
    c = (int*)core_malloc(sizeof(int)); *c = 1;
    d = (int*)core_malloc(sizeof(int)); *d = 10;
    e = (int*)core_malloc(sizeof(int)); *e = 11;*/
    
    
    
    core_log("Unit tests: Linked list //END");
}

void u_linked_list_destructor1(void** content) {
    core_log("Destructor 1: %d", *content);
    core_free(*content);
}

void u_linked_list_destructor2(void** content) {
    core_log("Destructor 2: %d", *content);
    core_free(*content);
}

void u_linked_list_forall(linked_list* entry) {
    int* item = (int*)entry->value;
    core_log("--Item %d", *item);
}
