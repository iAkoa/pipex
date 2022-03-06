/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:25:58 by rmattheo          #+#    #+#             */
/*   Updated: 2022/01/28 17:23:10 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		if ((char)c == '\0')
			return ((char *)&s[ft_strlen(s)]);
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	return (0);
}
