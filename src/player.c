# include "global.h"
# include "game.h"
# include "events.h"

t_player *player;

void gameKeyEventKeyDown(SDL_Keycode sym)
{
	//move player
	switch (sym)
		{
		case SDLK_ESCAPE:
			escapeHandler();
			break;
		case SDLK_w:
		case SDLK_UP:
			ft_printf("W KEY PRESSED\n");
			// move player dir
			player->posX += cos(player->dir) * player->speed;
			player->posY += sin(player->dir) * player->speed;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			// rotate player
			ft_printf("A KEY PRESSED\n");
			player->dir -= player->rotSpeed;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			ft_printf("S KEY PRESSED\n");
			player->posX -= cos(player->dir) * player->speed;
			player->posY -= sin(player->dir) * player->speed;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			ft_printf("D KEY PRESSED\n");
			player->dir += player->rotSpeed;
		break;
		default:
			break;
		}
		printf("Player pos: %f, %f rotation: %f\n", player->posX, player->posY, player->dir);
}

void gameMoveEventMotion(SDL_Keycode sym)
{
	// TODO WITH mouse motion change player direction
}

void	initPlayer(float posX, float posY, float dir)
{
	player = (t_player *)malloc(sizeof(t_player));
	player->posX = posX;
	player->posY = posY;
	player->dir = dir;
	player->fov = 60;
	player->speed = 0.1;
	player->rotSpeed = 0.1;
	player->health = 100;
	player->armor = 0;
	player->ammo = 0;
	player->weapon.type = 0;
	player->weapon.damage = 0;
	player->weapon.ammo = 0;
	player->weapon.clipSize = 0;
	player->weapon.cooldown = 0;
}