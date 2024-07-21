#include "global.h"
#include "render.h"
#include "map.h"

int render_func()
{
	SDL_Rect rect = {0, 0, 100, 100};
	while (gameEnv->RunningState == 2)
	{
		gameEventSetter();
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0, 0, 0, 255);
		SDL_RenderClear(gameEnv->sdl.renderer);
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 255, 0, 0, 255);
		// draw a box
		SDL_RenderFillRect(gameEnv->sdl.renderer, &rect);

		SDL_RenderPresent(gameEnv->sdl.renderer);
		SDL_Delay(300);
	}

	return 0;
}

void GameKeyHandler(SDL_Keycode sym)
{
	switch (sym)
	{
	case SDLK_UP:
		break;
	case SDLK_DOWN:
		break;
	case SDLK_RETURN:
		break;
	case SDLK_ESCAPE:
		gameEnv->RunningState = 1;
		break;
	case SDLK_BACKSPACE:
		break;
	default:
		break;
	}
}