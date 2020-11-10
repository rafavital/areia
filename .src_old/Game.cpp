#include <iostream> 
#include <SDL.h>
#include <vector>
#include "Game.h"
#include "Globals.h"
#include "Dependencies.h"
#include "TextureManager.h"

SDL_Event Game::event;
SDL_Window* Game::window = nullptr;
SDL_Surface* Game::display_surf = nullptr;
SDL_Surface* test_surf = nullptr;

Particle* test_particle = nullptr;

Particle* arr_grid[WIDTH][HEIGHT];

int count = 0;

void Game::init(const char* name, int x, int y, int w, int h)
{
    #pragma region BASE INIT
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    window = SDL_CreateWindow(name, x,y,w, h, 0);
    if (window)
        std::cout << "Window Created" << std::endl;
    else
    {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    display_surf = SDL_GetWindowSurface(window);
    if (display_surf)
        std::cout << "Surface Created" << std::endl;
    else
    {
        std::cout << "Failed to create surface: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    isRunning = true;
    #pragma endregion

    Particle::surf = TextureManager::LoadSurface("pixel.bmp");

    test_surf = TextureManager::LoadSurface("pixel.bmp");

    // for (auto i = 0; i < Particle::grid.size(); i++)
    // {
    //     Particle::grid[i] = new Particle(empty,Vector2D(0,0));
    // }
    

    for (int x = 0 ; x < WIDTH ; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            Particle::grid[x][y] = new Particle(empty, Vector2D(x,y));
        } 
    }

    for (int _x = 0; _x < WIDTH; _x++)
    {
        new Particle(sand_id, Vector2D(_x, 10));
    }

    std::cout << "Grid size: " << Particle::grid.size() << std::endl;
    
    int c = 0;
    // for (auto& p : Particle::grid)
    // {
    //     if (p != NULL)
    //         c++;
    // }

    for (int x = 0 ; x < WIDTH ; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            if (Particle::grid[x][y] != NULL)
                c++;
        } 
    }

    std::cout << "# of not null partices: " << c << std::endl;
    
}

void Game::handle_events ()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE);
            isRunning = false;
            return;
        break;
    case SDL_QUIT:
        isRunning = false;
        return;
        break;

    default:
        break;
    }
}

void Game::update()
{
    return;
    new Particle(sand_id, Vector2D(WIDTH / 2, 1));
    count++;
    //std::cout<<count<<std::endl;
    // for (auto p : Particle::grid)
    //     p->update();

}
void Game::render()
{
    return;
    SDL_FillRect(display_surf, NULL, 0);
    // for (int i = 0; i < Particle::grid.size(); i++)
    // {
    //     Particle* p = Particle::grid[i];
    //     TextureManager::TryDraw(test_surf, display_surf, p->x, p->y);
    // }
    
    for (auto& p : Particle::grid)
    {
        //std::cout << p->position.x << "," << p->position.y << std::endl;
        //TextureManager::TryDraw(test_surf, display_surf, p->position.x, p->position.y);
        //if (p != NULL)
            //p->draw();
    }

    SDL_UpdateWindowSurface(Game::window);
}
void Game::cleanup()
{
    SDL_FreeSurface(display_surf);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
bool Game::is_running ()
{
    return isRunning;
}