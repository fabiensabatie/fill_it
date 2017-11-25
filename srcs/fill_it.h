/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <saxiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:58:43 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/24 17:02:22 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H
# define BUFF_SIZE 20

typedef	struct			s_etrimino
{
	char				**str;
	char				letter;
	int					x;
	int					y;
	struct s_etrimino	*next;
	struct s_etrimino	*pre;
}						t_etrimino;

typedef	struct			s_map
{
	char				**map;
	int					size;
	struct s_map		*add_map;
}						t_map;

void					ft_exit(char const *s);
t_etrimino				*ft_readfile(int fd);
t_map					*new_map(int size);
void					print_tetri(unsigned short t);
t_etrimino				*add_tetri(char **s, int nb, t_etrimino *old_list);
void					remove_onete(char **map, int mpsize, t_etrimino *list);
int						find_fit(t_map *map, t_etrimino *list);
char					**mv_left_top(char **s);
int						check_fill(t_map *map, t_etrimino *list, int x, int y);
void					ft_exit(char const *s);
int						mini_sq(t_etrimino *list);
void					print_map(char **map, int size);
int						solve_map(t_map *map, t_etrimino **list);

#endif
