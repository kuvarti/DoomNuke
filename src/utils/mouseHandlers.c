#include "global.h"

void	mouseEventNullSetter() {
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}

void	lvlEditorMouseEventSetter() {
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}

void	mainMenuMouseEventSetter() {
	gameEnv->event.lMouseButtonHandler = &mainMenu_mouseButtonHandler;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}