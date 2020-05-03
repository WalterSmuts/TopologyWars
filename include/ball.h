#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "window.h"
#include <list>

class Window;
class Ball
{
    public:
    Ball(int x, int y, int radius, int orbital_radius, float speed);
    void update(int ticks);
    void draw(Window* window, SDL_Renderer* renderer);

    private:
    int x;
    int y;
    int x_center;
    int y_center;
    int radius;
    int orbital_radius;
    float speed;

    void drawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius);
};

#endif // BALL_H
