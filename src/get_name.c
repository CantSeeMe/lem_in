/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:58:51 by jye               #+#    #+#             */
/*   Updated: 2017/03/19 11:10:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <libft.h>

char	*get_name(const char *line, char *pattern)
{
	char			*name;
	char			*new;
	char			*ptr;
	unsigned int	len;

	if (*pattern)
		++line;
	if ((ptr = ft_strchr(line, *(pattern + 1))) == NULL)
		f_perror(123);
	len = ptr - line;
	if ((name = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		f_perror(1);
	new = name;
	while (line != ptr)
		*name++ = *line++;
	*name = 0;
	return (new);
}
