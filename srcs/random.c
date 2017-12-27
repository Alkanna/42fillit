/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 01:36:38 by klouer            #+#    #+#             */
/*   Updated: 2017/12/27 17:55:29 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdint.h>

unsigned int	ft_random(unsigned int startnumber, unsigned int endnumber)
{
	unsigned int		bit;
	unsigned int		t;
	static unsigned int	lfsr = 0xACE1u;
	int					*p;

	p = NULL;
	t = 0;
	if (startnumber == endnumber)
		return (startnumber);
	p = malloc(sizeof(*p));
	t = t ^ (int)p;
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	lfsr = ((bit << 15) | (lfsr >> 1) | t) % endnumber;
	while (lfsr < startnumber)
	{
		lfsr = lfsr + endnumber - startnumber;
	}
	free(p);
	return (lfsr);
}
