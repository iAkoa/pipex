/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:37:10 by pat               #+#    #+#             */
/*   Updated: 2022/06/12 20:30:14 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_pipe_infile_cmd(t_data *d)
{
	int		fd_infile;
	int		pfdin;
	int		pfdout;
	char	**cmd;
	char	*path;

	path = d->lst->command->cmd_path;
	fd_infile = d->lst->prev->command->fd_infile;
	cmd = d->lst->command->cmd;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	close(pfdout);
	dup2(fd_infile, STDIN_FILENO);
	dup2(pfdin, STDOUT_FILENO);
	ft_close_all_pipe(d);
	close(fd_infile);
	execve (path, cmd, d->main.envp);
}

void	ft_pipe_cmd_cmd(t_data *d)
{
	int		pfdin;
	int		pfdout;
	int		last_pfdout;
	int		last_pfdin;
	char	*path;

	path = d->lst->command->cmd_path;
	last_pfdout = d->lst->prev->command->pfdout;
	last_pfdin = d->lst->prev->command->pfdin;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	close (pfdout);
	close(last_pfdin);
	dup2(last_pfdout, STDIN_FILENO);
	dup2(pfdin, STDOUT_FILENO);
	ft_close_all_pipe(d);
	execve (path, d->lst->command->cmd, d->main.envp);
}

void	ft_pipe_cmd_outfile(t_data *d)
{
	int		pfdin_last;
	int		last_pfdout;
	char	*path;

	path = d->lst->command->cmd_path;
	last_pfdout = d->lst->prev->command->pfdout;
	pfdin_last = d->lst->prev->command->pfdin;
	close (pfdin_last);
	dup2(d->lst->next->command->fd_outfile, STDOUT_FILENO);
	dup2(last_pfdout, STDIN_FILENO);
	close(d->lst->next->command->fd_outfile);
	ft_close_all_pipe(d);
	execve (path, d->lst->command->cmd, d->main.envp);
}

void	ft_pipe_infile_cmd_outfile(t_data *d)
{
	int		fd_infile;
	int		fd_outfile;
	int		pfdin;
	int		pfdout;
	char	*path;

	(void)pfdin;
	(void)pfdout;
	path = d->lst->command->cmd_path;
	fd_infile = d->lst->prev->command->fd_infile;
	fd_outfile = d->lst->next->command->fd_outfile;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	dup2(fd_infile, STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	ft_close_all_pipe(d);
	close(fd_infile);
	close(fd_outfile);
	execve (path, d->lst->command->cmd, d->main.envp);
}

void	ft_pipe_heredock_cmd(t_data *d)
{
	char	*here_doc;
	int		pfdout;
	int		last_pfdin;
	int		last_pfdout;
	char	*path;

	path = d->lst->command->cmd_path;
	here_doc = d->lst->prev->command->here_doc;
	pfdout = d->lst->command->pfdout;
	last_pfdin = d->lst->prev->command->pfdin;
	last_pfdout = d->lst->prev->command->pfdout;
	close (pfdout);
	write (last_pfdin, here_doc, ft_strlen(here_doc));
	close (last_pfdin);
	dup2(last_pfdout, STDIN_FILENO);
	dup2(d->lst->command->pfdin, STDOUT_FILENO);
	ft_close_all_pipe(d);
	close (last_pfdout);
	execve (path, d->lst->command->cmd, d->main.envp);
}
