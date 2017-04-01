/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seto <jye@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 01:02:39 by seto              #+#    #+#             */
/*   Updated: 2017/02/16 21:16:19 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <libft.h>
#include <stdlib.h>

static t_pathf	*init_pathf(t_node *node)
{
	t_pathf *new_pathf;

	if ((new_pathf = (t_pathf *)malloc(sizeof(t_pathf))) == NULL)
		return (NULL);
	ft_memset(new_pathf, 0, sizeof(t_pathf));
	new_pathf->node = node;
	return (new_pathf);
}

static t_lst	*list_nchecked(t_node *node)
{
	t_lst			*not_checked;
	unsigned int	n;

	n = node->nb_link;
	not_checked = NULL;
	while (n--)
	{
		if (node->next[n]->flag)
			continue ;
		push_lst__(&not_checked, node->next[n]);
	}
	return (not_checked);
}

static int		explore_node(t_pathf *pathf, t_lst **cp_track, t_lst **log)
{
	t_lst			*not_checked;

	not_checked = list_nchecked(pathf->node);
	while (not_checked)
	{
		append_lst__(*cp_track, init_pathf((t_node *)not_checked->data));
		pop_lst__(&not_checked, NULL);
		*cp_track = (*cp_track)->next;
		push_lst__(log, (*cp_track)->data);
		((t_pathf *)(*cp_track)->data)->prev = pathf;
		if (((t_pathf *)(*cp_track)->data)->node->io == 10)
		{
			while (not_checked)
				pop_lst__(&not_checked, NULL);
			return (1);
		}
		((t_pathf *)(*cp_track)->data)->node->flag |= CHECKED;
	}
	return (0);
}

static t_lst	*trace_route(t_lst *track, t_lst *log)
{
	t_lst	*route;
	t_pathf	*cp;

	route = NULL;
	cp = (t_pathf *)log->data;
	while (cp)
	{
		push_lst__(&route, cp->node);
		cp = cp->prev;
	}
	while (log)
		pop_lst__(&log, &free);
	while (track)
		pop_lst__(&track, NULL);
	return (route);
}

t_lst			*solve_it(t_node *start)
{
	t_pathf	*pathf;
	t_lst	*track;
	t_lst	*cp;
	t_lst	*log;

	if (!start)
		f_perror(85512);
	start->flag |= CHECKED;
	if ((pathf = init_pathf(start)) == NULL)
		f_perror(85513);
	if ((track = init_lst__(pathf)) == NULL)
		f_perror(85514);
	cp = track;
	if ((log = init_lst__(pathf)) == NULL)
		f_perror(85590);
	while (track)
	{
		pathf = (t_pathf *)track->data;
		if (explore_node(pathf, &cp, &log))
			return (trace_route(track, log));
		pop_lst__(&track, NULL);
	}
	return (NULL);
}
