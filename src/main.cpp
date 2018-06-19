#include "SDL.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	// Declare a pointer
	SDL_Window *window;

	// Initialize SDL2
	SDL_Init(SDL_INIT_VIDEO);

	// Get screen size
	int screenHeight, screenWidth;
	SDL_DisplayMode dm;
	SDL_GetDesktopDisplayMode(0, &dm);

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Topology Wars",		// window title
		SDL_WINDOWPOS_UNDEFINED,	// initial x position
		SDL_WINDOWPOS_UNDEFINED,	// initial y position
		dm.w,				// width, in pixels
		dm.h,				// height, in pixels
		SDL_WINDOW_OPENGL		// flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("SDL couldn't create a window:( \n Error: %s\n", SDL_GetError());
		return 1;
	}

	// Set Window FullScreen
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	// Enter main loop
	SDL_Delay(1000); // For now just show black screen for 1 second

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}
