/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:58:25 by jye               #+#    #+#             */
/*   Updated: 2017/02/16 19:45:26 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned int	f_atoi(char *str)
{
	unsigned long	nb;

	nb = 0;
	if (!*str)
		f_perror(56123);
	while (*str >= 0x30 && *str <= 0x39)
	{
		if ((nb = nb * 10 + (*str - 0x30)) > 0xffffffff)
			f_perror(2);
		++str;
	}
	return ((unsigned int)nb);
}
