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
#include <stdio.h>

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
		if (!(map->map[i] = (char*)malloc(sizeof(char*) * mapsize + 1)))
			return (NULL);
		ft_memset(map->map[i], '.', mapsize);
		i++;
	}
	map->map[i] = 0;
	map->map_size = mapsize;
	map->x = 0;
	map->y = 0;
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

void		ft_print_map(t_map *map)
{
	char **toprint;
	int mapsize = map->map_size;
	int i = 0;
	int j = 0;

	toprint = map->map;
	while (i < mapsize)
	{
		j = 0;
		while (j < mapsize)
		{
			ft_putchar(toprint[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static int	ft_change_free(t_map *map)
{
	ft_putstr("Trying to change the free from ");
	ft_putnbr(map->x);
	ft_putchar(' ');
	ft_putnbr(map->y);
	ft_putstr(" to ");
	map->x++;
	if (map->x % map->map_size == 0)
	{
		map->x = 0;
		map->y++;
	}
	ft_putnbr(map->x);
	ft_putchar(' ');
	ft_putnbr(map->y);
	ft_putchar('\n');
	if (map->y >= map->map_size || map->x == map->map_size)
		return (0);
	return (1);
}


int		ft_solve_map(t_map *map, t_etrimino *tetriminos, int x, int y)
{
	map->x = x;
	map->y = y;
	t_etrimino *start;

	start = tetriminos;
	while (tetriminos)
	{

		while (!ft_check_piece(map, tetriminos))
		{
			ft_putchar(tetriminos->letter);
			ft_putstr(" doesn't fit in ");
			ft_putnbr(map->x);
			ft_putchar(' ');
			ft_putnbr(map->y);
			ft_putchar('\n');
			if (!ft_change_free(map))
			{
				ft_putstr("Could not change the free, we reached the end of the map.\n");
				if (tetriminos->letter == 'A')
					return ft_solve_map(ft_newmap(map, map->map_size + 1), start, 0, 0);
				else
				{
					ft_rem_tetri(map, tetriminos->prev);
					ft_putstr("About to replace ");
					ft_putchar(tetriminos->prev->letter);
					ft_putstr(" from ");
					ft_putnbr(tetriminos->prev->x);
					ft_putchar(' ');
					ft_putnbr(tetriminos->prev->y);
					ft_putstr(" to ");
					ft_putnbr(tetriminos->prev->x + 1);
					ft_putchar(' ');
					ft_putnbr(tetriminos->prev->y);
					ft_putchar('\n');
					ft_putstr("The map size is : ");
					ft_putnbr(map->map_size);
					ft_putendl("");
					ft_putendl("");
					// The segfault comes from the tet-prev-x / y
					return ft_solve_map(map, tetriminos->prev, tetriminos->prev->x + 1, tetriminos->prev->y);
				}
			}
		}
		ft_putstr("The piece ");
		ft_putchar(tetriminos->letter);
		ft_putstr(" fits in ");
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(y);
		ft_putendl("");
		ft_putendl("");
		ft_place_tetri(map, tetriminos);
		//printf("%c has been put in map[%i][%i]\n", tetriminos->letter, map->y, map->x);
		tetriminos = tetriminos->next;
		map->x = 0;
		map->y = 0;

		ft_print_map(map);
		ft_putendl("");
	}

	return (1);
}
