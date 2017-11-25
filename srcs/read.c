/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <saxiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:35 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/24 17:02:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../includes/libft.h"
#include "fill_it.h"

int			check_fill(t_map *map, t_etrimino *list, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((list->str)[i][j] == '#')
			{
				if (x + i >= map->size || y + j >= map->size
				|| map->map[x + i][y + j] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	only_dot_hash(char *s, int len)
{
	int		hash_count;
	int		index;

	hash_count = 0;
	index = 0;
	while (index < len)
	{
		if ((!((index + 1) % 5) || index == len - 1))
		{
			if (s[index] && s[index] != '\n')
				ft_exit("error");
		}
		else
		{
			if (s[index] != '.' && s[index] != '#')
				ft_exit("error");
			if (s[index] == '#')
				hash_count++;
		}
		index++;
	}
	if (hash_count != 4)
		ft_exit("error");
}

static char	*valid_tetri(char *s)
{
	int		touch_count;
	int		i;

	touch_count = 0;
	i = 0;
	while (i < BUFF_SIZE)
	{
		if (s[i] == '#')
		{
			if (i + 5 < BUFF_SIZE && s[i + 5] == '#')
				touch_count++;
			if (i != 3 && i != 8 && i != 13 && i != 18)
			{
				if (i + 1 < BUFF_SIZE && s[i + 1] == '#')
					touch_count++;
			}
		}
		i++;
	}
	if (touch_count != 3 && touch_count != 4)
		ft_exit("error");
	return (s);
}

t_etrimino	*ft_readfile(int fd)
{
	char		*buff;
	char		**s;
	int			nb_tetri;
	t_etrimino	*list;
	int			test_n;

	nb_tetri = 0;
	list = NULL;
	test_n = 0;
	if (!(buff = (char*)malloc(BUFF_SIZE)))
		return (NULL);
	while (read(fd, buff, BUFF_SIZE))
	{
		if (nb_tetri > 25)
			ft_exit("error");
		only_dot_hash(valid_tetri(buff), BUFF_SIZE);
		s = ft_strsplit((const char *)buff, '\n');
		list = add_tetri(mv_left_top(s), nb_tetri++, list);
		test_n = read(fd, buff, 1);
		ft_bzero(buff, BUFF_SIZE);
	}
	if (nb_tetri == 0 || test_n == 1)
		ft_exit("error");
	return (list);
}
