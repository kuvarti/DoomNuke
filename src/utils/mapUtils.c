#include "map.h"

void	init2dVector(void *p) {
	t_2dVector	*v = (t_2dVector *)p;
	(*v).x = 0;
	(*v).y = 0;
}

void	initSurface(void *p) {
	t_surface	*s = (t_surface *)p;
	(*s).height = 0;
	(*s).placeholder = 0;
	(*s).transparency = 0;
}

void	initSector(void *p) {
	t_sector	*s = (t_sector *)p;
	(*s).sectorNo = 0;
	(*s).walls = NULL;
	(*s).wallCount = 0;
	(*s).placeholder = 0;
	initSurface(&((*s).Floor));
	initSurface(&((*s).Ceiling));
}

void	initWall(void *p) {
	t_wall		*w = (t_wall *)p;
	init2dVector(&((*w).wallStart));
	init2dVector(&((*w).wallEnd));
	initSurface(&((*w).texture));
	(*w).portal = 0;
}