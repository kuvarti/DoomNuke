#include "global.h"

void	eventNullSetter() {
	gameEnv->event.keyUpHandler = NULL;
	gameEnv->event.keyDownHandler = NULL;
	gameEnv->event.textInputHandler = NULL;
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;

}

void	mainMenuEventSetter() {
	gameEnv->event.keyUpHandler = NULL;
	gameEnv->event.keyDownHandler = NULL;
	gameEnv->event.textInputHandler = NULL;
	gameEnv->event.lMouseButtonHandler = &mainMenu_mouseButtonHandler;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}

void	gameEventSetter(){
	gameEnv->event.keyUpHandler = &keyEventKeyUp;
	gameEnv->event.keyDownHandler = &gameKeyEventKeyDown;
	gameEnv->event.textInputHandler = NULL;
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = &gameMoveEventMotion;
}

void	editorMenuEvents() {
	gameEnv->event.keyUpHandler = NULL;
	gameEnv->event.keyDownHandler = &lvlEditorMenuKeyDownHandler;
	gameEnv->event.textInputHandler = &lvlEditorMenuTextinputHandler;
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}

void	editorEvents() {
	gameEnv->event.keyUpHandler = &lvlEditorKeyUpHandler;
	gameEnv->event.keyDownHandler = &lvlEditorKeyDownHandler;
	gameEnv->event.textInputHandler = NULL;
	gameEnv->event.lMouseButtonHandler = &lvlEditorlMouseHandler;
	gameEnv->event.rMouseButtonHandler = &lvlEditorrMouseHandler;
	gameEnv->event.MouseMotionHandler = &lvlEditorMouseMotionHandler;
}