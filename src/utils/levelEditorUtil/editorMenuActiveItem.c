#include "global.h"

void	clearSubItems(t_LevelEditorMenuItem *item) {
	t_LevelEditorMenuItem	*tmp, *del;

	item->flags -= LVLEDITORMENU_IS_EXPANDED;
	tmp = item->next;
	while (tmp->flags & LVLEDITORMENU_IS_SUB) {
		del = tmp;
		tmp = tmp->next;
		if (del->flags & LVLEDITORMENU_IS_INPUT){
			free(gameEnv->editor->menu.newFile);
			gameEnv->editor->menu.newFile = NULL;
		}
		free(del);
	}
	item->next = tmp;
}

t_LevelEditorMenuItem	*createNewSub(char *title, t_LevelEditorMenuItem *next) {
	t_LevelEditorMenuItem	*ret;

	ret = (t_LevelEditorMenuItem *)malloc(sizeof(t_LevelEditorMenuItem));
	ret->active = &mapSelectionBtn;
	ret->flags = LVLEDITORMENU_IS_SUB;
	ret->title = malloc(ft_strlen(title) + 1);
	ret->title = ft_strdup(title);
	ret->next = next;
	return ret;
}

void	changeActiveItem(int new) {
	t_LevelEditorMenuItem *tmp = NULL, *prev = NULL;

	tmp = gameEnv->editor->menu.menuItems;
	while (tmp) {
		if ((LVLEDITORMENU_IS_ACTIVE & tmp->flags) && (LVLEDITORMENU_IS_EXPANDED & tmp->flags)) {
			prev = NULL;
			tmp = tmp->next;
			continue;
		}
		if (LVLEDITORMENU_IS_ACTIVE & tmp->flags) {
			if (new > 0) {
				if (!(tmp->next))
					break;
				if ((LVLEDITORMENU_IS_SUB & tmp->flags) == (LVLEDITORMENU_IS_SUB & tmp->next->flags)) {
					tmp->flags -= LVLEDITORMENU_IS_ACTIVE;
					tmp->next->flags += LVLEDITORMENU_IS_ACTIVE;
					break;
				}
			} else {
				if (!prev)
					break;
				if ((LVLEDITORMENU_IS_SUB & tmp->flags) == (LVLEDITORMENU_IS_SUB & prev->flags)) {
					tmp->flags -= LVLEDITORMENU_IS_ACTIVE;
					prev->flags += LVLEDITORMENU_IS_ACTIVE;
					break;
				}
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}