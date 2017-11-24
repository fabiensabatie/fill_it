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
#include "libft.h"

tetri_list	*add_tetri(char **s, int nb, tetri_list *old_list)
{
	tetri_list	*list;
	tetri_list	*temp;
	int			i;

	i = 0;
	if(!(list = (tetri_list *)malloc(sizeof(*list))))
		return (NULL);
	if(!(list->str = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	list->str = s;
	list->letter = 'A' + nb;
	list->x = 0;
	list->y = 0;
	list->next = NULL;
	list->pre = NULL;
	if(!old_list)
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


void	remove_onete(char **map, int mpsize, tetri_list *list)
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

int		find_fit(char **map, int mpsize, tetri_list *list)
{
	int		x;
	int		y;

	x = list->x;
	y = list->y;
	while ( x  < mpsize)
	{
		while (y < mpsize)
		{
			if (check_fill(map, mpsize, list, x, y))
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

int		empty_col(char **s)
{
	int		x;
	int		y;

	y = 0;
	while ( y < 4)
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

void  mv_left_top(char **s)
{
	int		i;
	int		j;
	int		y;
	int		k;

	k = 0;
	i = -1;
	y = empty_col(s);
	while (!ft_strchr(s[k],'#'))
		k++;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if(s[i][j] == '#')
				ft_swap(&s[i][j], &s[i - k][j - y]);
		}
	}
}
