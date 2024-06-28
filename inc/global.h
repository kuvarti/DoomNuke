#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "SDL.h"

# include "map.h"

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480 

extern SDL_Surface *window_surface;
extern SDL_Window *window;

static struct s_gameEnv {
	t_map	map;
}	gameEnv;

extern int running;

#endif