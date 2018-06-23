#include "SDL.h"
#include "window.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	// Declare pointers
	Window window;

	//Draw
	window.draw();

	// Enter main loop
	SDL_Delay(2000); // For now just show black screen for 2 seconds
	return 0;
}
