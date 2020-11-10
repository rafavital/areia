#pragma once
#include <SDL.h>
#include <vector>
#include <array>

#include "Vector2D.h"
#include "Color.h"

enum mat_type_id
{
    empty = 0,
    sand_id = 1
};

class Particle
{
public:
    static std::vector<Particle*> _grid;
    static std::vector<std::vector<Particle*>> grid;
    static SDL_Surface *surf;
public:
    Vector2D position;
    mat_type_id id;
    bool has_been_updated;

    Particle(mat_type_id _id, Vector2D pos);
    void update ();
    void draw();
};