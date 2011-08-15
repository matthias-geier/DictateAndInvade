

#ifndef U_ARRAY_LIST_H
#define	U_ARRAY_LIST_H

#include <assert.h>
#include <logging.h>
#include <memory_management.h>
#include <array_list.h>

void u_array_list(void);

void u_array_list_destructor1(void** content);

void u_array_list_destructor2(void** content);

void u_array_list_forall(int pos, void* content);

#endif	/* U_ARRAY_LIST_H */

