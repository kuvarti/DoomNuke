#include "global.h"

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
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}