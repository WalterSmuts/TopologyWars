#include "SDL.h"
#include "window.h"
#include "block.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

static int updateThread(void *ptr)
{
	Block *b = (Block*)ptr;
	while (true)
	{
		b->update(SDL_GetTicks());
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
	Block block;
	Window window(&block);

	// Start Update thread
	SDL_Thread *thread1;
	thread1 = SDL_CreateThread(updateThread, "updateThread", &block);

	// Start Rendering thread
	SDL_Thread *thread2;
	thread2 = SDL_CreateThread(renderThread, "renderThread", &window);

	SDL_WaitThread( thread1, NULL );
	SDL_WaitThread( thread2, NULL );
	return 0;
}
