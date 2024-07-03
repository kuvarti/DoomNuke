#include "global.h"

void	gameKeyHandlerSetter(){
	gameEnv->event.keyUpHandler = &keyEventKeyUp;
	gameEnv->event.keyDownHandler = &keyEventKeyDown;
	gameEnv->event.textInputHandler = NULL;
}

void	levelEditorKeyHandler(){
	gameEnv->event.keyUpHandler = NULL;
	gameEnv->event.keyDownHandler = NULL;
	gameEnv->event.textInputHandler = NULL;
}