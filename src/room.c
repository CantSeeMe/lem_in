/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:23:17 by jye               #+#    #+#             */
/*   Updated: 2017/03/12 18:53:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <libft.h>
#include <ft_printf.h>

static t_node	*init_node__(char *name, unsigned short io)
{
	t_node	*new;

	if ((new = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	ft_memset(new, 0, sizeof(t_node));
	new->name = name;
	new->io = io;
	return (new);
}

static int		eval_sharp(char *line, int io)
{
	if (ft_strcmp(line, "#start") == 0)
	{
		if (io == 5 || io == 10)
			f_perror(7);
		return (5);
	}
	if (ft_strcmp(line, "#end") == 0)
	{
		if (io == 5 || io == 10)
			f_perror(7);
		return (10);
	}
	if (io == 5)
		return (5);
	else if (io == 10)
		return (10);
	else
		return (0);
}

static void		push_lst(t_lst **lst_node, t_node *node)
{
	t_lst	*cp;
	t_node	*cp_node;

	if (node == NULL)
		f_perror(1);
	cp = *lst_node;
	while (cp)
	{
		cp_node = (t_node *)cp->data;
		if (ft_strcmp(cp_node->name, node->name) == 0)
			f_perror(5);
		if (node->io != 0 && cp_node->io == node->io)
			f_perror(6);
		cp = cp->next;
	}
	push_lst__(lst_node, node);
}

static t_node	*get_node(const char *line, int io)
{
	char	*name;

	if ((name = *line == '(' ? get_name(line, "()") : get_name(line, "\0 "))
		== NULL)
		f_perror(1);
	return (init_node__(name, io));
}

t_lst			*init_node(t_lst *lst_data)
{
	t_lst			*lst_node;
	char			*line;
	unsigned short	io;

	lst_node = NULL;
	io = 0;
	while (lst_data && lst_data->data)
		lst_data = lst_data->next;
	if (!lst_data)
		f_perror(56461);
	pop_lst__(&lst_data, NULL);
	while (lst_data && (line = (char *)lst_data->data))
	{
		if (*line == '#')
			io = eval_sharp(line + 1, io);
		else
		{
			push_lst(&lst_node, get_node(line, io));
			io = 0;
		}
		lst_data = lst_data->next;
	}
	if (io != 0)
		f_perror(4);
	return (lst_node);
}
