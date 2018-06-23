#include "SDL.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	// Declare pointers
	SDL_Window *window;
	SDL_Renderer* gRenderer;

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

	//Create Renderer
	gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

	// Set Window FullScreen
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	// Clears screen to black
	SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);

	// Render red filled quad
	SDL_Rect fillRect = {dm.w / 4, dm.h / 4, dm.w / 2, dm.h / 2 };
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
	SDL_RenderFillRect( gRenderer, &fillRect );

	// Update Screen
	SDL_RenderPresent(gRenderer);

	// Enter main loop
	SDL_Delay(2000); // For now just show black screen for 2 seconds

	// Clean up
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
