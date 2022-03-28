/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:08:44 by rmattheo          #+#    #+#             */
/*   Updated: 2022/03/26 01:12:59 by pat              ###   ########lyon.fr   */
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
	lstnew->command = content;
	lstnew->next = NULL;
	return (lstnew);
}
