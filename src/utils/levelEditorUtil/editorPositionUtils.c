#include "global.h"

t_2dVector	calcGridIntersection(t_2dVector c) {
	t_Editor	*editor;
	t_2dVector	ret;

	if (c.x <= 0 || c.y <= 0) {
		return (t_2dVector){0, 0};
	}
	editor = &gameEnv->editor->editor;
	ret.x = (c.x / editor->gridSize) * editor->gridSize;
	ret.y = (c.y / editor->gridSize) * editor->gridSize;
	if (editor->gridSize / 2 < c.x % editor->gridSize)
		ret.x += editor->gridSize;
	if (editor->gridSize / 2 < c.y % editor->gridSize)
		ret.y += editor->gridSize;
	return ret;
}

t_2dVector	calcCoordinate(t_2dVector c) {
	t_Editor	*editor;
	t_2dVector	ret;

	editor = &gameEnv->editor->editor;
	ret.x = (c.x - (editor->anchor.x + editor->offset.x)) / editor->gridSize;
	ret.y = (c.y - (editor->anchor.y + editor->offset.y)) / editor->gridSize;
	return ret;
}

t_2dVector	reCalsPosition(t_2dVector c) {
	t_Editor	*editor;
	t_2dVector	ret;

	editor = &gameEnv->editor->editor;
	ret.x = editor->anchor.x + (c.x * editor->gridSize) + editor->offset.x;
	ret.y = editor->anchor.y + (c.y * editor->gridSize) + editor->offset.y;
	return ret;
}