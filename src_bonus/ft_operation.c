/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:37:10 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 02:00:50 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_pipe_infile_cmd(t_data *d)
{
	int		fd_infile;
	int		pfdin;
	int		pfdout;
	char	**cmd;
	char	**envp;
	char	*path;

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	fd_infile = d->lst->prev->command->fd_infile;
	cmd = d->lst->command->cmd;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	if (close (pfdout) == -1)
		gc_free_all(&d->track);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(pfdin, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	close(fd_infile);
	if (execve (path, cmd, envp) == -1)
		gc_free_all(&d->track);
}

void	ft_pipe_cmd_cmd(t_data *d)
{
	int		pfdin;
	int		pfdout;
	int		last_pfdout;
	char	**cmd;
	char	**envp;
	char	*path;

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	cmd = d->lst->command->cmd;
	last_pfdout = d->lst->prev->command->pfdout;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	if (close (pfdout) == -1)
		gc_free_all(&d->track);
	if (dup2(last_pfdout, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(pfdin, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	if (execve (path, cmd, envp) == -1)
		gc_free_all(&d->track);
}

void	ft_pipe_cmd_outfile(t_data *d)
{
	int		fd_outfile;
	int		pfdin;
	int		pfdout;
	char	**cmd;
	char	**envp;
	char	*path;

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	fd_outfile = d->lst->next->command->fd_outfile;
	cmd = d->lst->command->cmd;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	if (close (pfdout) == -1)
		gc_free_all(&d->track);
	if (dup2(fd_outfile, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(pfdin, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	close(fd_outfile);
	if (execve (path, cmd, envp) == -1)
		gc_free_all(&d->track);
}

void	ft_pipe_heredock_cmd(t_data *d)
{
	// int		here_doc;
	// int		pfdin;
	// int		pfdout;
	// char	**cmd;
	// char	**envp;
	// char	*path;
	(void)d;
	// path = d->lst->command->cmd_path;
	// envp = d->main.envp;
	// here_doc = d->lst->command->here_doc;
	// cmd = d->lst->command->cmd;
	// pfdin = d->lst->command->pfdin;
	// pfdout = d->lst->command->pfdout;
	// if (close (pfdout) == -1)
	// 	ft_free_all(d);
	// if (dup2(fd_outfile, STDIN_FILENO) == -1)
	// 	ft_free_all(d);
	// if (dup2(pfdin, STDOUT_FILENO) == -1)
	// 	ft_free_all(d);
	// if (close (pfdin) == -1)
	// 	ft_free_all(d);
	// close(fd_outfile);
	// if (execve (path, cmd, envp) == -1)
	// 	ft_free_all(d);
}