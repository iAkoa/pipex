/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:38:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/01/13 18:26:50 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot;
	void	*dst;

	tot = size * count;
	dst = malloc(tot);
	if (!(dst))
		return (NULL);
	ft_bzero(dst, tot);
	return (dst);
}
