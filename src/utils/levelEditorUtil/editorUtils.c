#include "global.h"

void	initWallVertex(void *p) {
	t_WallVertex *w = (t_WallVertex *)p;
	w->next = NULL;
	w->prev = NULL;
	w->coordinate.x = 0;
	w->coordinate.y = 0;
	w->position.x = 0;
	w->position.y = 0;
}
void	initEditorSector(void *p) {
	t_EditorSectors *e = (t_EditorSectors *)p;
	e->next = NULL;
	e->prev = NULL;
	e->walls = NULL;
	e->sectorNo = 0;
}