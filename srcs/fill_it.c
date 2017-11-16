/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:02:07 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/11 13:02:09 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"
#include "libft.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_list	*tetrimino;
	t_map	*map;

	if (argc != 2)
		ft_putnexit("usage: ./fillit [filename]");
	map = ft_newmap(0);
	tetrimino = ft_read_entry(argv[1], map);
	printf("The minimum size map will be : %i\n", map->map_size);
	while (tetrimino->next)
	{
		ft_printbytetetri((t_etrimino*)(tetrimino->content));
		ft_putendl("");
		ft_check_tetri(((t_etrimino*)(tetrimino->content))->c_tet);
		tetrimino = tetrimino->next;
	}
	return (0);
}
