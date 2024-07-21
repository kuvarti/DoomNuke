#include "config.h"
#include "events.h"
#include "global.h"
#include "commonStructures.h"
#include <stdio.h>

void	initGameEnv(void *p) {
	t_gameEnv *g = (t_gameEnv *)p;
	g->map.sector = NULL;
	g->sdl.window = NULL;
	g->sdl.window_surface = NULL;
	g->mainMenu.menuButtons = NULL;
	g->event.lMouseButtonHandler = NULL;
	g->event.rMouseButtonHandler = NULL;
	g->event.MouseMotionHandler = NULL;
	g->event.keyUpHandler = NULL;
	g->event.keyDownHandler = NULL;
	g->event.textInputHandler = NULL;
	g->RunningState = 0;
}

void	initMainMenu() {
	initMainMenuButtons();
	initMainMenufont();
} 

int InitConfigs() {
	gameEnv = (t_gameEnv *)getAndInitStruct(1, sizeof(t_gameEnv), &initGameEnv);
	initMainMenu();
	return 1;
}