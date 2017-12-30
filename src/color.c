/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 06:00:39 by klouer            #+#    #+#             */
/*   Updated: 2017/12/30 12:26:43 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_color_map3(t_res *res, int x, int y)
{
	if (!ft_strncmp(&res->map[y][x], "P", 1))
		ft_putstr("\x1b[38;5;109m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "Q", 1))
		ft_putstr("\x1b[38;5;112m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "R", 1))
		ft_putstr("\x1b[38;5;220m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "S", 1))
		ft_putstr("\x1b[38;5;223m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "T", 1))
		ft_putstr("\x1b[38;5;115m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "U", 1))
		ft_putstr("\x1b[38;5;117m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "V", 1))
		ft_putstr("\x1b[38;5;225m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "W", 1))
		ft_putstr("\x1b[38;5;227m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "X", 1))
		ft_putstr("\x1b[38;5;119m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "Y", 1))
		ft_putstr("\x1b[38;5;122m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "Z", 1))
		ft_putstr("\x1b[38;5;230m■ \x1b[0m");
}

void	ft_color_map2(t_res *res, int x, int y)
{
	if (!ft_strncmp(&res->map[y][x], "E", 1))
		ft_putstr("\x1b[38;5;94m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "F", 1))
		ft_putstr("\x1b[38;5;202m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "G", 1))
		ft_putstr("\x1b[38;5;205m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "H", 1))
		ft_putstr("\x1b[38;5;97m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "I", 1))
		ft_putstr("\x1b[38;5;100m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "J", 1))
		ft_putstr("\x1b[38;5;208m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "K", 1))
		ft_putstr("\x1b[38;5;211m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "L", 1))
		ft_putstr("\x1b[38;5;103m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "M", 1))
		ft_putstr("\x1b[38;5;106m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "N", 1))
		ft_putstr("\x1b[38;5;214m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "O", 1))
		ft_putstr("\x1b[38;5;217m■ \x1b[0m");
	ft_color_map3(res, x, y);
}

void	ft_color_map1(t_res *res, int x, int y)
{
	if (!ft_strncmp(&res->map[y][x], "A", 1))
		ft_putstr("\x1b[38;5;22m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], ".", 1))
		ft_putstr("\x1b[38;5;22m. \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "B", 1))
		ft_putstr("\x1b[38;5;196m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "C", 1))
		ft_putstr("\x1b[38;5;199m■ \x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "D", 1))
		ft_putstr("\x1b[38;5;91m■ \x1b[0m");
	ft_color_map2(res, x, y);
}

void	ft_frame_horizontal(t_res *res, int c, char **av)
{
	int		i;

	if (ft_argparse(av) == 3)
		return ;
	if (c)
	{
		i = 0;
		ft_putstr("╔");
		while (i++ < res->size)
			ft_putstr("═");
		ft_putstr("╗\n");
	}
	else if (!c)
	{
		i = 0;
		ft_putstr("╚");
		while (i++ < res->size)
			ft_putstr("═");
		ft_putstr("╝\n");
	}
}

/*
** ft_aleacolor(res, x, y)
** ft_color_map1(res, x, y)
*/

void	ft_color_map(t_res *res, char **av)
{
	int		y;
	int		x;
	unsigned int  *rt;

	rt = ft_readrandomtab(30);
	y = 0;
	ft_frame_horizontal(res, 1, av);
	while (y < res->size)
	{
		x = 0;
		if (ft_argparse(av) != 3)
			ft_putstr("║");
		while (x < res->size)
		{
			ft_argmode(ft_argparse(av), res, x, y, rt);
			x++;
		}
		y++;
		if (ft_argparse(av) != 3)
			ft_putstr("║");
		ft_putchar('\n');
	}
	ft_frame_horizontal(res, 0, av);
//	free(rt);
}
