/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:37:10 by pat               #+#    #+#             */
/*   Updated: 2022/03/23 22:33:03 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_first_fork(t_data *d, char **envp)
{
		if (close (d->m.pfd[0]) == -1)
			ft_free_all(d);
		if (dup2(d->infile, STDIN_FILENO) == -1)
			ft_free_all(d);
		if (dup2(d->m.pfd[1], STDOUT_FILENO) == -1)
			ft_free_all(d);
		if (close (d->m.pfd[1]) == -1)
			ft_free_all(d);
		close (d->infile);
		if (execve (d->path1.check_access, d->path1.s_argv, envp) == -1)
		{
			dprintf(2, "error\n");
			ft_free_all(d);
		}
}

void	ft_second_fork(t_data *d, char **envp)
{
		if (close (d->m.pfd[1]) == -1)
			ft_free_all(d);
		if (dup2(d->m.pfd[0], STDIN_FILENO) == -1)
			ft_free_all(d);
		if (dup2(d->outfile, STDOUT_FILENO) == -1)
			ft_free_all(d);
		if (close (d->m.pfd[0]) == -1)
			ft_free_all(d);
		close(d->outfile);
		if (execve (d->path2.check_access, d->path2.s_argv, envp) == -1)
		{
			dprintf(2, "test\n");
			ft_free_all(d);
		}
}