/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:32 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 01:07:47 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void ft_check_fd(t_data *d, int infile, int outfile)
{
	if (infile == -1)
		gc_free_all(&d->track);
	if (outfile == -1)
		gc_free_all(&d->track);
}

void	ft_check_path(t_data *d, char *argv)
{
	int		i;
	char	**cmd;
	i = 0;
	
	cmd = gc_split(&d->track, argv, ' ');
	d->check.cmd_slash = gc_strjoin(&d->track, "/", cmd[0]);
	while(ft_strncmp (d->main.envp[i], "PATH", 4))
		i++;
	d->check.s_path = gc_split(&d->track, &d->main.envp[i][5], ':');
	i = -1;
	while(d->check.s_path[++i])
	{
		d->check.path_access = gc_strjoin(&d->track,
			d->check.s_path[i], d->check.cmd_slash);
		if (!access(d->check.path_access, X_OK))
		{
			d->lst->command->cmd_path = d->check.path_access;
			return ;
		}
		gc_free_malloc(&d->track, (void **)&d->check.path_access);
	}
	gc_free_all(&d->track);
}