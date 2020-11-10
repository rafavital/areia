#include <iostream>
#include "SDL.h"
#include <vector>

#define FPS 60;

const int WIDTH = 480;
const int HEIGHT = 320;

SDL_Surface* window_surf = nullptr;
SDL_Surface* pixel_surf = nullptr;
SDL_Window* window = nullptr;
SDL_Event event;

enum mat_type_id {
    empty = 0,
    sand = 1
};

struct Particle {
  mat_type_id material;  
  bool has_been_updated;

  Particle(mat_type_id mat)
  {
      material = mat;
  }
};

//std::vector<mat_type_id> grid = std::vector<mat_type_id>(WIDTH * HEIGHT * sizeof(mat_type_id));
Particle* grid[WIDTH][HEIGHT];

void update_sand(Particle& p, int x, int y);

int main ()
{
    uint32_t frame_start_time = 0;
    uint32_t delta = 0;
    uint32_t frame_delay = 1000 / FPS;
    SDL_Rect pixel_rect;

    bool isRunning = false;

    #pragma region SDL INIT
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Initialization Error: " << SDL_GetError() << std::endl;
        return 1;
    }else 
    {
        std::cout << "SDL Initialized" << std::endl;
    }
    window = SDL_CreateWindow("areia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (window)
    {
        std::cout << "Window Created" << std::endl;
    } else
    {
        std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
        return 2;
    }
    window_surf = SDL_GetWindowSurface (window);
    pixel_surf = SDL_LoadBMP ("pixel.bmp");
    


    isRunning = true;
    #pragma endregion

    grid[WIDTH/2][HEIGHT/2 - 9] = new Particle(sand);
    grid[WIDTH/2][HEIGHT/2 - 5] = new Particle(sand);
    grid[WIDTH/2][HEIGHT/2] = new Particle(sand);

    #pragma region Game Loop
    while (isRunning)
    {
        frame_start_time = SDL_GetTicks ();

        #pragma region EVENT HANDLING
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT :
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                //std::cout << "Mouse Pos: " << x << "," << y << std::endl;
                auto& p = grid[x][y];
                if (p == NULL)
                    p = new Particle(sand);
                else
                    p->material = sand;
                
            }
            break;
        default:
            break;
        }
        #pragma endregion

        #pragma region UPDATE

        for (auto y = HEIGHT; y > 0; y--)
        {
            for (auto x = 0; x < WIDTH; x++)
            {
                auto& particle = grid[x][y];
                if (particle == NULL)
                    continue;
                switch (particle->material)
                {
                case sand:
                    update_sand(*particle, x, y);
                    
                    break;
                
                default:
                    break;
                }
            }
            
        }

        #pragma endregion

        #pragma region RENDERING
        SDL_FillRect(window_surf, NULL, 0);
        for (auto y = HEIGHT; y > 0; y--)
        {
            for (auto x = 0; x < WIDTH; x++)
            {
                auto& p = grid[x][y];
                if (p == NULL)
                    continue;

                if (p->material == empty)
                    continue;

                pixel_rect.x = x;
                pixel_rect.y = y;
                SDL_BlitSurface(pixel_surf, NULL, window_surf, &pixel_rect);
            }
            
        }
        
        SDL_UpdateWindowSurface(window);
        #pragma endregion

        delta = SDL_GetTicks () - frame_start_time;
        if (frame_delay > delta)
            SDL_Delay(frame_delay - delta);
    }
    #pragma endregion

    SDL_FreeSurface(window_surf);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void update_sand(Particle& p, int x, int y)
{
    if (y == HEIGHT - 1)
        return;

    auto& down_neigh = grid[x][y+1];
    auto& left_neigh = grid[x-1][y+1];
    auto& right_neigh = grid[x+1][y+1];

    if (down_neigh == NULL)
    {
        down_neigh = new Particle(sand);
        p.material = empty;
    } else if (down_neigh->material == empty)
    {
        down_neigh->material = sand;
        p.material = empty;
    } else if (left_neigh == NULL) 
    { 
        left_neigh = new Particle(sand);
        p.material = empty;
    } else if (left_neigh->material == empty)
    {
        left_neigh->material = sand;
        p.material = empty;
    } else if (right_neigh == NULL) 
    { 
        right_neigh = new Particle(sand);
        p.material = empty;
    } else if (right_neigh->material == empty)
    {
        right_neigh->material = sand;
        p.material = empty;
    }

    // mat_type_id l;
    // mat_type_id d;
    // mat_type_id r;
    // if (x > 0 && y < HEIGHT)
    //     l = grid[((y+1) * WIDTH) + (x-1)];
    // if (x < WIDTH && y < HEIGHT)
    //     r = grid[((y+1) * WIDTH) + (x+1)];
    // if (y < HEIGHT)
    //     d = grid[((y+1) * WIDTH) + (x)];

    // if (y < HEIGHT && d == empty)
    // {
    //     grid[(y*WIDTH) + x] = empty;
    //     grid[((y+1) * WIDTH) + (x)] = mat;
    // } else if (x > 0 && l == empty)
    // {
    //     grid[(y*WIDTH) + x] = empty;
    //     grid[((y+1) * WIDTH) + (x-1)] = mat;
    // } else if (x < WIDTH && r == empty)
    // {
    //     grid[(y*WIDTH) + x] = empty;
    //     grid[((y+1) * WIDTH) + (x+1)] = mat;
    // }
}