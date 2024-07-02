#include "global.h"
#include "levelEditor.h"

void drawGrid(SDL_Renderer* renderer, int gridSpacing) {
	SDL_SetRenderDrawColor(renderer, 0x44, 0x44, 0x44, 0xFF);

	for (int x = 0; x < WINDOW_WIDTH; x += gridSpacing) {
		SDL_RenderDrawLine(renderer, x, 0, x, WINDOW_HEIGHT);
	}

	for (int y = 0; y < WINDOW_HEIGHT; y += gridSpacing) {
		SDL_RenderDrawLine(renderer, 0, y, WINDOW_WIDTH, y);
	}
}

int lvlEditor() {
	// Grid spacing
	int gridSpacing = 20;
	while (gameEnv->RunningState == 3) {
		SDL_RenderClear(gameEnv->sdl.renderer);
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		editorMenuEvents();
		showMapSelectMenu();
		editorEvents();
		// Clear screen
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gameEnv->sdl.renderer);
		// Render grid
		drawGrid(gameEnv->sdl.renderer, gridSpacing);
		// Update screen
		SDL_RenderPresent(gameEnv->sdl.renderer);
	}
	return 1;
}
