#include "levelEditor.h"
#include "stdlib.h"
#include "libft.h"

//	Select Existing map
//	Create New map
//	Return Main menu

t_LevelEditorMenuItem	*setMenuItems(){
	t_LevelEditorMenuItem	*ret = NULL, *tmp = NULL, *prev = NULL;

	tmp = (t_LevelEditorMenuItem *)malloc(sizeof(t_LevelEditorMenuItem));
	tmp->active = &selectExistingMap;
	tmp->flags = LVLEDITORMENU_IS_ACTIVE;
	tmp->title = malloc(ft_strlen(LVLEDITORMENU1) + 1);
	tmp->title = ft_strdup(LVLEDITORMENU1);
	tmp->next = NULL;
	ret = tmp; prev = tmp;

	tmp = (t_LevelEditorMenuItem *)malloc(sizeof(t_LevelEditorMenuItem));
	tmp->active = *createNewMap;
	tmp->flags = 0;
	tmp->title = malloc(ft_strlen(LVLEDITORMENU2) + 1);
	tmp->title = ft_strdup(LVLEDITORMENU2);
	tmp->next = NULL;
	prev->next = tmp; prev = tmp;

	tmp = (t_LevelEditorMenuItem *)malloc(sizeof(t_LevelEditorMenuItem));
	tmp->active = &returnMainMenu;
	tmp->flags = 0;
	tmp->title = malloc(ft_strlen(LVLEDITORMENU3) + 1);
	tmp->title = ft_strdup(LVLEDITORMENU3);
	tmp->next = NULL; prev->next = tmp;
	
	return ret;
}