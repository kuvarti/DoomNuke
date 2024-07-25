#include "global.h"
#include "levelEditor.h"

void	releaseMenuItems() {
	t_LevelEditorMenuItem	*tmp;
	tmp = gameEnv->editor->menu.menuItems;
	while (tmp) {
		if (tmp->flags & LVLEDITORMENU_IS_EXPANDED) {
			clearSubItems(tmp);
		}
		tmp = tmp->next;
	}
	gameEnv->editor->menu.menuActive = 0;
	if (gameEnv->editor->menu.newFile)
		free(gameEnv->editor->menu.newFile);
	gameEnv->editor->menu.newFile = NULL;
}

void	lvlEditorMenuEscapeHandler() {
	t_LevelEditorMenuItem	*tmp;

	tmp = gameEnv->editor->menu.menuItems;
	while (tmp) {
		if (tmp->flags & LVLEDITORMENU_IS_EXPANDED) {
			clearSubItems(tmp);
			return;
		}
		tmp = tmp->next;
	}
	gameEnv->editor->menu.menuActive = 0;
	gameEnv->RunningState = 1;
}

void	selectMenuItem() {
	t_LevelEditorMenuItem *tmp;

	tmp = gameEnv->editor->menu.menuItems;
	while (tmp) {
		if ((LVLEDITORMENU_IS_ACTIVE & tmp->flags) && !(LVLEDITORMENU_IS_EXPANDED & tmp->flags)) {
			if (tmp->active) {
				if (!(LVLEDITORMENU_IS_INPUT & tmp->flags))
					gameEnv->editor->menu.newFile = ft_strdup(tmp->title);
				tmp->active();
			}
			else
				ft_printf("Item Click Action not found. Item: %s\n", tmp->title);
			break;
		}
		tmp = tmp->next;
	}
}

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

void	showMapSelectMenu() {
	SDL_Rect	msgR;
	char		*title = NULL;

	gameEnv->editor->menu.menuActive = 1;
	gameEnv->editor->menu.menuItems = setMenuItems();
	while (gameEnv->editor->menu.menuActive) {
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0, 0, 0, 255);
		SDL_RenderClear(gameEnv->sdl.renderer);
		msgR = (SDL_Rect){10, 10, 0, 0};
		t_LevelEditorMenuItem *menuitem = gameEnv->editor->menu.menuItems;
		while (menuitem)
		{
			title = menuitem->title;
			msgR.x = menuitem->flags & LVLEDITORMENU_IS_SUB ? 40 : 10;
			if (menuitem->flags & LVLEDITORMENU_IS_INPUT)
				title = ft_strjoin(title, gameEnv->editor->menu.newFile);
			drawMenuItem(title, menuitem->flags & LVLEDITORMENU_IS_ACTIVE, &msgR);
			if (menuitem->flags & LVLEDITORMENU_IS_INPUT)
				free(title);
			menuitem = menuitem->next;
		}
		SDL_RenderPresent(gameEnv->sdl.renderer);
		SDL_Delay(100);
	}
}