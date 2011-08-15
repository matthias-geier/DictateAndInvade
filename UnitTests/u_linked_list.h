

#ifndef U_LINKED_LIST_H
#define	U_LINKED_LIST_H

#include <assert.h>
#include <logging.h>
#include <memory_management.h>
#include <linked_list.h>


void u_linked_list(void);

void u_linked_list_destructor1(void** content);

void u_linked_list_destructor2(void** content);

void u_linked_list_forall(linked_list* entry);

#endif	/* U_LINKED_LIST_H */

