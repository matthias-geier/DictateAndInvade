
#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <lua_transform_array.h>

double* lua_transform_array_to_num(lua_State* L, int stack_pos, int* size) {
    int i;
    double* ptr;
    *size = luaL_getn(L, stack_pos);
    printf("Got Size: %d\n", *size);
    double* array = (double*)malloc(sizeof(double) * (*size));
    for (i = 0; i < *size; i++) {
        ptr = array + sizeof(double) * i;
        lua_rawgeti(L, stack_pos, i);
        *ptr = lua_tonumber(L, -1);
        //printf("Got Number: %.1f\n", *ptr);
        lua_pop(L, 1);
    }
    return array;
}

int lua_transform_num_to_array(lua_State* L, double* array, int* size) {
    int i;
    double* ptr;
    lua_checkstack(L, 2);
    for (i = 0; i < *size; i++) {
        ptr = array + sizeof(double) * i;
        lua_pushnumber(L, *ptr);
        lua_rawseti(L, -2, i);
        free(ptr);
    }
    *size = 0;
    return lua_gettop(L);
}
