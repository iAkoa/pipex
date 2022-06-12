/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:50:17 by pat               #+#    #+#             */
/*   Updated: 2022/06/12 20:30:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_pipe_heredock_cmd_outfile(t_data *d)
{
	char	*here_doc;
	int		last_pfdin;
	int		last_pfdout;
	char	*path;
	int		ft_outfile;

	path = d->lst->command->cmd_path;
	here_doc = d->lst->prev->command->here_doc;
	last_pfdin = d->lst->prev->command->pfdin;
	last_pfdout = d->lst->prev->command->pfdout;
	ft_outfile = d->lst->next->command->fd_outfile;
	write (last_pfdin, here_doc, ft_strlen(here_doc));
	close (last_pfdin);
	dup2(last_pfdout, STDIN_FILENO);
	dup2(ft_outfile, STDOUT_FILENO);
	ft_close_all_pipe(d);
	execve (path, d->lst->command->cmd, d->main.envp);
}
