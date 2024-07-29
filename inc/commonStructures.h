#pragma once 
#include <stddef.h>

typedef struct s_2dVector {
    int x;
    int y;
}   t_2dVector;

int		compare2dVector(t_2dVector, t_2dVector);
void	*getAndInitStruct(int number, size_t size, void (* initStruct)(void *));