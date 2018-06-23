#include "block.h"
#include <math.h>

Block::Block()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

int Block::getX()
{
	return x;
}

int Block::getY()
{
	return y;
}

int Block::getWidth()
{
	return width;
}

int Block::getHeight(){
	return height;
}

void Block::update(int ticks){
	x = 200*sin(ticks*0.005);
	y = 200*cos(ticks*0.005);
}
