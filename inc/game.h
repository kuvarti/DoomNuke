#pragma once

# include "libft.h"
# include "events.h"

void gameEventSetter();
void gameKeyEventKeyDown(SDL_Keycode sym);
void gameMoveEventMotion(SDL_Keycode sym);

//TODO: Move this to a separate file
typedef struct s_weapon {
	int 	type;	// 0 - melee, 1 - pistol, 2 - rifle, 3 - shotgun
	int		damage;
	int		ammo;
	int		clipSize;
	int		cooldown;
}	t_weapon;

typedef struct s_player {
	float		posX;
	float		posY;
	float		dir;
	float		fov; // we might define this in the config file
	float		speed;
	float		rotSpeed;

	int			health;
	int			armor;
	int			ammo;
	t_weapon	weapon;
}	t_player;

void	initPlayer(float posX, float posY, float dir);

extern t_player	*player;
