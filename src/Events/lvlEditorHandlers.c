#include "global.h"
#include "events.h"
#include "levelEditor.h"

void	lvlEditorKeyUpHandler(SDL_Keycode sym){
}

void	lvlEditorKeyDownHandler(SDL_Keycode sym){
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
		lvlEditorEscapeHandler();
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