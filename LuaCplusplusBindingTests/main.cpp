#include <iostream>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "luatestclass.h"
#include <luawrapper.hpp>

using namespace std;


int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_TestClass(L);
    if (luaL_loadfile(L, "testLua.lua")) {
        std::cout<<"Error, can't open script"<<std::endl;
    }

    lua_pcall(L, 0, 0, 0);
}
