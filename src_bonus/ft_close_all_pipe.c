/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_all_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:52:45 by pat               #+#    #+#             */
/*   Updated: 2022/06/12 20:29:58 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close_all_pipe(t_data *d)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = d->lst;
	while (d->lst)
	{
		if (d->lst->command[i].pfdin)
			close(d->lst->command[i].pfdin);
		if (d->lst->command[i].pfdout)
			close(d->lst->command[i].pfdout);
		d->lst = d->lst->next;
	}
	d->lst = tmp;
}
