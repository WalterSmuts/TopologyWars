#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "block.h"
#include <list>

class Block;
class Window //Childclass of SDL_Window???
{
    public:
    Window(std::list<Block> *blockList);

    ~Window();
    void draw();
    void update(int ticks);
    int getHeight();
    int getWidth();

    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::list<Block> *blockList;
};

#endif // WINDOW_H
