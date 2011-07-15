module(..., package.seeall);

path = "../lua_framework/dist/Release/GNU-Linux-x86/liblua_framework.so";
io.write("Libpath: " .. path .. "\n");
lfw_func = package.loadlib(path, "lfw_open_cfunctions");
lfw = lfw_func();