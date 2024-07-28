#include "global.h"

void	newSector() {
	t_EditorSectors *new = (t_EditorSectors *)getAndInitStruct(1, sizeof(t_EditorSectors), &initEditorSector);
	t_EditorSectors *tmp;
	new->walls = gameEnv->editor->editor.activeSector;

	gameEnv->editor->editor.activeSector = NULL;
	tmp = gameEnv->editor->editor.sectors;
	if (tmp) {
		tmp->prev = new;
		new->next = tmp;
		gameEnv->editor->editor.sectors = new;
	} else {
		gameEnv->editor->editor.sectors = new;
	}
}

void	removeSector(t_EditorSectors *tmp) {
	t_Editor *editor = &gameEnv->editor->editor;

	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else if (tmp->next) //* !tmp->prev
		tmp->next->prev = NULL;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	else if (tmp->prev) //* !tmp->next
		tmp->prev->next = NULL;
	if(editor->sectors == tmp)
		gameEnv->editor->editor.sectors = tmp->next;
	freeWallVertexes(tmp->walls);
	tmp->walls = NULL;
	free(tmp);
}

void	checkVertexesHasValidShape() {
	t_WallVertex *tmp, *first;

	tmp = gameEnv->editor->editor.activeSector;
	first = tmp;
	while (1) {
		if (first->next) {
			first = first->next;
		} else
			break;
	}
	if (tmp->next->coordinate.x == first->coordinate.x &&
			tmp->next->coordinate.y == first->coordinate.y)
		newSector();
}

int	checkPosIsValidSectorWall(t_2dVector pos) {
	t_EditorSectors	*tmp;
	t_WallVertex	*wtmp;

	tmp = gameEnv->editor->editor.sectors;
	while (tmp) {
		wtmp = tmp->walls;
		while (wtmp)
		{
			if (compare2dVector(pos, wtmp->position)){
				removeSector(tmp);
				return 1;
			}
			wtmp = wtmp->next;
		}
		tmp = tmp->next;
	}
	return 0;
}