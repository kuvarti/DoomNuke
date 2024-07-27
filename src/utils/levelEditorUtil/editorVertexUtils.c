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

	// ft_printf("next: %p\nprev: %p\n\n", tmp->next, tmp->prev);
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (editor->sectors == tmp && !editor->sectors->next)
		gameEnv->editor->editor.sectors = NULL;

	freeWallVertexes(tmp->walls);
	free(tmp);
	//! TODO segfault

// 	t_EditorSectors *new = gameEnv->editor->editor.sectors;
// 	while (new) {
// 		write(1, "a", 1);
// 		printf("New Sector %p\nnext: %p\nprev:%p\n----------\n", new, new->next, new->prev);
// 		write(1, "b", 1);
// 		new = new->next;
// 	}
// 	ft_printf("\n\n");
// }

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