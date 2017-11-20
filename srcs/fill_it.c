/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:15:46 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 16:15:47 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fill_it.h"

int main(int argc, char const *argv[]) {
	t_etrimino	*tetriminos;

	if (argc != 2)
		ft_putnexit("usage : ./fillit map");
	tetriminos = ft_read_entry(argv[1]);
	while (tetriminos->next)
	{
		ft_print_tetri(tetriminos);
		tetriminos = tetriminos->next;
	}
	return 0;
} 
