#include "events.h"
#include <stdlib.h>

void temp_KeyPressInit() {
	g_tempKeypress.forward = 0;
	g_tempKeypress.left = 0;
	g_tempKeypress.right = 0;
	g_tempKeypress.back = 0;
}

t_KeyPress g_tempKeypress;
int running = 1;

int event_thread_func(void* data) {
    (void) data;
	SDL_Event event;

	temp_KeyPressInit();
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = 0;
			} else if (event.type == SDL_EVENT_KEY_DOWN) {
				keyEventKeyDown(event.key.keysym.sym);
			} else if (event.type == SDL_EVENT_KEY_UP) {
				keyEventKeyUp(event.key.keysym.sym);
			}
		}
		SDL_Delay(10);
		if (!running){
			ft_printf("ESC KEY PRESSED\nQUITTING...\n");
			exit(1);
		}
	}
	return 0;
}