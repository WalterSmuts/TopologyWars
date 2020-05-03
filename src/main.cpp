#include "SDL.h"
#include "window.h"
#include "block.h"
#include <cstdio>
#include <list>
#include <cstdlib>

using namespace std;

static int updateThread(void *ptr)
{
    list<Block> *blockList = (list<Block>*)ptr;
    list<Block>::iterator block;
    while (true)
    {
        Uint32 ticks = SDL_GetTicks();
        for (block = blockList->begin(); block != blockList->end(); ++block) {
           block->update(ticks);
        }
    }
    return 0;
}

static int renderThread(void *ptr)
{
    Window *w = (Window*)ptr;
    while (true)
    {
        w->draw();
    }
    return 0;
}

int main(int argc, char* argv[]) {
    // Declare pointers
    list<Block> blockList;
    for (int i = 0; i < 200; i++) {
        blockList.emplace_back(Block(rand()%1000 - 500,
                                     rand()%1000 - 500,
                                     rand()%100 - 50,
                                     rand()%100 - 50,
                                     rand()%1000,
                                     (rand()%200 - 100)/10000.0f));
    }
    Window window(&blockList);

    // Start Update thread
    SDL_Thread *thread1;
    thread1 = SDL_CreateThread(updateThread, "updateThread", &blockList);

    // Start Rendering thread
    SDL_Thread *thread2;
    thread2 = SDL_CreateThread(renderThread, "renderThread", &window);

    SDL_WaitThread(thread1, NULL);
    SDL_WaitThread(thread2, NULL);
    return 0;
}
