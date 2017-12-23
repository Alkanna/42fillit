/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:43:16 by dshults           #+#    #+#             */
/*   Updated: 2017/12/22 14:43:20 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>

static void	ft_show_res(t_res *res)
{
	int		y;
	int		x;

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
		ft_putstr("Usage: ./fillit sample.fillit\n");
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

	if (ac != 2)
		ft_put_error(2);
	fd = open(av[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(ft_check_input(buf)))
		ft_put_error(0);
	res = ft_get(buf, 0, 0);
	if (res == 0)
		ft_put_error(0);
	while (!ft_solve(res, 0))
		res->size++;
	ft_show_res(res);
	free(res);
	close(fd);
	exit(0);
}
