/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:37:10 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 19:03:21 by rmattheo         ###   ########lyon.fr   */
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
	if (close(pfdout) == -1)
		gc_free_all(&d->track);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(pfdin, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	close(fd_infile);
	// dprintf(2, "fd infile =  %i\n", fd_infile);
	// dprintf(2, "fd outfile =  %i\n",d->lst->command->pfdout);
	if (execve (path, cmd, envp) == -1)
	{
		gc_free_all(&d->track);
		exit(1);
	}
}

void	ft_pipe_cmd_cmd(t_data *d)
{
	int		pfdin;
	int		pfdout;
	int		last_pfdout;
	int		last_pfdin;
	char	**cmd;
	char	**envp;
	char	*path;

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	cmd = d->lst->command->cmd;
	last_pfdout = d->lst->prev->command->pfdout;
	last_pfdin = d->lst->prev->command->pfdin;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	if (close (pfdout) == -1)
		gc_free_all(&d->track);
	if (close(last_pfdin) == -1)
		gc_free_all(&d->track);
	if (dup2(last_pfdout, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(pfdin, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	// dprintf(2, "fd outfile =  %i\n", pfdin);
	// dprintf(2, "fd intfile =  %i\n", last_pfdout);
	if (execve (path, cmd, envp) == -1)
	{
		gc_free_all(&d->track);
		exit(1);
	}
}

void	ft_pipe_cmd_outfile(t_data *d)
{
	int		fd_outfile;
	int		pfdin;
	int		pfdin_last;
	int		last_pfdout;
	int		pfdout;
	char	**cmd;
	char	**envp;
	char	*path;

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	fd_outfile = d->lst->next->command->fd_outfile;
	cmd = d->lst->command->cmd;
	pfdin = d->lst->command->pfdin;
	last_pfdout = d->lst->prev->command->pfdout;
	pfdin_last = d->lst->prev->command->pfdin;
	pfdout = d->lst->command->pfdout;
	if (close (pfdin_last) == -1)
		gc_free_all(&d->track);
	if (dup2(last_pfdout, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	close(fd_outfile);
	close(last_pfdout);
	if (execve (path, cmd, envp) == -1)
	{
		gc_free_all(&d->track);
		exit(1);
	}
}

void	ft_pipe_infile_cmd_outfile(t_data *d)
{
	int		fd_infile;
	int		fd_outfile;
	int		pfdin;
	int		pfdout;
	char	**cmd;
	char	**envp;
	char	*path;

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	fd_infile = d->lst->prev->command->fd_infile;
	fd_outfile = d->lst->next->command->fd_outfile;
	cmd = d->lst->command->cmd;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	if (close (pfdout) == -1)
		gc_free_all(&d->track);
	close(fd_infile);
	close(fd_outfile);
	if (execve (path, cmd, envp) == -1)
	{
		gc_free_all(&d->track);
		exit(1);
	}
}

void	ft_pipe_heredock_cmd(t_data *d)
{
	char	*here_doc;
	int		pfdin;
	int		pfdout;
	int		last_pfdin;
	int		last_pfdout;
	char	**cmd;
	char	**envp;
	char	*path;
	

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	here_doc = d->lst->prev->command->here_doc;
	cmd = d->lst->command->cmd;
	pfdin = d->lst->command->pfdin;
	pfdout = d->lst->command->pfdout;
	last_pfdin = d->lst->prev->command->pfdin;
	last_pfdout = d->lst->prev->command->pfdout;

	if (close (pfdout) == -1)
		gc_free_all(&d->track);
	dprintf(2, "heredoc == %s\n", here_doc);
	write (last_pfdin, here_doc, ft_strlen(here_doc));
	if (close (last_pfdin) == -1)
		gc_free_all(&d->track);
	if (dup2(last_pfdout, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(pfdin, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (pfdin) == -1)
		gc_free_all(&d->track);
	if (close (last_pfdout) == -1)
		gc_free_all(&d->track);
	if (execve (path, cmd, envp) == -1)
		gc_free_all(&d->track);
}


void	ft_pipe_heredock_cmd_outfile(t_data *d)
{
	char	*here_doc;
	int		last_pfdin;
	int		last_pfdout;
	char	**cmd;
	char	**envp;
	char	*path;
	int		ft_outfile;
	

	path = d->lst->command->cmd_path;
	envp = d->main.envp;
	here_doc = d->lst->prev->command->here_doc;
	cmd = d->lst->command->cmd;
	last_pfdin = d->lst->prev->command->pfdin;
	last_pfdout = d->lst->prev->command->pfdout;
	ft_outfile = d->lst->next->command->fd_outfile;

	dprintf(2, "heredoc == %s\n", here_doc);
	write (last_pfdin, here_doc, ft_strlen(here_doc));
	if (close (last_pfdin) == -1)
		gc_free_all(&d->track);
	if (dup2(last_pfdout, STDIN_FILENO) == -1)
		gc_free_all(&d->track);
	if (dup2(ft_outfile, STDOUT_FILENO) == -1)
		gc_free_all(&d->track);
	if (close (last_pfdout) == -1)
		gc_free_all(&d->track);
	if (execve (path, cmd, envp) == -1)
		gc_free_all(&d->track);
}
