#include "global.h"
#include "levelEditor.h"

void	drawMenuItem(char *txt, int isActive, SDL_Rect *msgR){
	SDL_Color color;
	SDL_Color bgColor;
	if (isActive) {
		color = (SDL_Color){0, 0, 0, 255};
		bgColor = (SDL_Color){255, 255, 255, 255};
	} else {
		color = (SDL_Color){255, 255, 255, 255};
		bgColor = (SDL_Color){0, 0, 0, 255};
	}
	SDL_Surface *surface = TTF_RenderText_Solid(gameEnv->mainMenu.font.font, txt, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gameEnv->sdl.renderer, surface);
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
	int texW=0, texH=0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	msgR->w = texW;
	msgR->h = texH;
	SDL_RenderFillRect(gameEnv->sdl.renderer, msgR);
	SDL_RenderCopy(gameEnv->sdl.renderer, texture, NULL, msgR);
	msgR->y += texH + 5;
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

t_LevelEditorMenu showMapSelectMenu() {
	t_LevelEditorMenu	ret;
	SDL_Rect			msgR;

	gameEnv->editor->menu.menuActive = 1;
	ret.menuItems = setMenuItems();
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(gameEnv->sdl.renderer);
	while (gameEnv->editor->menu.menuActive) {
		msgR = (SDL_Rect){10, 10, 0, 0};
		for (size_t i = 0; i < 4; i++) {
			drawMenuItem(ret.menuItems[i], i == gameEnv->editor->menu.itemIndex, &msgR);
			SDL_RenderPresent(gameEnv->sdl.renderer);
		}
		SDL_Delay(100);
	}
}