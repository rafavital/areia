#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Game
{
public:
    static SDL_Event event;
    static SDL_Renderer* renderer;
    static SDL_Surface* display_surf;
    static SDL_Window* window;
public:
    void init(const char* name, int x, int y, int w, int h);
    void handle_events();
    void update();
    void render();
    void cleanup();
    bool is_running();
private:
    bool isRunning;
};