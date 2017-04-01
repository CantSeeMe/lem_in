/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:09:08 by jye               #+#    #+#             */
/*   Updated: 2017/03/29 15:53:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <libft.h>
#include <ft_printf.h>

t_node	*fg_start(t_lst *lst_node)
{
	t_node *node;

	while (lst_node)
	{
		node = (t_node *)lst_node->data;
		if (node->io == 5)
			return (node);
		lst_node = lst_node->next;
	}
	return (NULL);
}

int		get_ants(t_lst *lst_data)
{
	char	*line;

	while (lst_data)
	{
		line = lst_data->data;
		if (*line == '#')
		{
			if (!ft_strcmp(line + 1, "#start") || !ft_strcmp(line + 1, "#end"))
				f_perror(654654564);
		}
		else
			break ;
		lst_data = lst_data->next;
	}
	if (lst_data == NULL)
		f_perror(564654564);
	append_lst__(lst_data, NULL);
	return (f_atoi(line));
}

int		main(void)
{
	unsigned int	nb_ants;
	t_lst			*lst_data;
	t_lst			*link;
	t_lst			*node;
	t_lst			*route;

	if (!(lst_data = read_args()))
		f_perror(98560);
	if ((nb_ants = get_ants(lst_data)) == 0)
		f_perror(564654);
	node = init_node(lst_data);
	link = init_link(lst_data, node);
	link_it(node, link);
	if ((route = solve_it(fg_start(node))) == NULL)
		f_perror(54321);
	print_data(lst_data);
	if (((t_node *)route->next->data)->io == 10)
		move_all(nb_ants, route);
	else
		move_ants(nb_ants, route);
	while (route)
		pop_lst__(&route, NULL);
	while (node)
		pop_lst__(&node, &clr_node);
}
