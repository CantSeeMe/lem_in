/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:02:02 by jye               #+#    #+#             */
/*   Updated: 2017/02/12 21:05:01 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	clr_node(t_node *node)
{
	free(node->name);
	if (node->next)
		free(node->next);
	free(node);
}

void	clr_link(t_link *link)
{
	free(link->name1);
	free(link->name2);
	free(link);
}
