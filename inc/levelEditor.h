#pragma once

#include "SDL_rect.h"
#include "SDL_keycode.h"

#define MenuItemCount 3

typedef struct s_LevelEditorMenu {
	char	**menuItems;
	int		itemIndex;
	int		menuActive;
}	t_LevelEditorMenu;

typedef struct s_levelEditor{
	t_LevelEditorMenu menu;
}	t_levelEditor;

void	initEditor();
void	freeEditor();
void	editorMenuEvents();
void	editorEvents();

void	lvlEditorKeyUpHandler(SDL_Keycode);
void	lvlEditorKeyDownHandler(SDL_Keycode);
void	lvlEditorMenuKeyDownHandler(SDL_Keycode);

char	**setMenuItems();
void	drawMenuItem(char *, int, SDL_Rect *);

t_LevelEditorMenu showMapSelectMenu();

int lvlEditor();