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
#include "fill_it.h"
#include "libft.h"

void	ft_exit(char const *s)
{
	ft_putendl(s);
	exit(1);
}

int		main(int ac, char **av)
{
	tetri_list	*list;
	tetri_list	**ptr_lst;
	tetri_map	*n_map;
	tetri_map	*temp;

	if(ac != 2)
		ft_exit("not valid file number");
	list = ft_readfile(av[1]);
	n_map = new_map(mini_sq(list));
	ptr_lst = &list;
	while (!solve_map(n_map, ptr_lst))
	{
		if ((*ptr_lst)->letter != 'A')
			*ptr_lst = (*ptr_lst)->pre;
		else
		{
			temp = n_map;
			n_map = new_map(temp->size + 1);
			free (temp);
		}

	}
	print_map(n_map->map,n_map->size);
	return (0);
}
