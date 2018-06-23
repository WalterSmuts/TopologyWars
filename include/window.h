#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window //Childclass of SDL_Window???
{
	public:
	Window();
	~Window();
	void draw();

	private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width;
	int height;

};

#endif // WINDOW_H
