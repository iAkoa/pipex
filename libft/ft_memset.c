/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:21:16 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/09 20:26:40 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t count)
{
	int	i;

	i = count;
	while (count-- > 0)
		*(unsigned char *)str++ = (unsigned char)value;
	return (str - i);
}
