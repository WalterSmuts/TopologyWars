#include "block.h"
#include "window.h"
#include <cmath>

Block::Block(int x, int y, int width, int height, int radius, float speed)
{
    this->x = 0;
    this->y = 0;
    this->x_center = x;
    this->y_center= y;
    this->width = width;
    this->height = height;
    this->radius = radius;
    this->speed = speed;
}

void Block::draw(Window *window, SDL_Renderer *renderer)
{
    SDL_Rect fillRect = {
        window->getWidth()/2 - width/2 + y,
        window->getHeight()/2 - height/2 + x,
        width, height};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
}

void Block::update(int ticks){
    x = x_center + radius*sin(ticks*speed);
    y = y_center + radius*cos(ticks*speed);
}
