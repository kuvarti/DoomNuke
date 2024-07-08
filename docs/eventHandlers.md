# Usage of Events
In every different state program has different behaviors. So he have function pointors for different behaviors, because no need the write 182938 `if`.

Functions Pointers Located In:
```c
gameEnv->event;

typedef struct s_Events {
	t_KeyPress  keyPressed;
	void (* textInputHandler)(char *);
	void (* keyUpHandler)(SDL_Keycode);
	void (* keyDownHandler)(SDL_Keycode);
	void (* lMouseButtonHandler)(t_2dVector);
	void (* rMouseButtonHandler)(t_2dVector);
	void (* MouseMotionHandler)(t_2dVector);
}	t_Events;
```

Handler will be executed when any event is triggered and if handler exists. So if one of the handlers is not needed, set it to NULL, otherwise an older event handler will be executed.

### Example:
In the Level editor menu, i just need Up and Down arrow press and text input. I dont use any mouse event and setted NULL.

If i dont set NULL mouse events, main menu mouse events will be executed because Editor menu opens after MainMenu. 
```c
void	editorMenuEvents() {
	gameEnv->event.keyUpHandler = NULL;
	gameEnv->event.keyDownHandler = &lvlEditorMenuKeyDownHandler;
	gameEnv->event.textInputHandler = &lvlEditorMenuTextinputHandler;
	gameEnv->event.lMouseButtonHandler = NULL;
	gameEnv->event.rMouseButtonHandler = NULL;
	gameEnv->event.MouseMotionHandler = NULL;
}
```