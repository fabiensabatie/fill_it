/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:31:49 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/12 20:31:52 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fill_it.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Converts the char* string from input to a byte.
*/

static	short	int	ft_strtobyte(char *str)
{
	char		tet[BUFF_SIZE + 1];
	short	int i;
	short	int c;
	short	int n;
	short	int hash;

	hash = 0;
	c = 0;
	n = 0;
	i = 15;
	ft_strcpy(tet, str);
	while (n < (short)ft_strlen(tet))
	{
		if (tet[n] == '#')
		{
			hash++;
			c = c | (1 << i);
		}
		if (tet[n] == '.' || tet[n] == '#')
			i--;
		n++;
	}
	if (hash != 4)
		ft_putnexit("error");
	return (c);
}

/*
** Print bits of tetri.
*/

void				ft_printbytetetri(t_etrimino *tet)
{
	short int i;
	short int c;

	i = 0;
	c = tet->c_tet;
	while (i < 16)
	{
		if (c & 1 << i)
			ft_putchar(tet->letter);
		else
			ft_putchar('.');
		i++;
		if (!(i % 4) && i > 3)
			ft_putchar('\n');
	}
}

t_etrimino			*ft_newtetri(char *tet)
{
	static char let = 'A';
	t_etrimino	*tetrimino;

	if (!(tetrimino = (t_etrimino*)malloc(sizeof(tetrimino))))
		return (NULL);
	tetrimino->c_tet = ft_strtobyte(ft_strrev(tet));
	tetrimino->letter = let;
	let++;
	return (tetrimino);
}
