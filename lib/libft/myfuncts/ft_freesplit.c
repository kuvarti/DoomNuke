/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:02:36 by aeryilma          #+#    #+#             */
/*   Updated: 2024/06/27 12:48:24 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_freesplit(char **ptr)
{
    int i = -1;
    while (ptr[++i]) {
        free(ptr[i]);
    }
    free(ptr);
}
