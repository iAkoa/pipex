/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:52:11 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/18 14:18:56 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	if (!n)
		return (0);
	while ((*((unsigned char *)p1++) == (*(unsigned char *)p2++)) && --n > 0)
		;
	return (*((unsigned char *)--p1) - (*(unsigned char *)--p2));
}
