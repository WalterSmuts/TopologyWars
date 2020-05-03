#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "ball.h"
#include <list>

class Ball;
class Window //Childclass of SDL_Window???
{
    public:
    Window(std::list<Ball> *ballList);

    ~Window();
    void draw();
    void update(int ticks);
    int getHeight();
    int getWidth();
    bool isRunning();
    void stop();

    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::list<Ball> *ballList;
    bool running;
};

#endif // WINDOW_H
