/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:40:21 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 19:13:16 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	ft_exec(t_data *d)
{
	int	i;
	int pid[d->main.argc - 3];

	i = -1;
	while (++i < d->main.argc - 3)
	{
		d->lst = d->lst->next;
		if((pid[i] = fork()) == -1)
			gc_free_all(&d->track);
		if (pid[i] == 0)
		{
			if ((d->lst->prev->command->fd_infile || d->lst->prev->command->here_doc) && d->lst->next->command->fd_outfile)
			{
				if (d->lst->prev->command->fd_infile)
					ft_pipe_infile_cmd_outfile(d);
				else
					ft_pipe_heredock_cmd_outfile(d);
			}
			else if (d->lst->prev->command->fd_infile || d->lst->prev->command->here_doc)
			{
				if(d->lst->prev->command->fd_infile)
					ft_pipe_infile_cmd(d);
				else
					ft_pipe_heredock_cmd(d);
			}
			else if (d->lst->prev->command->cmd && d->lst->next->command
						&& !d->lst->next->command->fd_outfile)
				ft_pipe_cmd_cmd(d);
			else
				ft_pipe_cmd_outfile(d);
		}
		close(d->lst->prev->command->pfdin);
	}
	i = -1;
	while (++i < d->main.argc - 3)
		waitpid(pid[i], NULL, 0);
}
