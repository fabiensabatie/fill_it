/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <saxiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:35 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/24 16:53:08 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fill_it.h"
#include "../includes/libft.h"

int			mini_sq(t_etrimino *list)
{
	int			i;
	t_etrimino	*temp;

	i = 1;
	temp = list;
	while (temp->next)
		temp = temp->next;
	while (i * i < (temp->letter - 'A' + 1) * 4)
		i++;
	return (i);
}

t_map		*new_map(int size)
{
	int			i;
	int			j;
	t_map		*newmap;

	i = -1;
	if (!(newmap = (t_map*)malloc(sizeof(*newmap))))
		return (NULL);
	if (!(newmap->map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (++i < size)
	{
		if (!((newmap->map)[i] = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		j = -1;
		while (++j < size)
			(newmap->map)[i][j] = '.';
	}
	newmap->size = size;
	newmap->add_map = newmap;
	return (newmap);
}

void		print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
}

static void	fill_map(char **map, t_etrimino *list)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((list->str)[i][j] == '#')
				map[list->x + i][list->y + j] = list->letter;
			j++;
		}
	}
}

int			solve_map(t_map *map, t_etrimino **list)
{
	if (*list)
	{
		if (!find_fit(map, *list))
		{
			(*list)->x = 0;
			(*list)->y = 0;
			if ((*list)->letter != 'A')
				remove_onete(map->map, map->size, (*list)->pre);
			return (0);
		}
		else
		{
			fill_map(map->map, (*list));
			(*list) = (*list)->next;
			return (solve_map(map, list));
		}
	}
	return (1);
}
