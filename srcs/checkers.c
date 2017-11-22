/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:15:51 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 16:15:54 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fill_it.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

static char		**ft_check_conn(char **tetri)
{
	int i;
	int y;
	int conn;

	conn = 0;
	i = 0;
	while (tetri[i])
	{
		y = 0;
		while (tetri[i][y])
		{
			if (y < 3 && tetri[i][y] == '#')
				if (tetri[i][y + 1] == '#')
					conn++;
			if (i < 3 && tetri[i][y] == '#')
				if (tetri[i + 1][y] == '#')
					conn++;
			y++;
		}
		i++;
	}
	if (conn != 3 && conn != 4)
		ft_putnexit("error");
	return  (tetri);
}

static void		ft_is_valid(char *tetri)
{
	int i;
	int blocs;
	int conn;

	i = 0;
	blocs = 0;
	conn = 0;
	if (tetri[4] != '\n' || tetri[9] != '\n'
	|| tetri[14] != '\n' || tetri[19] != '\n')
		ft_putnexit("error");
	while (tetri[i])
	{
		if (!(tetri[i] == '#' || tetri[i] == '\n' || tetri[i] == '.'))
			ft_putnexit("error");
		if (tetri[i] == '#')
			blocs++;
		i++;
	}
	if (blocs != 4)
		ft_putnexit("error");
}

t_etrimino		*ft_read_entry(const char *filename)
{
	t_etrimino	*tetri;
	t_etrimino	*start;
	char		*buffer;
	char		letter;
	int			fd;

	letter = 'A';
	if (!(fd = open(filename, O_RDONLY)))
		ft_putnexit("error");
	if (!(tetri = ft_newtetri(&buffer, letter)))
		ft_putnexit("error");
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		ft_putnexit("error");
	start = tetri;
	while (read(fd, buffer, BUFF_SIZE))
	{
		ft_is_valid(buffer);
		tetri->tetrimino = ft_check_conn(ft_strsplit(buffer, '\n'));
		ft_set_tetri(tetri->tetrimino);
		letter++;
		if (!(tetri->next = ft_newtetri(&buffer, letter)))
			return (NULL);
		tetri->next->prev = tetri;
		ft_print_tetri(tetri);
		tetri = tetri->next;
	}
	tetri->prev->next = NULL;
	return (start);
}

int		ft_check_piece(t_map *map, t_etrimino* tetrimino)
{
	char **tet;
	int y;
	int i;
	int lastx;
	int lasty;
	//ft_putstr("2\n");
	lastx = map->x;
	//ft_putstr("3\n");
	lasty = map->y;
	tet = tetrimino->tetrimino;
	i = 0;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tet[i][y] == '#')
			{
				//ft_putstr("3Hre ?\n");
				if (i + lasty >= map->map_size || y + lastx >= map->map_size)
				{
					//ft_putstr("4Hre ?\n");
					//printf("out of map\n");
					return (0);
				}
				//ft_putstr("5Hre ?\n");
				if (map->map[lasty + i][lastx + y] != '.')
				{
					//printf("Comparing\n");
					return (0);
				}
			}
			y++;
		}
		i++;
	}
	//ft_putstr("4\n");
	//ft_print_map(map);
	//ft_putstr("5\n");
	return (1);
}
