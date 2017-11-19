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

typedef	struct			s_etrimino
{
	char				**tetrimino;
	char				letter;
	struct	s_etrimino	*next;
}						t_etrimino;

typedef struct			s_map
{
	char				**map;
	int					last_x;
	int					last_y;
}						t_map;

t_etrimino	*ft_read_entry(const char *filename);
t_etrimino	*ft_newtetri(char **tab, char letter);
void		ft_print_tetri(t_etrimino *tet);
void		ft_set_tetri(char **tab);

#endif
