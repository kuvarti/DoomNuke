#include "global.h"

void	drawGrid(t_2dVector offset, int gridSize) {
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0x44, 0x44, 0x44, 0xFF);

	for (int x = -gridSize; x<= WINDOW_WIDTH + gridSize; x+= gridSize) {
		SDL_RenderDrawLine(gameEnv->sdl.renderer, x + (offset.x % gridSize) - gridSize, 0, x + (offset.x % gridSize) - gridSize, WINDOW_HEIGHT);
	}
	for (int y = -gridSize; y<= WINDOW_WIDTH + gridSize; y+= gridSize) {
		SDL_RenderDrawLine(gameEnv->sdl.renderer, 0 , y + (offset.y % gridSize) - gridSize, WINDOW_WIDTH, y + (offset.y % gridSize) - gridSize);
	}
}

void	drawZeroPoint(t_2dVector anchor) {
	int			len = gameEnv->editor->editor.gridSize / 3;
	t_2dVector	zero = {
		anchor.x + gameEnv->editor->editor.offset.x,
		anchor.y + gameEnv->editor->editor.offset.y
	};

	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(gameEnv->sdl.renderer, zero.x - len, zero.y, zero.x + len, zero.y);
	SDL_RenderDrawLine(gameEnv->sdl.renderer, zero.x, zero.y - len, zero.x, zero.y + len);
}

void	drawWallVertexes(t_WallVertex *active) {
	t_WallVertex	*tmp = active, *first = active;
	
	while (first) {
		first->position = reCalsPosition(first->coordinate);
		first = first->next;
	}


	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xff, 0x0, 0x0, 0xFF);
	while (tmp && tmp->next) {
		SDL_RenderDrawLine(gameEnv->sdl.renderer, tmp->position.x, tmp->position.y, \
			tmp->next->position.x, tmp->next->position.y);
		tmp = tmp->next;
	}
}

void	showEditor() {
	while (!gameEnv->editor->escapeStatus) {
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gameEnv->sdl.renderer);
		drawGrid(gameEnv->editor->editor.offset, gameEnv->editor->editor.gridSize);

		// t_2dVector mouse1 = {5, 5}, mouse2 = {0, 0}, anchor = gameEnv->editor->editor.anchor, xm1, xm2;
		// xm1.x = anchor.x + (mouse1.x * gameEnv->editor->editor.gridSize) + gameEnv->editor->editor.offset.x;
		// xm1.y = anchor.y + (mouse1.y * gameEnv->editor->editor.gridSize) + gameEnv->editor->editor.offset.y;
		// xm2.x = anchor.x + (mouse2.x * gameEnv->editor->editor.gridSize) + gameEnv->editor->editor.offset.x;
		// xm2.y = anchor.y + (mouse2.y * gameEnv->editor->editor.gridSize) + gameEnv->editor->editor.offset.y;

		// SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xff, 0x0, 0x0, 0xFF);
		// SDL_RenderDrawLine(gameEnv->sdl.renderer, xm1.x, xm1.y, xm2.x, xm2.y);
		drawWallVertexes(gameEnv->editor->editor.activeSector);


		drawZeroPoint(gameEnv->editor->editor.anchor);
		SDL_RenderPresent(gameEnv->sdl.renderer);
		SDL_Delay(100);
	}
}