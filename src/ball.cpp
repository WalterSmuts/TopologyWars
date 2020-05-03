#include "ball.h"
#include "window.h"
#include <cmath>

Ball::Ball(int x, int y, int radius, int orbital_radius, float speed)
{
    this->x = 0;
    this->y = 0;
    this->x_center = x;
    this->y_center= y;
    this->radius = radius;
    this->orbital_radius = orbital_radius;
    this->speed = speed;
}

void Ball::draw(Window *window, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2+ x, this->y + window->getHeight()/2 - y);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2+ x, this->y + window->getHeight()/2 + y);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2- x, this->y + window->getHeight()/2 - y);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2- x, this->y + window->getHeight()/2 + y);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2+ y, this->y + window->getHeight()/2 - x);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2+ y, this->y + window->getHeight()/2 + x);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2- y, this->y + window->getHeight()/2 - x);
        SDL_RenderDrawPoint(renderer, this->x + window->getWidth()/2- y, this->y + window->getHeight()/2 + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Ball::update(int ticks){
    x = x_center + orbital_radius * sin(ticks * speed);
    y = y_center + orbital_radius * cos(ticks * speed);
}
