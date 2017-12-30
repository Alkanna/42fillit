/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:31:32 by klouer            #+#    #+#             */
/*   Updated: 2017/12/30 06:56:50 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int	*ft_randomtab(size_t size, int min, int max)
{
	int		*rtab;
	size_t	i;

	if ((rtab = (int *)malloc(size * sizeof(int)) + 1) == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		rtab[i] = ft_random(min, max);
		if (rtab[i] > 240)
			rtab[i] = rtab[i] % 70;
		i++;
	}
	rtab[i] = '\0';
	return (rtab);
}

char  *ft_readrandomtab(size_t size)
{
	int fd;
	int ret;
	char *buf;
	size_t i;
	unsigned char tab[100];

	if ((fd = open("/dev/random", O_RDONLY)) < 0)
		return (NULL);
	buf = NULL;
	ret = read(fd, tab, size);
	i = 0;
	if ((buf = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
//		printf("%d\n", tab[i]);
		ft_putnbr(tab[i]);
		ft_putstr("\n");
		i++;
	}
	return (buf);
}
