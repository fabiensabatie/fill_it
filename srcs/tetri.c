/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:16:27 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 16:16:28 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fill_it.h"
#include <stdlib.h>
#include <stdio.h>

t_etrimino	*ft_newtetri(char **tab, char letter)
{
	t_etrimino *tet;

	if (!(tet = (t_etrimino*)malloc(sizeof(t_etrimino))))
		return (NULL);
	tet->tetrimino = tab;
	tet->letter = letter;
	tet->next = NULL;
	return (tet);
}

void		ft_print_tetri(t_etrimino *tet)
{
	char **tetri;

	tetri = tet->tetrimino;
	while (*tetri)
		ft_putendl(*tetri++);
	ft_putendl("");
}

static int	*ft_get_space(char **tab, int x, int y)
{
	int *space;

	space = (int *)malloc(sizeof(int) * 2);
	space[0] = x;
	space[1] = y;

	while (space[1] < 4)
	{
		space[0] = 0;
		while (space[0] < 4)
		{
			if (tab[space[1]][space[0]] == '#')
				return (space);
			space[0]++;
		}
		space[1]++;
	}
	return (0);
}

void		ft_set_tetri(char **tab)
{
	int *pos;
	int i;
	int y;

	i = 0;
	pos = ft_get_space(tab, 0, 0);
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab[i][y] == '#')
				ft_swap(&tab[i][y], &tab[i - pos[1]][y - pos[0]]);
			y++;
		}
		i++;
	}
}
