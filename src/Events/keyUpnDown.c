#include "events.h"

void keyEventKeyUp(SDL_Keycode sym){
    switch (sym)
	{
	case SDLK_w:
	case SDLK_UP:
		ft_printf("W KEY RELEASED\n");
        g_tempKeypress.forward = 0;
		break;
	case SDLK_a:
	case SDLK_LEFT:
		ft_printf("A KEY RELEASED\n");
        g_tempKeypress.left = 0;
		break;
	case SDLK_s:
	case SDLK_DOWN:
		ft_printf("S KEY RELEASED\n");
        g_tempKeypress.back = 0;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		ft_printf("D KEY RELEASED\n");
        g_tempKeypress.right = 0;
		break;
	default:
		break;
	}
	// ft_printf("event.key Up : %d\n", sym);
}

void keyEventKeyDown(SDL_Keycode sym){
    switch (sym)
	{
	case SDLK_ESCAPE:
        running = 0;    //! With game loop running statement goes 2 for esc key menu!!
		break;          //! game is only quit within Quit button later.
	case SDLK_w:
	case SDLK_UP:
		ft_printf("W KEY PRESSED\n");
        g_tempKeypress.forward = 1;
		break;
	case SDLK_a:
	case SDLK_LEFT:
		ft_printf("A KEY PRESSED\n");
        g_tempKeypress.left = 1;
		break;
	case SDLK_s:
	case SDLK_DOWN:
		ft_printf("S KEY PRESSED\n");
        g_tempKeypress.back = 1;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		ft_printf("D KEY PRESSED\n");
        g_tempKeypress.right = 1;
		break;
	default:
		break;
	}
	// ft_printf("event.key Down : %d\n", sym);
}
