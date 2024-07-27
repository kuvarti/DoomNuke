#include "global.h"

void	drawEditorWallVertexes(t_WallVertex *active) {
	t_WallVertex	*tmp = active, *first = active;
	
	while (first) {
		first->position = reCalsPosition(first->coordinate);
		if (!first->next && active == gameEnv->editor->editor.activeSector)
			drawMousePoint(first->position);
		first = first->next;
	}
	SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0xff, 0x0, 0x0, 0xFF);
	while (tmp && tmp->next) {
		SDL_RenderDrawLine(gameEnv->sdl.renderer, tmp->position.x, tmp->position.y, \
			tmp->next->position.x, tmp->next->position.y);
		tmp = tmp->next;
	}
}