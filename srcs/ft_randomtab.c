/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:31:32 by klouer            #+#    #+#             */
/*   Updated: 2017/12/27 20:17:23 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	*ft_randomtab(size_t size, int min, int max)
{
	int		*rtab;
	size_t	i;

	rtab = (int*)malloc(size * sizeof(int) + 1);
	i = 0;
	while (i < size)
	{
		rtab[i] = ft_random(min, max);
		i++;
	}
	rtab[i] = '\0';
	return (rtab);
}
