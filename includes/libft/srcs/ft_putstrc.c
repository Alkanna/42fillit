/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 06:46:34 by klouer            #+#    #+#             */
/*   Updated: 2017/12/25 11:12:47 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include "../includes/color.h"

void ft_putstrc(char *str, char *color, size_t len)
{
	ft_putstr(color);
	write(1, str, len);
	ft_putstr(RESET);
}
