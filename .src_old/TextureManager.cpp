#include <iostream>
#include "TextureManager.h"
#include "Game.h"

SDL_Surface* TextureManager::LoadSurface(const char* file)
{
    SDL_Surface* temp_surf = nullptr;
    SDL_Surface* return_surf = nullptr;

    if ((temp_surf = SDL_LoadBMP(file)) == NULL)
    {
        std::cout << "Error : " << SDL_GetError() << std::endl;
        return NULL;
    }

    return_surf = SDL_ConvertSurfaceFormat(temp_surf, SDL_PIXELFORMAT_RGBA32,0);
    SDL_FreeSurface(temp_surf);
    
    return return_surf;
}

bool TextureManager::TryDraw(SDL_Surface* src_surf, SDL_Surface* dst_surf, int x, int y)
{
    if (src_surf == NULL || dst_surf == NULL)
    {
        //std::cout << "TextureManager::TryDraw was fed a null surface" << std::endl;
        return false;
    }

    SDL_Rect dst_rect;
    dst_rect.h = dst_rect.w = 1;

    dst_rect.x = x;
    dst_rect.y = y;

    SDL_BlitSurface(src_surf, NULL, dst_surf, &dst_rect);

    return true;
}