/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:25:52 by pat               #+#    #+#             */
/*   Updated: 2022/06/28 17:05:29 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	e_heredoc(t_data *d, t_pars *p,t_commands c)
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

void	e_exec(t_data *d, t_pars *p,t_commands *c)
{
	int	i;
	int pfd[2];
	int fd_in;
	int fd_out;
	fd_in = 0;

	i = -1;
	while (c[++i].stop == 0)
	{
		pipe(pfd);
		c[i].pid = fork();
		if (!c[i].pid)
		{
			close(pfd[0]);
			if (c[i].here_doc)
			{
					e_heredoc(d, p, c[i]);
			}
			if (c[i].infile)
			{
				fd_in = open(c[i].infile, O_RDONLY);
				dprintf(2, "fd_in: %d\n", fd_in);
				dprintf(2, "file: %s\n", c[i].infile);
				if (fd_in == -1)
				{
					perror(c[i].infile);
					exit(1);
				}
			}
			if (!c[i].here_doc)
			{
				dup2(fd_in, STDIN_FILENO);
			}
			if (fd_in)
				close(fd_in);
			if (c[i].outfile)
			{
				if (c[0].here_doc)
					fd_out = open(c[i].outfile, O_WRONLY | O_CREAT | O_APPEND, 0660);
				else
					fd_out = open(c[i].outfile, O_WRONLY | O_CREAT | O_TRUNC, 0660);
				dup2(fd_out, STDOUT_FILENO);
				close(fd_out);
			}
			else
				dup2(pfd[1], STDOUT_FILENO);
			close(pfd[1]);
			execve(c[i].cmd_path, c[i].args_vec, p->envp);
			exit(1);
		}
		else
		{
			close(pfd[1]);
			if (fd_in)
				close(fd_in);
			fd_in = dup(pfd[0]);
			close(pfd[0]);
		}
	}
	i = -1;
	while (c[++i].stop == 0)
	{
		waitpid(c[i].pid, NULL, 0);
	}
}
