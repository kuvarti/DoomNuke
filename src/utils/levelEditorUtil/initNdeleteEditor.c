#include "global.h"

void	initEditor() {
	gameEnv->editor = (t_levelEditor *)malloc(sizeof(t_levelEditor));
	gameEnv->editor->menu.menuActive = 0;
	gameEnv->editor->menu.newFile = NULL;
	gameEnv->editor->menu.menuItems = NULL;
	gameEnv->editor->openedFile = -1;
	gameEnv->editor->escapeStatus = 0;
}

void	freeEditorMenuItems() {
	t_LevelEditorMenuItem *tmp = gameEnv->editor->menu.menuItems;
	t_LevelEditorMenuItem *ftmp;
	while (tmp)
	{
		ftmp = tmp;
		tmp = tmp->next;
		free(ftmp);
	}
}

void	freeEditor() {
	freeEditorMenuItems();
	if (gameEnv->editor->menu.newFile)
		free(gameEnv->editor->menu.newFile);
	if (gameEnv->editor->openedFile != -1) 
		free(gameEnv->editor);
	gameEnv->editor = NULL;
}