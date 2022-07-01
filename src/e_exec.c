/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:25:52 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 18:42:34 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	e_outfile(t_pars *p, t_commands *c, int i)
{
	p->fd_out = open(c[i].outfile, O_WRONLY | O_CREAT | O_TRUNC, 0660);
	if (p->fd_out == -1)
	{
		perror(c[i].outfile);
		return (0);
	}
	dup2(p->fd_out, STDOUT_FILENO);
	close(p->fd_out);
	return (p->fd_out);
}

int	e_infile(t_pars *p, t_commands *c, int i)
{
	p->fd_in = open(c[i].infile, O_DIRECTORY);
	if (p->fd_in != 0 && p->fd_in != -1)
	{
		write(2, c[i].infile, ft_strlen(c[i].infile));
		write(2, " : is a directory\n", 19);
	}
	p->fd_in = open(c[i].infile, O_RDONLY);
	if (p->fd_in == -1)
	{
		perror(c[i].infile);
		return (0);
	}
	return (p->fd_in);
}

void	e_heredoc(t_commands c)
{
	int	pipe_heredoc[2];

	pipe(pipe_heredoc);
	if (write(pipe_heredoc[1], c.here_doc, ft_strlen(c.here_doc)) == -1)
		exit(1);
	if (close(pipe_heredoc[1]) == -1)
		exit(1);
	if (dup2(pipe_heredoc[0], STDIN_FILENO) == -1)
		exit(1);
	if (close(pipe_heredoc[0]) == -1)
		exit(1);
}

int	e_child(t_pars *p, t_commands *c, int i)
{
	close(p->pfd[0]);
	if (c[i].here_doc)
		e_heredoc(c[i]);
	if (c[i].infile)
	{
		p->fd_in = e_infile(p, c, i);
		if (!p->fd_in)
			return (0);
	}
	if (!c[i].here_doc)
		dup2(p->fd_in, STDIN_FILENO);
	if (p->fd_in)
		close(p->fd_in);
	if (c[i].outfile)
	{
		p->fd_out = e_outfile(p, c, i);
		if (!p->fd_in)
			return (0);
	}
	else
		dup2(p->pfd[1], STDOUT_FILENO);
	close(p->pfd[1]);
	e_execve(p, c, i);
	exit(1);
}

void	e_exec(t_pars *p, t_commands *c)
{
	int	i;

	p->fd_in = 0;
	i = -1;
	while (c[++i].stop == 0)
	{
		pipe(p->pfd);
		c[i].pid = fork();
		if (!c[i].pid)
		{
			if (!e_child(p, c, i))
				return ;
		}
		else
		{
			close(p->pfd[1]);
			if (p->fd_in)
				close(p->fd_in);
			p->fd_in = dup(p->pfd[0]);
			close(p->pfd[0]);
		}
	}
	i = -1;
	while (c[++i].stop == 0)
		waitpid(c[i].pid, NULL, 0);
}
