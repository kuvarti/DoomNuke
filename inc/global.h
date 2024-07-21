#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "SDL.h"

# include "render.h"
# include "map.h"
# include "events.h"
# include "menu.h"
# include "levelEditor.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720 

typedef struct s_SDLs{
	SDL_Window		*window;
	SDL_Surface		*window_surface;
	SDL_Renderer	*renderer;
}	t_SDLs;

//* RunningState: 0 is close, 1 is Main Menu, 2 is raycast, 3 is level editor.
typedef struct s_gameEnv {
	t_map			map;
	t_SDLs			sdl;
	t_Menu			mainMenu;
	t_Events		event;
	t_levelEditor	*editor;
	int				RunningState;
}	t_gameEnv;

extern t_gameEnv	*gameEnv;

int		renderMain();

#endif