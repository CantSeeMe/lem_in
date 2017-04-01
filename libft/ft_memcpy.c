/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:26:05 by jye               #+#    #+#             */
/*   Updated: 2017/03/15 19:20:54 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*ldst;
	unsigned long	*lsrc;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	ldst = NULL;
	while (((unsigned long)cdst & (sizeof(unsigned long) - 1)) && n)
	{
		*cdst++ = *csrc++;
		--n;
	}
	if (n >= 8)
	{
		ldst = (unsigned long *)cdst;
		lsrc = (unsigned long *)csrc;
		while (n >= 8 && (*ldst++ = *lsrc++))
			n -= 8;
	}
	csrc = ldst != NULL ? (unsigned char *)lsrc : csrc;
	cdst = ldst != NULL ? (unsigned char *)ldst : cdst;
	while (n-- > 0)
		*cdst++ = *csrc++;
	return (dst);
}
