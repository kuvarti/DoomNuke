#pragma once

#include "SDL_rect.h"
#include "SDL_keycode.h"

#define LVLEDITORMENU1 "Select An Existing Map"
#define LVLEDITORMENU2 "Create New Map"
#define LVLEDITORMENU3 "Return Main Menu"

#define LVLEDITORMENU_IS_SUB 1
#define LVLEDITORMENU_IS_EXPANDED 2
#define LVLEDITORMENU_IS_ACTIVE 4
#define LVLEDITORMENU_IS_INPUT 8
typedef struct s_LevelEditorMenuItem {
	char							*title;
	int								flags;
	void							(*active)();
	struct s_LevelEditorMenuItem	*next;
}	t_LevelEditorMenuItem;

typedef struct s_LevelEditorMenu {
	int						menuActive;
	char					*newFile;
	t_LevelEditorMenuItem	*menuItems;
}	t_LevelEditorMenu;

typedef struct s_levelEditor{
	t_LevelEditorMenu	menu;
}	t_levelEditor;

//* Init & Config
void	initEditor();
void	freeEditor();
void	freeEditorMenuItems();
void	editorMenuEvents();
void	editorEvents();

void	selectMenuItem();
void	lvlEditorEscapeHandler();
void	changeActiveItem(int new);
void	lvlEditorKeyUpHandler(SDL_Keycode);
void	lvlEditorKeyDownHandler(SDL_Keycode);
void	lvlEditorMenuKeyDownHandler(SDL_Keycode);
void	lvlEditorMenuTextinputHandler(char *txt);

void	drawMenuItem(char *, int, SDL_Rect *);

//* Menu Specific
t_LevelEditorMenuItem	*setMenuItems();
t_LevelEditorMenuItem	*createNewSub(char *, t_LevelEditorMenuItem *);
void					mapSelectionBtn();
void					showMapSelectMenu();
void					clearSubItems(t_LevelEditorMenuItem *);

void	selectExistingMap();
void	createNewMap();
void	returnMainMenu();

int lvlEditor();