/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:38:45 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 17:09:37 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gc.h"
#include "../include/libft.h"

void	gc_lstclear(t_track **lst, void (*del)(void*))
{
	t_track	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		printf("%p\n", (*lst)->address);
		temp = (*lst)->next;
		gc_lstdelone(*lst, del);
		*lst = temp;
	}
}

void	gc_free_all(t_track **track)
{
	gc_lstclear(track, free);
}
