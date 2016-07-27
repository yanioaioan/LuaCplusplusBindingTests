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
    float vecX = luaL_checknumber(L, 2);
    float vecY = luaL_checknumber(L, 3);
    float vecZ = luaL_checknumber(L, 4);
    return new TestClass(attribute , vecX, vecY, vecZ);
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


int TestClass_getAttributeVector(lua_State *L)
{
    TestClass* instance = luaW_check<TestClass>(L, 1);

    //contains the x,y,z coordinates of the ngl:vec3 vector
    float vectorArray[3];

    vectorArray[0]=instance->getAttributeVector().m_x;//x value of vector
    vectorArray[1]=instance->getAttributeVector().m_y;//y value of vector;
    vectorArray[2]=instance->getAttributeVector().m_z;//z value of vector
    lua_newtable(L);
    //push a table of 3 elements to Lua stack (practically the ngl::Vec3), and retrieve it from the LUA script back again (see testLua.lua)
      for(int i = 0;i < 3;i++)
      {
        lua_pushnumber(L,vectorArray[i]);
        lua_rawseti(L,-2,i + 1);
      }

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
    { "getAttributeVector", TestClass_getAttributeVector },

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


