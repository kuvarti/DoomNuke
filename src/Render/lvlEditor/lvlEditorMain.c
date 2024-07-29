#include "global.h"
#include "levelEditor.h"

void renderMenu() {
	SDL_RenderClear(gameEnv->sdl.renderer);
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	editorMenuEvents();
	showMapSelectMenu();
}

void escapeMenu() {
	SDL_RenderClear(gameEnv->sdl.renderer);
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	editorMenuEvents();
	showEditorEscapeSelectMenu();
}

void editorScreen() {
	SDL_RenderClear(gameEnv->sdl.renderer);
	editorEvents();
	showEditor();
}

int lvlEditor() {
	while (gameEnv->RunningState == 3) {
		if (gameEnv->editor->openedFile <= 0) {
			renderMenu();
			releaseMenuItems();
		}
		if (gameEnv->RunningState != 3)
			break;
		if (!gameEnv->editor->escapeStatus) {
			editorScreen();
		} else {
			escapeMenu();
			releaseMenuItems();
		}
	}
	return 1;
}
