#pragma once

#include "libft.h"
#include "SDL.h"
#include "SDL_events.h"

typedef struct s_KeyPress
{
    char forward;
    char left;
    char right;
    char back;
} t_KeyPress;

extern t_KeyPress g_tempKeypress;
// typedef struct s_

int event_thread_func(void *);
void keyEventKeyUp(SDL_Keycode);
void keyEventKeyDown(SDL_Keycode);