/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gencolorcode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:48:44 by klouer            #+#    #+#             */
/*   Updated: 2017/12/28 14:37:53 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_gencolorcode(int colorcode, char *string)
{
	char	*c;
	char	*ret;

	c = ft_itoa(colorcode);
	ret = ft_strndup("\x1b[38;5;", (ft_strlen(
										c) + ft_strlen(
											"\x1b[38;5;") + ft_strlen(
											"\x1b[0m") + ft_strlen("m")
									+ 1));
	ft_strcat(ret, c);
	free(c);
	ft_strcat(ret, "m");
	ft_strncat(ret, string, 1);
	ft_strcat(ret, "\x1b[0m");
	return (ret);
}
