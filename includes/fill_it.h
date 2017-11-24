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

#ifndef	FILL_IT_H
#define	FILL_IT_H

#define	BUFF_SIZE 21

typedef	struct	se_list
{
	char	**str;
	char	letter;
	int		x;
	int		y;
	struct	se_list	*next;
	struct	se_list *pre;
}				tetri_list;

typedef	struct	s_map
{
	char	**map;
	int		size;
	struct	s_map	*add_map;
}				tetri_map;

void		ft_exit(char const *s);
tetri_list	*ft_readfile(char const *file_name);
void		print_tetri(unsigned short t);
tetri_list	*add_tetri(char **s, int nb, tetri_list *old_list);
void		remove_onete(char **map, int mpsize, tetri_list *list);
int			find_fit(char **map, int mpsize, tetri_list *list);
int			empty_col(char **s);
void  		mv_left_top(char **s);
int			check_fill(char **map, int mpsize, tetri_list *list, int x, int y);
void		only_dot_hash(char *s, int len);
void		valid_tetri(char *s);
tetri_list	*ft_readfile(char const *file_name);
void		ft_exit(char const *s);
int			mini_sq(tetri_list *list);
tetri_map	*new_map(int size);
void		print_map(char **map, int size);
void		fill_map(char **map, tetri_list *list);
int			solve_map(tetri_map *map, tetri_list **list);

#endif
