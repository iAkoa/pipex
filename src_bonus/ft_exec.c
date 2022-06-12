/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:40:21 by pat               #+#    #+#             */
/*   Updated: 2022/06/12 20:30:01 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exec_bis(t_data *d)
{
	if ((d->lst->prev->command->fd_infile
			|| d->lst->prev->command->here_doc)
		&& d->lst->next->command->fd_outfile)
	{
		if (d->lst->prev->command->fd_infile)
			ft_pipe_infile_cmd_outfile(d);
		else
			ft_pipe_heredock_cmd_outfile(d);
	}
	else if (d->lst->prev->command->fd_infile
		|| d->lst->prev->command->here_doc)
	{
		if (d->lst->prev->command->fd_infile)
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

void	ft_exec(t_data *d)
{
	int	i;
	int	*pid;

	pid = gc_calloc(sizeof(int), d->main.argc - 3, &d->track);
	i = -1;
	while (++i < d->main.argc - 3)
	{
		d->lst = d->lst->next;
		pid[i] = fork();
		if (pid[i] == 0)
		{
			ft_exec_bis(d);
		}
		close(d->lst->prev->command->pfdin);
	}
	i = -1;
	while (++i < d->main.argc - 3)
		waitpid(pid[i], NULL, 0);
}
