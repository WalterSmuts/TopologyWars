#include "block.h"
#include "window.h"
#include <math.h>

Block::Block()
{
    x = 0;
    y = 0;
    width = 50;
    height = 50;
}

int Block::getX()
{
    return x;
}

int Block::getY()
{
    return y;
}

void Block::draw(Window *window, SDL_Renderer *renderer)
{
    SDL_Rect fillRect = {
        window->getWidth()/2 - 50 + this->getY(),
        window->getHeight()/2 - 50 + this->getX(),
        width, height};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
}

void Block::update(int ticks){
    x = 200*sin(ticks*0.01);
    y = 200*cos(ticks*0.01);
}
