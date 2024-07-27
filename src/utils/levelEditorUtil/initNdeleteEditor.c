#include "global.h"

void	initEditor() {
	gameEnv->editor = (t_levelEditor *)malloc(sizeof(t_levelEditor));
	gameEnv->editor->menu.menuActive = 0;
	gameEnv->editor->menu.newFile = NULL;
	gameEnv->editor->menu.menuItems = NULL;
	gameEnv->editor->openedFile = -1;
	gameEnv->editor->escapeStatus = 0;
	gameEnv->editor->editor.gridSize = 25;
	gameEnv->editor->editor.offset.x = 0;
	gameEnv->editor->editor.offset.y = 0;
	gameEnv->editor->editor.anchor.x = ((WINDOW_WIDTH / 2) / gameEnv->editor->editor.gridSize) * gameEnv->editor->editor.gridSize;
	gameEnv->editor->editor.anchor.y = ((WINDOW_HEIGHT / 2) / gameEnv->editor->editor.gridSize) * gameEnv->editor->editor.gridSize;
	gameEnv->editor->editor.mousePos.x = gameEnv->editor->editor.anchor.x;
	gameEnv->editor->editor.mousePos.y = gameEnv->editor->editor.anchor.y;
	gameEnv->editor->editor.sectors = NULL;
	gameEnv->editor->editor.activeSector = NULL;
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

void	freeWallVertexes(t_WallVertex *w) {
	t_WallVertex *tmp, *hold;

	tmp = w;
	while (tmp) {
		hold = tmp;
		tmp= tmp->next;
		free(hold);
	}
}