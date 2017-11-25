/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <saxiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:35 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/24 16:53:19 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/fcntl.h>
#include "fill_it.h"
#include "../includes/libft.h"

void	ft_exit(char const *s)
{
	ft_putendl(s);
	exit(1);
}

int		main(int ac, char **av)
{
	t_etrimino	*list;
	t_map		*n_map;
	t_map		*temp;
	int			fd;

	if (ac != 2)
		ft_exit("error");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_exit("error");
	list = ft_readfile(fd);
	n_map = new_map(mini_sq(list));
	while (!solve_map(n_map, &list))
	{
		if (list->letter != 'A')
			list = list->pre;
		else
		{
			temp = n_map;
			n_map = new_map(temp->size + 1);
			free(temp);
		}
	}
	print_map(n_map->map, n_map->size);
	return (0);
}
