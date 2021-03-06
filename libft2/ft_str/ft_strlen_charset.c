/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:13:04 by rmattheo          #+#    #+#             */
/*   Updated: 2022/06/30 17:48:12 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/gc.h"

int	ft_strcmp1(const char *charset, char c)
{	
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen_charset(const char *str, char *charset)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i]
		|| ft_strcmp1(charset, str[i]))
		i++;
	return (i);
}
