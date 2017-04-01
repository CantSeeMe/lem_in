/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:41:44 by jye               #+#    #+#             */
/*   Updated: 2017/03/19 11:13:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <libft.h>

static t_link	*init_link__(char *name1, char *name2)
{
	t_link	*new;

	if ((new = (t_link *)malloc(sizeof(t_link))) == NULL)
		return (NULL);
	new->name1 = name1;
	new->name2 = name2;
	return (new);
}

static void		check_name(t_lst *lst_room, char *name)
{
	char	bool__;
	t_node	*node;

	bool__ = 0;
	while (lst_room)
	{
		node = (t_node *)lst_room->data;
		if (!ft_strcmp(node->name, name))
		{
			bool__ = 1;
			break ;
		}
		lst_room = lst_room->next;
	}
	if (!bool__)
		f_perror(855632);
}

static void		push_lst(t_lst **lst_link, t_link *link, t_lst *lst_room)
{
	if (link == NULL)
		f_perror(1);
	check_name(lst_room, link->name1);
	check_name(lst_room, link->name2);
	push_lst__(lst_link, link);
}

static t_link	*get_link(const char *line)
{
	const char	*ptr;
	char		*name1;
	char		*name2;

	name1 = *line == '(' ? get_name(line, "()") : get_name(line, "\0-");
	ptr = *line == '(' ? ft_strchr(line, ')') + 2 : ft_strchr(line, '-') + 1;
	name2 = *ptr == '(' ? get_name(ptr, "()") : get_name(ptr, "\0\0");
	return (init_link__(name1, name2));
}

t_lst			*init_link(t_lst *lst_data, t_lst *lst_room)
{
	t_lst	*lst_link;
	char	*line;

	lst_link = NULL;
	while (lst_data && lst_data->data)
		lst_data = lst_data->next;
	if (!lst_data)
		f_perror(55555);
	pop_lst__(&lst_data, NULL);
	while (lst_data)
	{
		line = (char *)lst_data->data;
		if (*line == '#')
		{
			if (!ft_strcmp(line, "##end") || !ft_strcmp(line, "##start"))
				f_perror(85555);
			lst_data = lst_data->next;
			continue ;
		}
		push_lst(&lst_link, get_link(line), lst_room);
		lst_data = lst_data->next;
	}
	return (lst_link);
}
