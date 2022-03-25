/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:37:10 by pat               #+#    #+#             */
/*   Updated: 2022/03/25 16:18:37 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


// void	ft_pipe_fork(t_data *d, char **envp, int fd_old_pipe)
// {
// 		if (close (d->m.pfd[1]) == -1)
// 			ft_free_all(d);
// 		if (dup2(d->m.pfd[0], STDIN_FILENO) == -1)
// 			ft_free_all(d);
// 		if (dup2(fd_old_pipe, STDOUT_FILENO) == -1)
// 			ft_free_all(d);
// 		if (close (d->m.pfd[0]) == -1)
// 			ft_free_all(d);
// 		close(d->outfile);
// 		if (execve (d->path2.check_access, d->path2.s_argv, envp) == -1)
// 			ft_free_all(d);
// }
