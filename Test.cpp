#include "Test.h"
#include<stdio.h>
extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

int main()
{
    int a = 10;
    int b = 20;
    printf("%d %d\n", a, b);

    lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, "script.lua");

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
