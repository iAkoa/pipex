/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:09:37 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/10 19:27:31 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size < i || !size)
		return (size + ft_strlen(src));
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
