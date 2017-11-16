/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:28:14 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/10 16:28:16 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H
# include "libft.h"
# define BUFF_SIZE 21

typedef struct	s_etrimino
{
	short int	c_tet;
	char		letter;
}				t_etrimino;

typedef struct	s_map
{
	int			map_size;
	char		*map;
}				t_map;

t_map			*ft_newmap(int size);
t_etrimino		*ft_newtetri(char *tet);
t_list			*ft_read_entry(const char *filename, t_map* map);
void			ft_printbytetetri(t_etrimino *tet);
void			ft_check_tetri(short int tet);
int				ft_minmapsize(int numberoftetris);

#endif
