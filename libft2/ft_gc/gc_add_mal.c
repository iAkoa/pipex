/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add_mal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:52:46 by pat               #+#    #+#             */
/*   Updated: 2022/03/25 16:12:47 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gc.h"
#include "../include/libft.h"

void	gc_add_mal(t_track **track, void **address)
{
	if (!(*track))
		*track = gc_tracknew(address);
	else
		gc_lstadd_front(track, gc_tracknew(address));
}
