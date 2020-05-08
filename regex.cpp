#include <regex>
#include <lua.hpp>

int ismatch(lua_State *L){
    std::regex e;
    try{e = luaL_checkstring(L, 2);}catch(const std::regex_error&){luaL_error(L, "Invalid syntax of the regex");}
    lua_pushboolean(L, std::regex_match(luaL_checkstring(L, 1), e) ? true : false);
    return 1;
}

int match(lua_State *L){
    std::regex e;
    try{e = luaL_checkstring(L, 2);}catch(const std::regex_error&){luaL_error(L, "Invalid syntax of the regex");}
    std::cmatch m;
    lua_newtable(L);
    if(std::regex_match(luaL_checkstring(L, 1), m, e)){
        for(unsigned int i = 0; i < m.size(); i++){lua_pushnumber(L, i+1); lua_pushstring(L, std::string(m[i]).c_str()); lua_settable(L, -3);}
        return 1;
    }
    return 0;
}

int find(lua_State *L){
    std::regex e;
    try{e = luaL_checkstring(L, 2);}catch(const std::regex_error&){luaL_error(L, "Invalid syntax of the regex");}
    std::cmatch m;
    lua_newtable(L);
    if(std::regex_search(luaL_checkstring(L, 1), m, e)){
        for(unsigned int i = 0; i < m.size(); i++){lua_pushnumber(L, i+1); lua_pushstring(L, std::string(m[i]).c_str()); lua_settable(L, -3);}
        return 1;
    }
    return 0;
}

int replace(lua_State *L){
    std::regex e;
    try{e = luaL_checkstring(L, 2);}catch(const std::regex_error&){luaL_error(L, "Invalid syntax of the regex");}
    lua_pushstring(L, std::regex_replace(luaL_checkstring(L, 1), e, luaL_checkstring(L, 3)).c_str());
    return 1;
}

extern "C" {__declspec(dllexport) int luaopen_regex(lua_State *L){
    lua_newtable(L);

    lua_pushcfunction(L, ismatch);
    lua_setfield(L, -2, "ismatch");

    lua_pushcfunction(L, match);
    lua_setfield(L, -2, "match");

    lua_pushcfunction(L, find);
    lua_setfield(L, -2, "find");

    lua_pushcfunction(L, replace);
    lua_setfield(L, -2, "replace");

    return 1;
}}


