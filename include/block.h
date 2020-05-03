#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include "window.h"

class Window;
class Block
{
	public:
	Block();
	int getX();
	int getY();
	void update(int ticks);
	void draw(Window* window, SDL_Renderer* renderer);

	private:
	int x;
	int y;
	int width;
	int height;
};

#endif // BLOCK_H
