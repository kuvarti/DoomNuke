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
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0x00, 0xFF, 0x00, 0xFF);
	t_2dVector	zero = {
		anchor.x + gameEnv->editor->editor.offset.x,
		anchor.y + gameEnv->editor->editor.offset.y
	};

	SDL_RenderDrawLine(gameEnv->sdl.renderer, zero.x - len, zero.y, zero.x + len, zero.y);
	SDL_RenderDrawLine(gameEnv->sdl.renderer, zero.x, zero.y - len, zero.x, zero.y + len);
}

void	drawWalls(t_WallVertex *active) {
	t_EditorSectors	*tmp;
	
	if (active) 
		drawEditorWallVertexes(active);
	tmp = gameEnv->editor->editor.sectors;
	while (tmp) {
		drawEditorWallVertexes(tmp->walls);
		tmp = tmp->next;
	}
}

void	drawMousePoint(t_2dVector pos) {
	int	len = gameEnv->editor->editor.gridSize / 4;
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	SDL_RenderDrawLine(gameEnv->sdl.renderer, pos.x - len, pos.y, pos.x + len, pos.y);
	SDL_RenderDrawLine(gameEnv->sdl.renderer, pos.x, pos.y - len, pos.x, pos.y + len);
	SDL_RenderPresent(gameEnv->sdl.renderer);
}

void	showEditor() {
	while (!gameEnv->editor->escapeStatus) {
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gameEnv->sdl.renderer);
		drawGrid(gameEnv->editor->editor.offset, gameEnv->editor->editor.gridSize);
		drawZeroPoint(gameEnv->editor->editor.anchor);

		if (gameEnv->editor->editor.activeSector || gameEnv->editor->editor.sectors)
			drawWalls(gameEnv->editor->editor.activeSector);
		if (!gameEnv->editor->editor.activeSector)
			drawMousePoint(gameEnv->editor->editor.mousePos);

		SDL_RenderPresent(gameEnv->sdl.renderer);
		SDL_Delay(10);
	}
}