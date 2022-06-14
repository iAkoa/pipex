/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_tracknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:08:44 by rmattheo          #+#    #+#             */
/*   Updated: 2022/06/12 23:02:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gc.h"
#include "../include/libft.h"

t_track	*gc_tracknew(void **address)
{
	t_track	*lstnew;

	lstnew = malloc(sizeof(t_track));
	if (!lstnew)
		return (0);
	lstnew->address = *address;
	lstnew->next = NULL;
	lstnew->prev = NULL;
	return (lstnew);
}
