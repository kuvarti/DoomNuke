#include "global.h"

void	initEditor() {
	gameEnv->editor = (t_levelEditor *)malloc(sizeof(t_levelEditor));
}

void	freeEditor() {
	free(gameEnv->editor);
}