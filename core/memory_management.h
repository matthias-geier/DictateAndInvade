

#ifndef MEMORY_MANAGEMENT_H
#define	MEMORY_MANAGEMENT_H


#include <stdlib.h>
#include <stdio.h>
#include <logging.h>

extern int core_mallocd;



/**
 * wrapper for malloc
 * uses console output and counters to keep track of all allocated memory
 * 
 * @param size:                 size of memory block
 * @return:                     pointer to memory block
 */
void* core_malloc(size_t size);



/**
 * wrapper for free
 * uses console output and counters to keep track of all allocated memory
 * 
 * @param ptr:                  pointer to memory block
 */
void core_free(void* ptr);

#endif	/* MEMORY_MANAGEMENT_H */

