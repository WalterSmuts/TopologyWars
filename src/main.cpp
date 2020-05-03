#include "SDL.h"
#include "window.h"
#include "ball.h"
#include <cstdio>
#include <list>
#include <cstdlib>

using namespace std;

static int updateThread(void *ptr)
{
    Window *w = (Window*)ptr;
    while (w->isRunning())
    {
        w->update(SDL_GetTicks());
    }
    return 0;
}

static int renderThread(void *ptr)
{
    Window *w = (Window*)ptr;
    while (w->isRunning())
    {
        w->draw();
    }
    return 0;
}

static int handle_event(void *ptr)
{
    Window *w = (Window*)ptr;
    while (w->isRunning())
    {
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
            w->stop();
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    // Declare pointers
    list<Ball> ballList;
    for (int i = 0; i < 200; i++) {
        ballList.emplace_back(Ball(rand() % 1000 - 500,
                                     rand()%1000 - 500,
                                     rand()%100 - 50,
                                     rand()%1000,
                                     (rand()%200 - 100)/100000.0f));
    }
    Window window(&ballList);

    // Start Update thread
    SDL_Thread *thread1;
    thread1 = SDL_CreateThread(updateThread, "updateThread", &window);

    // Start Rendering thread
    SDL_Thread *thread2;
    thread2 = SDL_CreateThread(renderThread, "renderThread", &window);

    // Start event handling thread
    SDL_Thread *thread3;
    thread3 = SDL_CreateThread(handle_event, "eventHandlingThread", &window);

    SDL_WaitThread(thread1, NULL);
    SDL_WaitThread(thread2, NULL);
    SDL_WaitThread(thread3, NULL);
    return 0;
}
