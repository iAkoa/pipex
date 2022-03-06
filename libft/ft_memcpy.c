/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:17:06 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/17 11:06:17 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = n;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (dest - i);
}
