



#include "game.h"
#include <stdio.h>


int main(int argc,char *argv[])
{
    GameInit();
    Window *window = WindowCreate_("Game",800,600);
    WindowMainLoop(1,window);
    
    return 0;
}





