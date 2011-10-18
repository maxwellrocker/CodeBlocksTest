#include "Test.h"
#include<stdio.h>
#include<string>
extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

static int SayHello(lua_State* L){
    const char* Name = lua_tostring(L, 1);
    std::string Hello = "Hello! ";
    Hello += Name;
    lua_pushstring(L, Hello.c_str());
    return 1;
}

int main()
{
    int a = 10;
    int b = 20;
    printf("%d %d\n", a, b);

    lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "SayHello", SayHello);
	luaL_dofile(L, "script.lua");

    /**/
	lua_getglobal(L, "plus");
	lua_pushnumber(L, 10);
	lua_pushnumber(L, 5);
	lua_pcall(L, 2, 1, 0);
	printf("%d", (int)lua_tonumber(L, -1));
	lua_pop(L, 1);

	char buff[256];
	while(fgets(buff, sizeof(buff), stdin) != NULL)
	{
		printf(buff);
	}

	lua_close(L);

    return 0;
}



/*
int main(void)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, "script.lua");

	char buff[256];
	int error;
	while(fgets(buff, sizeof(buff), stdin) != NULL)
	{
		printf(buff);
	}

	lua_close(L);
	return 0;
}
*/
