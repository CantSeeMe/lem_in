/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:44:51 by jye               #+#    #+#             */
/*   Updated: 2017/03/20 16:59:02 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <ft_printf.h>
#include <stdlib.h>

static t_ant	*init_ant__(unsigned int id_ant)
{
	t_ant	*ant;

	if ((ant = (t_ant *)malloc(sizeof(t_ant))) == NULL)
		return (NULL);
	ant->id_ant = id_ant;
	ant->route = NULL;
	return (ant);
}

static t_lst	*init_ants(unsigned int nb_ants, t_lst *route)
{
	t_lst			*lst_ants;
	t_ant			*ant;

	lst_ants = NULL;
	while (nb_ants > 0)
	{
		if ((ant = init_ant__(nb_ants)) == NULL)
			f_perror(89999);
		ant->route = route;
		push_lst__(&lst_ants, ant);
		--nb_ants;
	}
	return (lst_ants);
}

static void		move__(t_lst *cp)
{
	t_ant	*ant;

	while (cp)
	{
		ant = (t_ant *)cp->data;
		if (!(((t_node *)ant->route->next->data)->flag & OCCUPIED))
		{
			((t_node *)ant->route->data)->flag ^= OCCUPIED;
			ant->route = ant->route->next;
			if (((t_node *)ant->route->data)->io != 10)
				((t_node *)ant->route->data)->flag ^= OCCUPIED;
			ft_printf("L%d-%s", ant->id_ant,
						((t_node *)ant->route->data)->name);
			if ((cp = cp->next))
				ft_putchar(' ');
		}
		else
			return ;
	}
}

void			move_all(unsigned int nb_ants, t_lst *route)
{
	unsigned int	n;
	t_node			*node;

	n = 1;
	node = (t_node *)route->next->data;
	while (n <= nb_ants)
	{
		ft_printf("L%d-%s", n++, node->name);
		if (n <= nb_ants)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return ;
}

void			move_ants(unsigned int nb_ants, t_lst *route)
{
	t_lst	*lst_ants;

	lst_ants = init_ants(nb_ants, route);
	while (lst_ants)
	{
		if (((t_node *)((t_ant *)lst_ants->data)->route->data)->io == 10)
			pop_lst__(&lst_ants, &free);
		move__(lst_ants);
		if (lst_ants)
			ft_putchar('\n');
	}
}
