/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:10:40 by jye               #+#    #+#             */
/*   Updated: 2017/02/22 01:34:18 by seto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <ft_printf.h>
#include <stdlib.h>

void	swap(void *a, void *b)
{
	*(unsigned long *)a = *(unsigned long *)a ^ *(unsigned long *)b;
	*(unsigned long *)b = *(unsigned long *)b ^ *(unsigned long *)a;
	*(unsigned long *)a = *(unsigned long *)a ^ *(unsigned long *)b;
}

void	print_data(t_lst *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->data);
		pop_lst__(&lst, &free);
	}
	ft_printf("\n");
}
