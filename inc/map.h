#pragma once

#define MAP_WIDTH 6
#define MAP_HEIGHT 6

// TODO: After generating better map system use this struct
typedef struct s_sectorlst
{
	int x;
	int y;
	int sector;
	struct s_sectorlst *next;
} t_sectorlst;

// TODO: remove this after generating map system
static int map[MAP_WIDTH][MAP_HEIGHT] = {
	{1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1}};

int get_map_value(int x, int y);
