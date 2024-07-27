#include "global.h"
#include "events.h"
#include "levelEditor.h"

//TODO remove this logic
void	lvlEditorlMouseHandler(t_2dVector pos){
	t_WallVertex *tmp, *active;

	tmp = (t_WallVertex *)getAndInitStruct(1, sizeof(t_WallVertex), &initWallVertex);
	tmp->position = calcGridIntersection(pos);
	tmp->coordinate = calcCoordinate(tmp->position);

	active = gameEnv->editor->editor.activeSector;
	if (!active) {
		active = (t_WallVertex *)getAndInitStruct(1, sizeof(t_WallVertex), &initWallVertex);
		active->next = tmp;
		active->position = tmp->position;
		active->coordinate = tmp->coordinate;
		tmp->prev = active;
		gameEnv->editor->editor.activeSector = active;
	} else {
		tmp->next = active;
		active->prev = tmp;
		gameEnv->editor->editor.activeSector = tmp;
	}

	if (tmp->next && tmp->next->next) {
		t_WallVertex *first = tmp;

		while (1) {
			if (first->next) {
				first = first->next;
			} else
				break;
		}

		if (tmp->next->coordinate.x == first->coordinate.x &&
				tmp->next->coordinate.y == first->coordinate.y)
			ft_printf("New Sector Accuired\n");
	}
	ft_printf("New Vertex at: %d, %d Coordinate: %d, %d\n", tmp->position.x, tmp->position.y, tmp->coordinate.x, tmp->coordinate.y);
}

void	lvlEditorMouseMotionHandler(t_2dVector pos){
	t_WallVertex *tmp;
	
	tmp = gameEnv->editor->editor.activeSector;
	if (tmp) {
		tmp->position = calcGridIntersection(pos);
		tmp->coordinate = calcCoordinate(tmp->position);
	}
}

void	lvlEditorKeyUpHandler(SDL_Keycode sym){
}

void	lvlEditorKeyDownHandler(SDL_Keycode sym){
	switch (sym)
	{
	case SDLK_ESCAPE:
		gameEnv->editor->escapeStatus = 1;
		break;
	case SDLK_UP:
		gameEnv->editor->editor.offset.y -= gameEnv->editor->editor.gridSize;
		break;
	case SDLK_DOWN:
		gameEnv->editor->editor.offset.y += gameEnv->editor->editor.gridSize;
		break;
	case SDLK_RIGHT:
		gameEnv->editor->editor.offset.x += gameEnv->editor->editor.gridSize;
		break;
	case SDLK_LEFT:
		gameEnv->editor->editor.offset.x -= gameEnv->editor->editor.gridSize;
		break;
	default:
		break;
	}
}

void	lvlEditorMenuKeyDownHandler(SDL_Keycode sym){
	switch (sym)
	{
	case SDLK_UP:
		changeActiveItem(-1);
		break;
	case SDLK_DOWN:
		changeActiveItem(1);
		break;
	case SDLK_RETURN:
		selectMenuItem();
		break;
	case SDLK_ESCAPE:
		lvlEditorMenuEscapeHandler();
		break;
	case SDLK_BACKSPACE:
		lvlEditorMenuTextinputHandler((char *)'\0');
		break;
	default:
		break;
	}
}

void	lvlEditorMenuTextinputHandler(char *txt) {
	char	**fileName = &(gameEnv->editor->menu.newFile);
	size_t	i, j, nameLen, size;
	char	*new;

	if (!(*fileName)) {
		return;
	}
	size = ft_strlen(*fileName);
	if (txt == NULL)
		size--;
	else
		size += ft_strlen(txt);
	new = malloc(size + 1);
	nameLen = ft_strlen(*fileName);
	for (i = 0; i < nameLen - 4; i++)
		new[i] = (*fileName)[i];
	if (txt) {
		for (j = 0; j < ft_strlen(txt); i++, j++)
			new[i] = txt[j];
	} else {
		if (i > 0)
			i--;
	}
	for (j = nameLen - 4; i < size || i < 4; i++, j++) 
		new[i] = (*fileName)[j];
	new[i] = '\0';
	free(*fileName);
	*fileName = new;
}