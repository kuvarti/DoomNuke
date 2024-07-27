#pragma once

#include "SDL_rect.h"
#include "SDL_keycode.h"
#include "commonStructures.h"

#define LVLEDITORMENU1 "Select An Existing Map"
#define LVLEDITORMENU2 "Create New Map"
#define LVLEDITORMENU3 "Return Main Menu"

#define LVLEDITORESCAPEMENU "Returning main menu without saving are you sure?"
#define LVLEDITORESCAPEMENU1 "Yes"
#define LVLEDITORESCAPEMENU2 "No"

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

typedef struct s_Editor {
	t_2dVector			offset;
	t_2dVector			anchor;
	int					gridSize;
	struct s_WallVertex	*activeSector;
}	t_Editor;

typedef struct s_levelEditor{
	int					openedFile;
	int					escapeStatus;
	t_Editor			editor;
	t_LevelEditorMenu	menu;
}	t_levelEditor;

//* Editor Structures
typedef struct s_WallVertex {
	t_2dVector			position;
	t_2dVector			coordinate;
	struct s_WallVertex	*next;
	struct s_WallVertex	*prev;
}	t_WallVertex;

//* Init & Config
void	initEditor();
void	freeEditor();
void	freeEditorMenuItems();
void	editorMenuEvents();
void	editorEvents();

void	selectMenuItem();
void	releaseMenuItems();
void	lvlEditorMenuEscapeHandler();
void	changeActiveItem(int);
void	lvlEditorlMouseHandler(t_2dVector);
void	lvlEditorKeyUpHandler(SDL_Keycode);
void	lvlEditorKeyDownHandler(SDL_Keycode);
void	lvlEditorMouseMotionHandler(t_2dVector);
void	lvlEditorMenuKeyDownHandler(SDL_Keycode);
void	lvlEditorMenuTextinputHandler(char *txt);

void	drawMenuItem(char *, int, SDL_Rect *);

//* Menu Specific
t_LevelEditorMenuItem	*setMenuItems();
t_LevelEditorMenuItem	*setEscapeMenuItems();
t_LevelEditorMenuItem	*createNewSub(char *, t_LevelEditorMenuItem *);
void					mapSelectionBtn();
void					showMapSelectMenu();
void					showEditorEscapeSelectMenu();
void					clearSubItems(t_LevelEditorMenuItem *);

void	selectExistingMap();
void	createNewMap();
void	returnMainMenu();
void	escapeMenuNoButton();

//* Editor
void	showEditor();

//* Editor Utils
void		initWallVertex(void *);
t_2dVector	calcGridIntersection(t_2dVector);
t_2dVector	calcCoordinate(t_2dVector);
t_2dVector	reCalsPosition(t_2dVector);

int lvlEditor();