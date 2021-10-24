


#include "../../include/Lua/lua.hpp"


#ifndef GAL_LUA_HEAD
#define GAL_LUA_HEAD

class GalLua
{
private:
    lua_State *l;
public:
    GalLua();
    GalLua(lua_State *l);
    ~GalLua();

    void AddInteger(const char *name,int data);
    void AddBoolean(const char *name,bool data);
    void AddString(const char *name,const char *data);
    void RegisterFunction(const char *function_name,lua_CFunction function);

    void AddUserData(void *data);

    lua_State *GetL();
};




#endif


