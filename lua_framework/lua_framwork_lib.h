
#ifndef LUA_FRAMEWORK_LIB_H
#define	LUA_FRAMEWORK_LIB_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>
#include "lua_transform_array.h"
#include <lauxlib.h>


double my_test_number = 0;

int set_test_num(lua_State *L);

const struct luaL_reg lfw_cfunctions [] = {
    {"set_test_num", set_test_num},
    {NULL, NULL}
};

int lfw_open_cfunctions(lua_State *L);

void call_lua_stack();

#endif	/* LUA_FRAMEWORK_LIB_H */

