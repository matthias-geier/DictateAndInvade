
#ifndef CORE_H
#define	CORE_H

#include <stdlib.h>
#include <stdio.h>

extern int core_mallocd;

void* core_malloc(size_t size);

void core_free(void* ptr);

#endif	/* CORE_H */

