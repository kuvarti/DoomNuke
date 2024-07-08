#pragma once

#include "libft.h"
#include "SDL.h"
#include "SDL_events.h"
#include "commonStructures.h"

typedef struct s_KeyPress
{
	char forward;
	char left;
	char right;
	char back;
}	t_KeyPress;

typedef struct s_Events {
	t_KeyPress  keyPressed;
	void (* textInputHandler)(char *);
	void (* keyUpHandler)(SDL_Keycode);
	void (* keyDownHandler)(SDL_Keycode);
	void (* lMouseButtonHandler)(t_2dVector);
	void (* rMouseButtonHandler)(t_2dVector);
	void (* MouseMotionHandler)(t_2dVector);
}	t_Events;

int		event_thread_func(void *);
void	keyEventKeyUp(SDL_Keycode);
void	keyEventKeyDown(SDL_Keycode);

void	mainMenuEventSetter();
void	mainMenu_mouseButtonHandler(t_2dVector pos);