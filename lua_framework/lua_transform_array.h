
#ifndef LUA_TRANSFORM_ARRAY_H
#define	LUA_TRANSFORM_ARRAY_H

#include <core.h>
#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <lauxlib.h>

double* lua_transform_array_to_num(lua_State* L, int stack_pos, int* size);
int lua_transform_num_to_array(lua_State* L, double* array, int* size);

#endif	/* LUA_TRANSFORM_ARRAY_H */

