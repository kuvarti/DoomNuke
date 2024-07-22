#include "global.h"
#include "levelEditor.h"

int renderMain() {
	while (gameEnv->RunningState) {
		printf("RunningState: %d\n", gameEnv->RunningState);
		if (gameEnv->RunningState == 1) {
			showMainMenu();
		}
		if (gameEnv->RunningState == 2) {
			initPlayer(10, 10, 0);
			render_func(player);
		}
		if (gameEnv->RunningState == 3) {
			initEditor();
			lvlEditor();
			freeEditor();
		}
	}
	return 1;
}
