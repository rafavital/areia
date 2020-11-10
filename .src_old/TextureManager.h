#pragma once
#include "Game.h"

class TextureManager {
public:
    static SDL_Surface* LoadSurface(const char* file);
    static bool TryDraw (SDL_Surface* src_surf, SDL_Surface* dst_surf, int x, int y);
private:

};