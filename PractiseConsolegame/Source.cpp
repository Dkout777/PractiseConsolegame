
#include "GameMap.h"
#include "Game.h"
int main()
{
   //init Game engine
    Game game;

 

    while (game.running())
    {
        game.update();
        game.render();

       
    }
}