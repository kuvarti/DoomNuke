#pragma once

#include "libft.h"
#include "SDL.h"

#define FOV (3.14159 / 2.0)
#define MAX_DEPTH 60.0

int render_thread_func(void *);