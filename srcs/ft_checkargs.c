/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 00:36:36 by klouer            #+#    #+#             */
/*   Updated: 2017/12/28 06:44:14 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_checkargs(int argc, char *argv, char *arg)
{
	if (argc >= 3)
		return (!ft_strncmp(&argv[1], arg, 2));
	else
		return (0);
}
