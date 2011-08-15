

#include <memory_management.h>

int core_mallocd = 0;

void* core_malloc(size_t size) {
    void* ptr;
    core_mallocd += 1;
    ptr = malloc(size);
    core_log("Allocating %u bytes to %d. Total allocated amount of pointers: %d", size, ptr, core_mallocd);
    return ptr;
}

void core_free(void* ptr) {
    core_mallocd -= 1;
    core_log("Deallocating %d. Total allocated amount of pointers: %d", ptr, core_mallocd);
    free(ptr);
}
