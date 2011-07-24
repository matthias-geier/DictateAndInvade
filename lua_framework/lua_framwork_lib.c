
#include <lua_framwork_lib.h>

int set_test_num(lua_State *L) {
    double d = luaL_checknumber(L, 1);
    my_test_number = d;
    return 0;
}

int lfw_open_cfunctions(lua_State *L) {
    luaL_openlib(L, "lfw", lfw_cfunctions, 0);
    return 1;
}

/*
 * 
 */
void call_lua_stack() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    int status = luaL_loadfile(L, "script2.lua");
    if (status) {
        /* If something went wrong, error message is at the top of */
        /* the stack */
        fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(L, -1));
        return;
        //exit(1);
    }
    lua_newtable(L);
    int i;
    for (i = 1; i <= 5; i++) {
        lua_pushnumber(L, i);
        lua_pushnumber(L, i*2);
        lua_rawset(L, -3);
    }
    lua_setglobal(L, "foo");
    //lua_pushcfunction(L, set_test_num);
    //lua_setglobal(L, "set_test_num");
    int result = lua_pcall(L, 0, LUA_MULTRET, 0);
    if (result) {
        fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
        //exit(1);
        return;
    }
    int s = 0;
    double* ptr;
    double* array = lua_transform_array_to_num(L, -1, &s);
    printf("Returned Size: %d\n", s);
    for (i=0; i<s; i++) {
        ptr = array + sizeof(double) * i;
        printf("Returned value for %d: %.1f\n", i, *ptr);
    }
    //double sum = lua_tonumber(L, -1);
    //printf("Script returned: %.0f\n", sum);
    //lua_pop(L, 1);
    
    printf("Script set: %.0f\n", my_test_number);
    lua_close(L);
}
