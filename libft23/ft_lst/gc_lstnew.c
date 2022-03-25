/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:08:44 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/25 16:01:01 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/gc.h"

t_list	*gc_lstnew(t_track **track, void *content)
{
	t_list	*lstnew;

	lstnew = gc_calloc(sizeof(t_list), 1, track);
	if (!lstnew)
		return (0);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
