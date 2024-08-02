#pragma once

#include "SDL_ttf.h"

#define FONTSIZE_ESMALL 12
#define FONTSIZE_SMALL 18
#define FONTSIZE_NORMAL 24
#define FONTSIZE_LARGE 36
#define FONTSIZE_ELARGE 48

typedef struct s_Font {
	TTF_Font	*extraSmall;
	TTF_Font	*small;
	TTF_Font	*normal;
	TTF_Font	*large;
	TTF_Font	*extraLarge;
	char		*name;
}	t_Font;

void	initFonts();
void	closeFonts();
t_Font	*getFont(char *);