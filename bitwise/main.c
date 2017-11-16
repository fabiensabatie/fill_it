/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:28:32 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/16 18:29:16 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 21



void				ft_printbytetetri(short int c)
{
	short int i;

	i = 0;
	while (i < 16)
	{
		if (c & 1 << i)
			ft_putnbr(1);
		else
			ft_putnbr(0);
		i++;
		if (!(i % 4) && i > 3)
			ft_putchar('\n');
	}
}

static short int	*ft_move_tetri(short int* c)
{
	int i;

	i = 0;
	i = 16;

	while (!(*c & 1 << i))
	{
		i -= 4;
		if (i == 0)
		{
			*c = *c >> 1;
			i = 16;
		}
	}

	return (c);
}

short int	*ft_resize_tetri(short int *c, int old_size)
{
	short int *new_s_tet;
	if (!(new_s_tet = (short int*)ft_memalloc((old_size + 1) / 8 + 1)))
		return (NULL);

	int y = 0;
	int i = 0;
	while (i < (old_size + 1) * (old_size + 1))
	{
		 if (*c & (1 << i))
		 {
			 *new_s_tet = *new_s_tet | (1 << i);
			 ft_putendl("Got into if");
		 }
		 else if (!(i % 4))
		 {
			 *new_s_tet = *new_s_tet | (0 << (i + y));
			 ft_putendl("Got into else");
			 y++;
		 }
		 else
		 i++;
	}
	return (new_s_tet);
}


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
	ft_strrev(tet);
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



int main(void)
{
	char str[] = "..#.\\n.##.\\n..#.\\n....";
	short int c = ft_strtobyte(str);
	short int *c_tet;

	ft_printbytetetri(c);
	ft_putendl("");
	c_tet = &c;
	ft_move_tetri(c_tet);
	c_tet = ft_resize_tetri(c_tet, 4);
	ft_printbytetetri(c);
}
