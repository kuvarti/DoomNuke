#include "global.h"

void	showEditorEscapeSelectMenu() {
	SDL_Rect	msgR;
	char		*title = NULL;

	gameEnv->editor->menu.menuActive = 1;
	gameEnv->editor->menu.menuItems = setEscapeMenuItems();
	while (gameEnv->editor->menu.menuActive) {
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0, 0, 0, 255);
		SDL_RenderClear(gameEnv->sdl.renderer);
		msgR = (SDL_Rect){10, 10, 0, 0};
		t_LevelEditorMenuItem *menuitem = gameEnv->editor->menu.menuItems;
		msgR.x = 10;
		title = ft_strdup(LVLEDITORESCAPEMENU);
		drawMenuItem(title, 0, &msgR);
		free(title);
		while (menuitem)
		{
			title = menuitem->title;
			msgR.x = 40;
			drawMenuItem(title, menuitem->flags & LVLEDITORMENU_IS_ACTIVE, &msgR);
			menuitem = menuitem->next;
		}
		SDL_RenderPresent(gameEnv->sdl.renderer);
		SDL_Delay(100);
	}
}