#include "global.h"
#include "config.h"

# define MainMenuButton gameEnv->mainMenu.menuButtons

void	initMenuButton(void *p){
	t_Button *b = (t_Button *)p;
	(*b).label = 0;
	(*b).onClick = NULL;
	(*b).rect = (SDL_Rect){0, 0, 0, 0};
}

void	initMainMenuButtons() {
	MainMenuButton = (t_Button *)getAndInitStruct(3, sizeof(t_Button), *initMenuButton);
	MainMenuButton[0].label = "Play";
	MainMenuButton[0].rect = (SDL_Rect){
		(WINDOW_WIDTH - BUTTON_WIDTH) / 2, 
		(WINDOW_HEIGHT - (BUTTON_HEIGHT * 3 + BUTTON_PADDING * 2)) / 2, 
		BUTTON_WIDTH, BUTTON_HEIGHT
	};
	MainMenuButton[0].onClick = &btn_Play;

	MainMenuButton[1].label = "Level Editor";
	MainMenuButton[1].rect = (SDL_Rect){
		(WINDOW_WIDTH - BUTTON_WIDTH) / 2,
		(WINDOW_HEIGHT - (BUTTON_HEIGHT * 3 + BUTTON_PADDING * 2)) / 2 + BUTTON_HEIGHT + BUTTON_PADDING,
		BUTTON_WIDTH, BUTTON_HEIGHT
	};
	MainMenuButton[1].onClick = &btn_LevelEditor;

	MainMenuButton[2].label = "Quit";
	MainMenuButton[2].rect = (SDL_Rect){
		(WINDOW_WIDTH - BUTTON_WIDTH) / 2,
		(WINDOW_HEIGHT - (BUTTON_HEIGHT * 3 + BUTTON_PADDING * 2)) / 2 + (BUTTON_HEIGHT + BUTTON_PADDING) * 2, 
		BUTTON_WIDTH, BUTTON_HEIGHT
	};
	MainMenuButton[2].onClick = &btn_Quit;
}