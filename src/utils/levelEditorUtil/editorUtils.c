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