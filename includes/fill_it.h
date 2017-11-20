/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:28:14 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 23:42:37 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H
# include "libft.h"
# define BUFF_SIZE 21

typedef	struct			s_etrimino
{
	char				**tetrimino;
	char				letter;
	struct	s_etrimino	*next;
}						t_etrimino;

typedef struct			s_map
{
	char				**map;
	int					map_size;
	int					last_x;
	int					last_y;
}						t_map;

t_etrimino	*ft_read_entry(const char *filename);
t_etrimino	*ft_newtetri(char **tab, char letter);
t_map		*ft_newmap(t_map *prev_map, int mapsize);
void		ft_print_tetri(t_etrimino *tet);
void		ft_set_tetri(char **tab);
int			ft_minmapsize(t_etrimino *tet);

#endif
