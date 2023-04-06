#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int dump_writer(lua_State *L, const void *p, size_t size, void *ud){
    unsigned char *string = (unsigned char*)p;
    for(int i = 0; i < size; i++){
        printf("%02x ", string[i]);    
    }
    printf("\n");
    return 0;
}

int compile(const char* fonte){
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);

    int res = luaL_loadstring(state, fonte);

    // eu acho que isso está errado, mas deixa pra lá por enquanto. funciona e faz o que eu quero.
    if(res != 0){
        size_t len = 0;
        const char* value = lua_tolstring(state, lua_gettop(state), &len);
        printf("%s\n", value);
    }else{
        lua_dump(state, dump_writer, NULL ,0);
    }

    lua_close(state);
    return res;
}

int run(const char* fonte){
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);
    int res = luaL_dostring(state, fonte);
    
    if(res != nil){
        size_t len = 0;
        const char* value = lua_tolstring(state, lua_gettop(state), &len);
        printf("%s\n", value);
    }

    lua_close(state);
    return res;
}
