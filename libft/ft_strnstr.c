/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:14:45 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/09 20:27:07 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *c, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*c)
		return ((char *)s);
	while (s[i] && i < len)
	{
		j = 0;
		while ((s[j + i] == c[j]) && s[i + j] && (j + i < len))
			if (!c[++j])
				return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
