#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>
#include "window.h"
#include <list>

class Window;
class Block
{
	public:
	Block(int x, int y, int width, int height, int radius, float speed);
	void update(int ticks);
	void draw(Window* window, SDL_Renderer* renderer);

	private:
	int x;
	int y;
    int x_center;
    int y_center;
	int width;
	int height;
    int radius;
    float speed;
};

#endif // BLOCK_H
