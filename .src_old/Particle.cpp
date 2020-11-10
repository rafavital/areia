#include <iostream>
#include "Particle.h"
#include "TextureManager.h"
#include "Globals.h"

//std::vector<Particle*> Particle::grid = std::vector<Particle*>(HEIGHT*WIDTH*sizeof (Particle));
//std::vector<Particle*> Particle::grid;
std::vector<std::vector<Particle*>> Particle::grid;
SDL_Surface* Particle::surf = nullptr;

Particle::Particle(mat_type_id _id, Vector2D pos)
{
    mat_type_id id = _id;
    position = pos;
    //std::cout << x << "," << y << std::endl;
    //Particle::grid[(y*WIDTH) + x] = this;
    //grid.push_back(this);
}

void Particle::update ()
{
//        auto& l = Particle::grid[(position.y+1 * WIDTH) + position.x-1];
//        auto& r = Particle::grid[(position.y+1 * WIDTH) + position.x+1];
//        auto& d = Particle::grid[(position.y+1 * WIDTH) + position.x];
//
//        if (d != NULL)
//        {
//            if (d->id == empty)
//                position.y++;
//        } else if (l != NULL)
//        {
//            if (l->id == empty)
//            {
//                position.y++;
//                position.x--;
//            }
//        }
//        else if (r != NULL)
//        {
//            if (r->id == empty)
//            {
//                position.y++;
//                position.x++;
//            }
//        } 
//    return;
}

void Particle::draw ()
{
    TextureManager::TryDraw(
        Particle::surf, 
        Game::display_surf, 
        static_cast<int> (this->position.x), 
        static_cast<int> (this->position.y)
    );
}