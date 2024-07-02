#include "global.h"

void	gameKeyHandlerSetter(){
	gameEnv->event.keyUpHandler = &keyEventKeyUp;
	gameEnv->event.keyDownHandler = &keyEventKeyDown;
}

void	levelEditorKeyHandler(){
	gameEnv->event.keyUpHandler = NULL;
	gameEnv->event.keyDownHandler = NULL;
}