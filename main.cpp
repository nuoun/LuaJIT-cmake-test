#include <iostream>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int main() {
    // Create Lua state
    lua_State* L = luaL_newstate();
    
    // Load Lua libraries
    luaL_openlibs(L);
    
    // Run Lua
    const char* script = R"(
print(_VERSION)
print(jit.version)
)";
    if (luaL_dostring(L, script) != LUA_OK) {
        std::cerr << "Error running Lua script: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
    }

    // Close Lua state
    lua_close(L);
    
    return 0;
}