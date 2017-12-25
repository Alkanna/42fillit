/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 06:00:39 by klouer            #+#    #+#             */
/*   Updated: 2017/12/25 15:02:53 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_color_map3(t_res *res, int x, int y)
{
	if (!ft_strncmp(&res->map[y][x], "P", 1))
		ft_putstr("\x1b[38;5;109mP\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "Q", 1))
		ft_putstr("\x1b[38;5;112mQ\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "R", 1))
		ft_putstr("\x1b[38;5;220mR\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "S", 1))
		ft_putstr("\x1b[38;5;223mS\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "T", 1))
		ft_putstr("\x1b[38;5;115mT\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "U", 1))
		ft_putstr("\x1b[38;5;117mU\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "V", 1))
		ft_putstr("\x1b[38;5;225mV\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "W", 1))
		ft_putstr("\x1b[38;5;227mW\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "X", 1))
		ft_putstr("\x1b[38;5;119mX\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "Y", 1))
		ft_putstr("\x1b[38;5;122mY\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "Z", 1))
		ft_putstr("\x1b[38;5;230mZ\x1b[0m");
}

void	ft_color_map2(t_res *res, int x, int y)
{
	if (!ft_strncmp(&res->map[y][x], "E", 1))
		ft_putstr("\x1b[38;5;94mE\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "F", 1))
		ft_putstr("\x1b[38;5;202mF\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "G", 1))
		ft_putstr("\x1b[38;5;205mG\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "H", 1))
		ft_putstr("\x1b[38;5;97mH\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "I", 1))
		ft_putstr("\x1b[38;5;100mI\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "J", 1))
		ft_putstr("\x1b[38;5;208mJ\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "K", 1))
		ft_putstr("\x1b[38;5;211mK\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "L", 1))
		ft_putstr("\x1b[38;5;103mL\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "M", 1))
		ft_putstr("\x1b[38;5;106mM\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "N", 1))
		ft_putstr("\x1b[38;5;214mN\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "O", 1))
		ft_putstr("\x1b[38;5;217mO\x1b[0m");
	ft_color_map3(res, x, y);
}

void	ft_color_map1(t_res *res, int x, int y)
{
	if (!ft_strncmp(&res->map[y][x], "A", 1))
		ft_putstrc(&res->map[y][x], WHITE, 1);//ft_putstr("\x1b[38;5;52mA\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], ".", 1))
		ft_putstr("\x1b[38;5;22m.\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "B", 1))
		ft_putstr("\x1b[38;5;196mB\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "C", 1))
		ft_putstr("\x1b[38;5;199mC\x1b[0m");
	if (!ft_strncmp(&res->map[y][x], "D", 1))
		ft_putstr("\x1b[38;5;91mD\x1b[0m");
}

void	ft_frame_horizontal(t_res *res, int c)
{
	int		i;

	if (c)
	{
		i = 0;
		ft_putstr("╔");
		while (i < res->size)
		{
			ft_putstr("═");
			i++;
		}
		ft_putstr("╗\n");
	}
	else if (!c)
	{
		i = 0;
		ft_putstr("╚");
		while (i < res->size)
		{
			ft_putstr("═");
			i++;
		}
		ft_putstr("╝\n");
	}
}

void	ft_color_map(t_res *res)
{
	int		y;
	int		x;

	y = 0;
	ft_frame_horizontal(res, 1);
	while (y < res->size)
	{
		x = 0;
		ft_putstr("║");
		while (x < res->size)
		{
			ft_color_map1(res, x, y);
			ft_color_map2(res, x, y);
			x++;
		}
		y++;
		ft_putstr("║");
		ft_putchar('\n');
	}
	ft_frame_horizontal(res, 0);
}
