#include "global.h"
#include "levelEditor.h"

int renderMain() {
	while (gameEnv->RunningState) {
		if (gameEnv->RunningState == 1) {
			showMainMenu();
		}
		if (gameEnv->RunningState == 2) {
			//TODO Raycast;
		}
		if (gameEnv->RunningState == 3) {
			initEditor();
			lvlEditor();
			freeEditor();
		}
	}
	return 1;
}
