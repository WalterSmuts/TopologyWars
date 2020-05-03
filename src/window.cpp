#include "window.h"
#include <list>

using namespace std;

Window::Window(list<Block> *blockList)
{
    this->blockList = blockList;

    // Initialize SDL2
    SDL_Init(SDL_INIT_VIDEO);

    // Get screen size
    int screenHeight, screenWidth;
    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(0, &dm);
    width = dm.w;
    height = dm.h;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Topology Wars",            // window title
        SDL_WINDOWPOS_UNDEFINED,    // initial x position
        SDL_WINDOWPOS_UNDEFINED,    // initial y position
        width,                      // width, in pixels
        height,                     // height, in pixels
        SDL_WINDOW_OPENGL           // flags - see below
    );

    //Create Renderer
    renderer = SDL_CreateRenderer( window, -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Set Window FullScreen
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
}

Window::~Window()
{
    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::draw()
{
    // Clears screen to black
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    // Let blocks draw themselves
    list<Block>::iterator block;
    for (block = blockList->begin(); block != blockList->end(); ++block) {
        block->draw(this, renderer);
    }

    // Update Screen
    SDL_RenderPresent(renderer);
}

void Window::update(int ticks)
{
    list<Block>::iterator block;
    for (block = blockList->begin(); block != blockList->end(); ++block) {
        block->update(ticks);
    }
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}
