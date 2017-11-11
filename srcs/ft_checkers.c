/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:03:58 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/11 13:03:59 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fill_it.h"
#include "libft.h"

/*
** • Exactement 4 lignes de 4 caractères suivis d’un retour à la ligne.
** • Un Tetriminos est une pièce de Tetris classique composée de 4 blocs.
** • Chaque caractère doit être, soit un ’#’ lorsque la case correspond à
** l’un des 4 blocs d’un Tetriminos, soit un ’.’ lorsque la case est vide.
** • Chaque bloc d’un Tetriminos doit être en contact avec au moins un
** autre bloc sur l’un ou l’autre de ses 4 côtés.
*/
static	int		ft_only_good_char
static	char	*ft_get_tetriminos_maps(char *filename)
{
	char	*tetbuffer;
	int		fd;

	if (!(tetbuffer = (char*)malloc(TET_BUFF_SIZE)))
		return (0);
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("File does not exist :(\n");
			return (0);
		}
		read(fd, tetbuffer, TET_BUFF_SIZE);
		close(fd);
	}
	return (tetbuffer);
}

static	int		ft_tetriminos_map_is_valid(char *maps)
{
	unsigned int ncounter;
	unsigned int i;

	ncounter = 0;
	i = 4;
	if (maps)
	{
		while (maps[i])
		{
			if (maps[i] != '\n')
			{
				ft_putstr("The set of tetriminos is invalid :(\n");
				return (0);
			}
			ncounter++;
			if (ncounter == 4)
			{
				i++;
				ncounter = 0;
			}
			i += 5;
		}
	}
	return (ft_only_good_char(maps));
}

int		ft_allisgood(int argc, const char** argv)
{
	char *map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit map\n");
		return (0);
	}
	if (!(map = ft_get_tetriminos_maps((char *)argv[1])))
		return (0);
	if (!ft_tetriminos_map_is_valid(map))
		return (0);
	return (1);
}
