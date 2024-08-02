#include "global.h"

void	initFont(void *p) {
	t_Font	*f = (t_Font *)p;
	f->extraLarge = NULL;
	f->large = NULL;
	f->normal = NULL;
	f->small = NULL;
	f->extraSmall = NULL;
	f->name = NULL;
}

void	ImportFont(TTF_Font **tf, char *f, int p) {
	*tf = TTF_OpenFont(f, p);
	if (!tf) {
		ft_printf("Failed to load font! Font: %s\nTTF_Error: %s\n", f, TTF_GetError());
	}
}

void	calculateAndImportFont(int index, char *font) {
	char **path = ft_split(font, '/');
	const int baseWidth = 1920;
	const int baseHeight = 1080;

	float widthRatio = (float)WINDOW_WIDTH / baseWidth;
	float heightRatio = (float)WINDOW_HEIGHT / baseHeight;
	float averageRatio = (widthRatio + heightRatio) / 2.0f;
	gameEnv->fonts[index].name = ft_strdup(path[2]);
	ImportFont(&gameEnv->fonts[index].extraSmall, font, (int)(FONTSIZE_ESMALL * averageRatio));
	ImportFont(&gameEnv->fonts[index].small, font, (int)(FONTSIZE_SMALL * averageRatio));
	ImportFont(&gameEnv->fonts[index].normal, font, (int)(FONTSIZE_NORMAL * averageRatio));
	ImportFont(&gameEnv->fonts[index].large, font, (int)(FONTSIZE_LARGE * averageRatio));
	ImportFont(&gameEnv->fonts[index].extraLarge, font, (int)(FONTSIZE_ELARGE * averageRatio));
	ft_freesplit(path);
	free(font);
}

void	initFonts() {
	gameEnv->fonts = (t_Font *)getAndInitStruct(1, sizeof(t_Font), &initFont);

	TTF_Init();
	calculateAndImportFont(0, ft_strdup("resources/ttf/arial.ttf"));
}

void	closeFonts() {
	int	i = 0;
	while (gameEnv->fonts[i].name) {
		free(gameEnv->fonts[i].name);
		TTF_CloseFont(gameEnv->fonts[i].extraSmall);
		TTF_CloseFont(gameEnv->fonts[i].small);
		TTF_CloseFont(gameEnv->fonts[i].normal);
		TTF_CloseFont(gameEnv->fonts[i].large);
		TTF_CloseFont(gameEnv->fonts[i].extraLarge);
		i++;
	}
}

t_Font	*getFont(char *f) {
	int	i = 0;
	while (gameEnv->fonts[i].name) {
		if (!ft_strncmp(gameEnv->fonts[i].name, f, ft_strlen(gameEnv->fonts[i].name)))
			return &gameEnv->fonts[i];
		i++;
	}
	return NULL;
}