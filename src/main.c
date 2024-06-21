#include "global.h"

#include "config.h"
#include "libft.h"
#include "events.h"

#include "SDL.h"
#include "SDL_thread.h"
#include <SDL2/SDL_events.h>

int main(int argc, char **argv)
{
	(void )argc;
	(void )argv;
	SDL_Thread* event_thread = NULL;

	printf("Hello World!\n");
	/* from libft.a */
	ft_putstr_fd("Hello from libft\n", STDIN_FILENO);
	/* from config.c */
	sayHelloFromConfig();

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr_fd("Failed to initialize the SDL2 library\n", STDERR_FILENO);
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("Shooter 01", 750, 500, 0);

	if(!window)
	{
		ft_putstr_fd("Failed to create window\n", STDERR_FILENO);
		return -1;
	}

	event_thread = SDL_CreateThread(event_thread_func, "EventThread", NULL);
	SDL_Surface *window_surface = SDL_GetWindowSurface(window);

	if(!window_surface)
	{
		ft_putstr_fd("Failed to get the surface from the window\n", STDERR_FILENO);
		return -1;
	}

	SDL_WaitThread(event_thread, NULL);
	SDL_UpdateWindowSurface(window);
	return (0);
}