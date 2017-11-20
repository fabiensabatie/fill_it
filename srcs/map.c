/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:16:21 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 23:42:59 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fill_it.h"
#include <stdlib.h>

t_map	*ft_newmap(t_map *prev_map, int mapsize)
{
	t_map *map;
	int i;

	i = 0;
	if (prev_map)
		free(prev_map);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->map = (char**)malloc(sizeof(char*) * mapsize + 1)))
		return (NULL);
	while (i < mapsize)
	{
		if (!(map->map[i] = (char*)malloc(sizeof(char*) * mapsize)))
			return (NULL);
		i++;
	}
	map->map[i] = 0;
	map->map_size = mapsize;
	return (map);
}

int		ft_minmapsize(t_etrimino *tet)
{
	int count;
	int sqr;

	count = 0;
	sqr = 0;
	while ((tet = tet->next))
		count++;
	while (sqr * sqr < 4 * count)
		sqr++;
	return (sqr);
}
