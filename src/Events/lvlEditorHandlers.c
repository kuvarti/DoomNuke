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
		gameEnv->editor->menu.itemIndex -= 1;
		if (gameEnv->editor->menu.itemIndex < 0)
			gameEnv->editor->menu.itemIndex = 0;
		break;
	case SDLK_DOWN:
		gameEnv->editor->menu.itemIndex += 1;
		if (gameEnv->editor->menu.itemIndex > MenuItemCount - 1)
			gameEnv->editor->menu.itemIndex = MenuItemCount - 1;
		break;
	case SDLK_ESCAPE:
		gameEnv->editor->menu.menuActive = 0;
		gameEnv->RunningState = 1; //TODO this is temporary
	default:
		break;
	}
}