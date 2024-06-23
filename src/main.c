#include "global.h"
#include <sys/mman.h>

#include "config.h"
#include "libft.h"
#include "events.h"
#include "render.h"

#include "SDL_thread.h"

SDL_Surface *window_surface = NULL;
SDL_Window *window = NULL;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	SDL_Thread *event_thread = NULL;
	SDL_Thread *render_thread = NULL;

	printf("Hello World!\n");
	/* from libft.a */
	ft_putstr_fd("Hello from libft\n", STDOUT_FILENO);
	/* from config.c */
	sayHelloFromConfig();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr_fd("Failed to initialize the SDL2 library\n", STDERR_FILENO);
		return -1;
	}

	window = SDL_CreateWindow("Shooter 01", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!window)
	{
		ft_putstr_fd("Failed to create window\n", STDERR_FILENO);
		return -1;
	}

	event_thread = SDL_CreateThread(event_thread_func, "EventThread", NULL);
	render_thread = SDL_CreateThread(render_thread_func, "RenderThread", NULL);

	SDL_WaitThread(event_thread, NULL);
	SDL_WaitThread(render_thread, NULL);

	// Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	// Quit SDL subsystems
	SDL_Quit();

	return 0;
}