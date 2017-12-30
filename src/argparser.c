/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:26:16 by klouer            #+#    #+#             */
/*   Updated: 2017/12/30 13:46:20 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** -c : pre-colored mode --now packed
** -cr : packed random color mode
** -cm : macro colored mode
** -cfr : full random color mode
*/

int		ft_argparse(char **av)
{
	if (!ft_strncmp(av[1], "-cr\0", 4))
		return (2);
	else if (!ft_strncmp(av[1], "-cm\0", 4))
		return (3);
	else if (!ft_strncmp(av[1], "-cfr\0", 5))
		return (4);
	else if (!ft_strncmp(av[1], "-c\0", 3))
		return (1);
	else if (!ft_strncmp(av[1], "-", 1))
	{
		ft_putstr("Available args :\n");
		ft_putstr("-c : Sorted Random Color Mode\n");
		ft_putstr("-cm : Pretty Macro Color Mode\n");
		ft_putstr("-cfr : Full Random Color Mode\n");
	}
	return (0);
}

void	ft_argmode(int mode, t_res *res, int x, int y, unsigned int *rt)
{
	if (mode == 3)
		ft_color_map1(res, x, y);
	else if (mode == 2)
		ft_aleasortedcolor(res, x, y, rt);
	else if (mode == 4)
		ft_aleacolor(res, x, y);
	else if (mode == 1)
		ft_aleasortedcolor(res, x, y, rt);
}
