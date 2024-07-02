#include "levelEditor.h"
#include "stdlib.h"
#include "libft.h"

#define MENU1 "Select An Existing Map"
#define MENU2 "Create New Map"
#define MENU3 "Return Main Menu"

//	Select Existing map
//	Create New map
//	Return Main menu
char	**setMenuItems() {
	char	**ret;
	int		i = -1;

	ret = (char **)malloc(sizeof(char *) * 4);
	ret[++i] = malloc(ft_strlen(MENU1));
	ret[i] = MENU1;
	ret[++i] = malloc(ft_strlen(MENU2));
	ret[i] = MENU2;
	ret[++i] = malloc(ft_strlen(MENU3));
	ret[i] = MENU3;
	ret[++i] = NULL;
	return ret;
}