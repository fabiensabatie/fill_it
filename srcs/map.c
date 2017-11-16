/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:18:41 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/16 15:18:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"
#include <string.h>
#include <stdlib.h>

t_map	*ft_newmap(int size)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->map_size = size;
	if (!(map->map = (char*)malloc(size / 8 + 1)))
		return (NULL);
	return (map);
}

int		ft_minmapsize(int numberoftetris)
{
	int dots;
	int size;

	size = 0;
	dots = 4 * numberoftetris;
	while (size * size < dots)
		size++;
	return (size);
}
