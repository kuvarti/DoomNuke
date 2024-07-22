#include "global.h"
#include "render.h"
#include "map.h"

int render_func()
{
	while (gameEnv->RunningState == 2)
	{
		gameEventSetter();
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 0, 0, 0, 255);
		SDL_RenderClear(gameEnv->sdl.renderer);
		SDL_SetRenderDrawColor(gameEnv->sdl.renderer, 255, 0, 0, 255);
		// draw a line for the player direction
		SDL_RenderDrawLine(gameEnv->sdl.renderer, player->posX * 10, player->posY * 10, player->posX * 10 + cos(player->dir) * 40, player->posY * 10 + sin(player->dir) * 40);

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