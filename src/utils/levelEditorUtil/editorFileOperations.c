#include "global.h"

void	readAndInitSectorWalls(t_sector *sector, t_EditorSectors *es)
{
	t_WallVertex	*tmp = NULL;
	t_2dVector		start;

	start = sector->walls[0].wallStart;
	for (int j = 0; j <= sector->wallCount; j++)
	{
		t_WallVertex *new = (t_WallVertex *)getAndInitStruct(1, sizeof(t_WallVertex), &initWallVertex);
		if (j == sector->wallCount)
			new->coordinate = start;
		else 
			new->coordinate = sector->walls[j].wallStart;
		if (tmp) {
			tmp->prev = new;
			new->next = tmp;
		}
		es->walls = new;
		tmp = new;
	}
}

void	readAndInitFile() 
{
	t_EditorSectors	*tmp = NULL;

	getMapFd(gameEnv->editor->openedFile);
	for (int i = 0; i < gameEnv->map.sectorCount; i++)
	{
		t_EditorSectors *new = (t_EditorSectors *)getAndInitStruct(1, sizeof(t_EditorSectors), &initEditorSector);
		if (tmp) {
			tmp->prev = new;
			new->next = tmp;
		}
		new->sectorNo = gameEnv->map.sector[i].sectorNo;
		readAndInitSectorWalls(&gameEnv->map.sector[i], new);
		gameEnv->editor->editor.sectors = new;
		tmp = new;
	}
	
}