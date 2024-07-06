#include <iostream>
#include <lua.hpp>

int main() {
    // Create Lua state
    lua_State* L = luaL_newstate();

    // Load Lua libraries
    luaL_openlibs(L);

    // Define script
    const char* script = R"(
print(_VERSION)
print(jit.version)
)";

    // Run Lua
    if (luaL_dostring(L, script) != LUA_OK) {
        std::cerr << "Error running Lua script: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
    }

    // Close Lua state
    lua_close(L);

    return 0;
}
