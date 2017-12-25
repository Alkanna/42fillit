/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:43:16 by dshults           #+#    #+#             */
/*   Updated: 2017/12/25 06:04:31 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>

static void	ft_show_res(t_res *res, int arg)
{
	int		y;
	int		x;

	if (arg == 2)
	{
		ft_color_map(res);
		return ;
	}
	y = 0;
	while (y < res->size)
	{
		x = 0;
		while (x < res->size)
		{
			ft_putchar(res->map[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

static void	ft_put_error(int err)
{
	if (err == 2)
	{
		ft_putstr("Usage: ./fillit (-c) [mapfile]\n");
		exit(0);
	}
	else if (err == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_res	*res;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		arg;

	arg = 1;
	if (ac == 3 && !ft_strncmp(av[1], "-c", 2))
		arg = 2;
	else if (ac != 2)
		ft_put_error(2);
	fd = open(av[arg], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(ft_check_input(buf)))
		ft_put_error(0);
	res = ft_get(buf, 0, 0);
	if (res == 0)
		ft_put_error(0);
	while (!ft_solve(res, 0))
		res->size++;
	ft_show_res(res, arg);
	free(res);
	close(fd);
	exit(0);
}
