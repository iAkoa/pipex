/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:38:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/07/01 16:45:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/gc.h"

void	*gc_calloc(size_t count, size_t size, t_track **track)
{
	size_t	tot;
	void	*dst;

	tot = size * count;
	dst = malloc(tot);
	// dprintf(2, "Malloc = %p\n", dst);
	if (!(dst))
		return (NULL);
	ft_bzero(dst, tot);
	gc_add_mal(track, (void **)&dst);
	// dprintf(2, "t_track = %p\n", (*track)->address);
	return (dst);
}
