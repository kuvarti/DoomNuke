#include "global.h"
#include <dirent.h>

void	mapSelectionBtn() {
	char	*fileN;
	fileN = ft_strjoin("resources/maps/", gameEnv->editor->menu.newFile);
	int fd = open(fileN, O_RDWR | O_CREAT, 0644);
	ft_printf("Map selected as : *%s (%d)\n", fileN, fd);
	if (fd <= 0) {
		ft_printf("Some error occured while opening file %d\n", fileN);
		return ;
	}
	gameEnv->editor->openedFile = fd;
	gameEnv->editor->menu.menuActive = 0;
	gameEnv->editor->escapeStatus = 0;
}

void	selectExistingMap() {
	struct dirent			*entry;
	t_LevelEditorMenuItem	*tmp, *next;

	DIR *dp = opendir("resources/maps");
	if (dp == NULL) {
		perror("opendir");
		return;
	}

	tmp = gameEnv->editor->menu.menuItems;
	tmp->flags += LVLEDITORMENU_IS_EXPANDED;

	next = tmp->next;
	while ((entry = readdir(dp))) {
		if (ft_strlen(entry->d_name) > 5 && ft_strrcmp(entry->d_name, ".map") == 0) {
			tmp->next = createNewSub(entry->d_name,next);
			if (tmp->flags & LVLEDITORMENU_IS_EXPANDED)
				tmp->next->flags += LVLEDITORMENU_IS_ACTIVE;
			tmp = tmp->next;
		}
	}
	closedir(dp);
}

void	createNewMap() {
	t_LevelEditorMenuItem *tmp, *next;

	tmp = gameEnv->editor->menu.menuItems;
	while (tmp && ft_strncmp(LVLEDITORMENU2, tmp->title, ft_strlen(tmp->title)))
		tmp = tmp->next;

	tmp->flags += LVLEDITORMENU_IS_EXPANDED;
	next = tmp->next;
	tmp->next = createNewSub(ft_strdup("File Name: "), next);
	tmp->next->flags += LVLEDITORMENU_IS_INPUT | LVLEDITORMENU_IS_ACTIVE;
	if (gameEnv->editor->menu.newFile)
		free(gameEnv->editor->menu.newFile);
	gameEnv->editor->menu.newFile = ft_strdup(".map");
}

void	returnMainMenu() {
	gameEnv->editor->menu.menuActive = 0;
	gameEnv->RunningState = 1;
	if (gameEnv->editor->openedFile)
		close(gameEnv->editor->openedFile);
	gameEnv->editor->openedFile = 0;
}

void	escapeMenuNoButton() {
	gameEnv->editor->menu.menuActive = 0;
	gameEnv->editor->escapeStatus = 0;
}