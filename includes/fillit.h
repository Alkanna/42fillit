/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:44:57 by dshults           #+#    #+#             */
/*   Updated: 2017/12/25 06:06:00 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/includes/libft.h"

typedef struct			s_block
{
	char				*content;
	size_t				content_size;
	struct s_block		*next;
	char				w;
	char				h;
	char				abcd;
	char				xmin;
	char				ymin;
	char				x[4];
	char				y[4];
}						t_block;

typedef struct			s_res
{
	char				map[16][16];
	char				size;
	char				x;
	char				y;
	int					t_nb;
	struct s_block		**tab;
}						t_res;

int						ft_check_input(char *s);
t_res					*ft_get(char *buf, size_t count, size_t size);
void					ft_get_tris(t_block *t);

int						ft_solve(t_res *map, int tetri);

int						ft_is_putable(t_res *map, t_block *t);
void					ft_put_tetris(t_res *res, t_block *t);

void					ft_color_map(t_res *res);
void					ft_color_map_2(t_res *res, int x, int y);
void					ft_color_map_3(t_res *res, int x, int y);

# define BUF_SIZE 4096

#endif
