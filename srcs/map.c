/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:16:21 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 16:16:22 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fill_it.h"
#include <stdlib.h>

t_map	*ft_newmap(int mapsize)
{
	t_map *map;
	(void)mapsize;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	return (0);
}
