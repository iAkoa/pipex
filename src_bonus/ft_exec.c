/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:40:21 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 02:44:57 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exec(t_data *d)
{
	int	i;
	int pid;

	i = -1;
	while (++i < d->main.argc - 2)
	{
		if((pid = fork()) == -1)
			gc_free_all(&d->track);
		dprintf(2, "pid == %i\n", pid);
		if (pid == 0)
		{
			if (d->lst->command->fd_infile)
			{
				d->lst = d->lst->next;
				ft_pipe_infile_cmd(d);
			}
			else if (d->lst->next->command->fd_outfile)
			{
				d->lst = d->lst->next;
				ft_pipe_cmd_outfile(d);
				break;
			}
			else
				ft_pipe_cmd_cmd(d);
		}
	}
}