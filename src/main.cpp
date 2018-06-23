#include "SDL.h"
#include "window.h"
#include "block.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char* argv[]) {
	// Declare pointers
	Block block;
	Window window(&block);

	// Enter main loop
	while (SDL_GetTicks() < 5000){
		// Update Block
		block.update(SDL_GetTicks());

		// Draw
		window.draw();
		SDL_Delay(20); // Approximately 50 Hz
	}
	return 0;
}
