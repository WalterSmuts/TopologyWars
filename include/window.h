#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "block.h"

class Block;
class Window //Childclass of SDL_Window???
{
	public:
	Window(Block *b);
	~Window();
	void draw();
    int getHeight();
    int getWidth();

	private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width;
	int height;
	Block *block;
};

#endif // WINDOW_H
