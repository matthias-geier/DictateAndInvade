
#include <core.h>

int core_mallocd = 0;

void* core_malloc(size_t size) {
    void* ptr;
    core_mallocd += 1;
    ptr = malloc(size);
    printf("Allocating %u bytes to %d. Total allocated amount of pointers: %d \n", size, ptr, core_mallocd);
    return ptr;
}

void core_free(void* ptr) {
    core_mallocd -= 1;
    printf("Deallocating %d. Total allocated amount of pointers: %d \n", ptr, core_mallocd);
    free(ptr);
}
