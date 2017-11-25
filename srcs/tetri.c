/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <saxiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:35 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/24 16:54:13 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fill_it.h"
#include "../includes/libft.h"

t_etrimino		*add_tetri(char **s, int nb, t_etrimino *old_list)
{
	t_etrimino	*list;
	t_etrimino	*temp;
	int			i;

	i = 0;
	if (!(list = (t_etrimino *)malloc(sizeof(*list))) ||
	!(list->str = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	list->str = s;
	list->letter = 'A' + nb;
	list->x = 0;
	list->y = 0;
	list->next = NULL;
	list->pre = NULL;
	if (!old_list)
		old_list = list;
	else
	{
		temp = old_list;
		while (temp->next)
			temp = temp->next;
		list->pre = temp;
		temp->next = list;
	}
	return (old_list);
}

void			remove_onete(char **map, int mpsize, t_etrimino *list)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mpsize)
	{
		j = -1;
		while (++j < mpsize)
		{
			if (map[i][j] == list->letter)
				map[i][j] = '.';
		}
	}
	if (list->y < mpsize - 1)
		list->y++;
	else if (list->y == mpsize - 1)
	{
		list->x++;
		list->y = 0;
	}
}

int				find_fit(t_map *map, t_etrimino *list)
{
	int		x;
	int		y;

	x = list->x;
	y = list->y;
	while (x < map->size)
	{
		while (y < map->size)
		{
			if (check_fill(map, list, x, y))
			{
				list->x = x;
				list->y = y;
				return (1);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

static int		empty_col(char **s)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[x][y] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (y);
}

char			**mv_left_top(char **s)
{
	int		i;
	int		j;
	int		y;
	int		k;

	k = 0;
	i = -1;
	y = empty_col(s);
	while (!ft_strchr(s[k], '#'))
		k++;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] == '#')
				ft_swap(&s[i][j], &s[i - k][j - y]);
		}
	}
	return (s);
}
