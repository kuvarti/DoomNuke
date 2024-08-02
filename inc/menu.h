#pragma once

#include "SDL.h"
#include "fonts.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_PADDING 20

typedef struct s_Button {
	SDL_Rect rect;
	const char *label;
	void (*onClick)();
}	t_Button;

typedef struct s_Menu {
	t_Button	*menuButtons;
}	t_Menu;

void	btn_Play();
void	btn_Quit();
void	btn_LevelEditor();

int		showMainMenu();
void	renderButton(SDL_Renderer *, t_Button, TTF_Font *);