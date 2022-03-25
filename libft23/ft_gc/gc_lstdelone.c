/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:55:57 by pat               #+#    #+#             */
/*   Updated: 2022/03/24 15:43:42 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gc.h"
#include "../include/libft.h"

void	gc_lstdelone(t_track *lst, void (*del)(void*))
{
	if (lst)
	{
		if (lst->address)
		{
			del(lst->address);
			lst->address = NULL;
			lst->next = NULL;
			lst->prev = NULL;
			free(lst);
		}
	}
}
