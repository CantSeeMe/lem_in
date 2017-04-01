/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:26:18 by jye               #+#    #+#             */
/*   Updated: 2017/03/12 18:50:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include <libft.h>

static int	check_link(char *line)
{
	char *cp;

	if (*line == '-')
		return (1);
	if (*line == '#')
		return (0);
	if (*line == '(')
	{
		if ((cp = ft_strchr(line, ')')) == NULL)
			return (1);
		if (*++cp != '-')
			return (1);
	}
	else
	{
		if ((cp = ft_strchr(line, '-')) == NULL)
			return (1);
	}
	if (*++cp == 0)
		return (1);
	return (0);
}

static int	check_coordinate(char *cp)
{
	if (*(cp + 1) == ' ')
		return (1);
	while (*++cp != ' ')
	{
		if (!*cp)
			return (1);
		if (ft_strchr("0123456789", *cp) == NULL)
			return (1);
	}
	if (*(cp + 1) == 0)
		return (1);
	while (*++cp)
	{
		if (ft_strchr("0123456789", *cp) == NULL)
			return (1);
	}
	return (0);
}

static int	check_room(char *line)
{
	char *cp;

	if (*line == 'L' || *line == ' ')
		return (1);
	if (*line == '#')
		return (0);
	if (*line == '(')
	{
		if ((cp = ft_strchr(line, ')')) == NULL)
			return (1);
		if (*(line + 1) == 'L' || *(line + 1) == '#' || line + 1 == cp)
			return (1);
		if (*++cp != ' ')
			return (1);
	}
	else
	{
		if ((cp = ft_strchr(line, ' ')) == NULL)
			return (1);
	}
	return (check_coordinate(cp));
}

static int	check_ants(char *line)
{
	if (*line == '#')
		return (0);
	while (*line)
	{
		if (!(*line >= 0x30 && *line <= 0x39))
			f_perror(10);
		++line;
	}
	return (1);
}

t_lst		*read_args(void)
{
	t_lst	*lst_arg;
	t_lst	*append;
	char	*line;
	char	steps;

	if ((lst_arg = init_lst__(NULL)) == NULL)
		f_perror(1);
	append = lst_arg;
	steps = 0;
	while (get_line(0, &line))
	{
		if (steps == 1 && check_room(line) && sub_rargs(&append))
			++steps;
		if (steps == 2 && check_link(line))
		{
			free(line);
			break ;
		}
		if (steps == 0 && check_ants(line))
			++steps;
		append_lst__(append, line);
		append = append->next;
	}
	pop_lst__(&lst_arg, NULL);
	return (lst_arg);
}
