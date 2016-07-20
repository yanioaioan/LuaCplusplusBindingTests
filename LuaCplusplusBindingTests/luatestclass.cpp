#include "testclass.h"


#include <iostream>
#include <string>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}
#include "luawrapper.hpp"


using namespace std;

//
// Allocator
//
// Types that do not have a default contructor require you to write an allocator function.
// This function is passed to luaW_register.
//

TestClass* TestClass_new(lua_State *L)
{
    int attribute = luaL_checknumber(L, 1);
    //    const char* another attribute = luaL_checkstring(L, 2);
    return new TestClass(attribute);
}


//
// Member Functions
//
// These functions are stored on the TestClass.metatable table.
// All TestClass objects in Lua have access to the functions defined there
// by the use of special a __index metatmethod that is set up by LuaWrapper.
//

int TestClass_getAttribute(lua_State *L)
{
    TestClass* instance = luaW_check<TestClass>(L, 1);
    lua_pushinteger(L, instance->getAttribute());
    return 1;
}

static luaL_Reg TestClass_table[] =
{
    { NULL, NULL }
};

static luaL_Reg TestClass_metatable[] =
{
    //the string getAttribute NEEDS to BE SPELLED PROPERLY based on TestClass function definition
    { "getAttribute", TestClass_getAttribute },

    { NULL, NULL }
};

int luaopen_TestClass(lua_State* L)
{
    luaW_register<TestClass>(L,
        "TestClass",
        TestClass_table,
        TestClass_metatable,
        TestClass_new // If your class has a default constructor you can omit this argument,
                        // LuaWrapper will generate a default allocator for you.
    );
    return 1;
}

