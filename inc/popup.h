#pragma once

#include "commonStructures.h"

#define POPUP_HAS_MENU 1
#define POPUP_HAS_BUTTONS 2

typedef struct s_PopupBase {
	int		flags;
	char	*name;
	void	(*eventSetter)();
	void	(*render)();
}	t_PopupBase;

void	initPopUp(t_PopupBase *);
void	drawPopUpFrame(t_2dVector);