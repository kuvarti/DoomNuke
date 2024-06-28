#include "map.h"
#include "global.h"

void	initSurface(t_surface *s) {
	(*s).height = 0;
	(*s).placeholder = 0;
	(*s).transparency = 0;
}

void	initSector(t_sector *s) {
	(*s).sectorNo = 0;
	(*s).walls = NULL;
	(*s).wallCount = 0;
	(*s).placeholder = 0;
	initSurface(&((*s).Floor));
	initSurface(&((*s).Ceiling));
}

void	init2dVector(t_2dVector *v) {
	(*v).x = 0;
	(*v).y = 0;
}

void	initWall(t_wall *w) {
	init2dVector(&((*w).wallStart));
	init2dVector(&((*w).wallEnd));
	initSurface(&((*w).texture));
	(*w).portal = 0;
}

t_wall		*getWall(int number) {
	t_wall	*ret = NULL;
	int i = -1;

	ret = (t_wall *)malloc(sizeof(t_wall) * (number + 1));
	while (++i <= number) {
		initWall(&ret[i]);
	}
	return ret;
}

t_sector	*getSector(int number) {
	t_sector	*ret = NULL;
	int			i = -1;

	ret = (t_sector *)malloc(sizeof(t_sector) * (number + 1));
	while (++i <= number) {
		initSector(&ret[i]);
	}
	return ret;
}

char	*getFullText(int file) {
	char	*ret = 0, *buf = 0;

	if (buf)
		free(buf);
	buf = get_next_line(file);
	while (1) {
		if (buf) {
			ret = ft_gnl_strjoin(ret, buf);
			free(buf);
		} else {
			break;
		}
		buf = get_next_line(file);
	}
	return (ret);
}

t_wall	*parseWalls(char **mapLines, int cursor, int len) {
	t_wall	*ret;
	char	**line;
	int		wallCursor, tmp = cursor - 1;

	ret = getWall(len);
	while ((++tmp - cursor) < len) {
		wallCursor = tmp - cursor;
		line = ft_split(mapLines[tmp], ' ');
		ret[wallCursor].wallStart.x = ft_atoi(line[0]);
		ret[wallCursor].wallStart.y = ft_atoi(line[1]);
		ret[wallCursor].wallEnd.x = ft_atoi(line[2]);
		ret[wallCursor].wallEnd.y = ft_atoi(line[3]);
		ret[wallCursor].portal = ft_atoi(line[4]);
		ret[wallCursor].texture.transparency = ft_atoi(line[5]);
		//TODO: Texture number
		ft_freesplit(line);
	}
	return (ret);
}

t_sector	*parseSector(char **mapLines) {
	int		i = -1, tmp = 0;
	int		sectorCursor = 0, wallCount;
	char	**line;
	while (1) {
		if (!tmp && ft_strnstr(mapLines[++i], "[Sector]", 9)) {
			tmp = i + 1;
			continue;
		}
		if (ft_strnstr(mapLines[++i], "[Wall]", 7)) {
			break;
		}
	}
	gameEnv.map.sector = getSector(i - tmp);
	while (1) {
		line = ft_split(mapLines[tmp++], ' ');
		wallCount = ft_atoi(line[2]);
		gameEnv.map.sector[sectorCursor].sectorNo = ft_atoi(line[0]);
		gameEnv.map.sector[sectorCursor].wallCount = wallCount;
		gameEnv.map.sector[sectorCursor].Floor.height = atof(line[3]);
		gameEnv.map.sector[sectorCursor].Ceiling.height = atof(line[5]);
		gameEnv.map.sector[sectorCursor].walls = parseWalls(mapLines, (i + 1) + ft_atoi(line[1]), wallCount);
		if (tmp == i)
			break;
		else
			sectorCursor++;
		ft_freesplit(line);
	}
	if (line)
		ft_freesplit(line);
}

int   getMap(char *file)
{
	t_map	mapRet;
	char	*txt, **lines;
	int fd = open(file, O_RDONLY);

	if (fd < 0) {
		return (!ft_printf("File Not Found :%s\n", file));
	}
	lines = ft_split(getFullText(fd), '\n');
	close(fd);
	parseSector(lines);
	ft_freesplit(lines);
	return 1;
}