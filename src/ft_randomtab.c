/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:31:32 by klouer            #+#    #+#             */
/*   Updated: 2017/12/28 14:38:12 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		i++;
	}
	rtab[i] = '\0';
	return (rtab);
}
