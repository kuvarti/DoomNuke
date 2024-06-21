#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "map.h"

int get_map_value(int x, int y)
{
	return map[y][x];
}
