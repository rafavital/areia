#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
#include "Globals.h"

Game* game = nullptr;
const int FPS = 60;

int main ()
{
    uint32_t game_start;
    int delta;
    int frameDelay = 1000/FPS;
    game = new Game();
    
    game->init("sandbox", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT);    

    while (game->is_running())
    {       
        game_start = SDL_GetTicks();
        game->handle_events();
        game->update();
        game->render();
        delta = SDL_GetTicks () - game_start;

        if (frameDelay > delta)
            SDL_Delay(frameDelay);
    }

    game->cleanup();
    
    return 0;
}