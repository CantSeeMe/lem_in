/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:26:43 by jye               #+#    #+#             */
/*   Updated: 2017/02/17 20:17:26 by seto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <libft.h>

static unsigned int	g_nbl(t_lst *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

static t_lst		*g_mlink(char *name, t_lst *lst_link)
{
	t_lst	*mlink;
	t_link	*link;
	char	b__;

	mlink = NULL;
	b__ = 0;
	while (lst_link)
	{
		link = (t_link *)lst_link->data;
		if (!ft_strcmp(name, link->name1) ||
			(!ft_strcmp(name, link->name2) && (b__ = 1)))
		{
			if (b__ && !(b__ = 0))
				swap(&link->name1, &link->name2);
			push_lst__(&mlink, link);
		}
		lst_link = lst_link->next;
	}
	return (mlink);
}

static t_node		*g_mnode(char *name, t_lst *lst_node)
{
	t_node *node;

	while (lst_node)
	{
		node = (t_node *)lst_node->data;
		if (!ft_strcmp(name, node->name))
			return (node);
		lst_node = lst_node->next;
	}
	f_perror(485256);
	return (NULL);
}

static void			f_linking(t_node *node, t_lst *lst_node, t_lst *mlink)
{
	unsigned int n;

	n = g_nbl(mlink);
	node->nb_link = n;
	if ((node->next = malloc(sizeof(t_node *) * n)) == NULL)
		f_perror(65446456);
	while (mlink)
	{
		node->next[--n] = g_mnode(((t_link *)mlink->data)->name2, lst_node);
		pop_lst__(&mlink, NULL);
	}
}

void				link_it(t_lst *lst_node, t_lst *lst_link)
{
	t_lst	*mlink;
	t_lst	*cp_lnode;
	t_node	*node;

	if (!(cp_lnode = lst_node) || !lst_link)
		f_perror(54322);
	while (cp_lnode)
	{
		node = (t_node *)cp_lnode->data;
		if (node->io == 10)
		{
			cp_lnode = cp_lnode->next;
			continue;
		}
		mlink = g_mlink(node->name, lst_link);
		f_linking(node, lst_node, mlink);
		cp_lnode = cp_lnode->next;
	}
	while (lst_link)
		pop_lst__(&lst_link, &clr_link);
}
