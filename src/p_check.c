/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:32 by pat               #+#    #+#             */
/*   Updated: 2022/06/28 17:02:20 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	p_check_path(t_data *d, t_pars *p, t_commands *commands, char *argv)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = gc_split(&d->track, argv, ' ');
	if (access(cmd[0], X_OK))
	{
		commands->cmd_path = gc_strdup(&d->track, cmd[0]);
	}
	p->cmd_slash = gc_strjoin(&d->track, "/", cmd[0]);
	while (ft_strncmp (p->envp[i], "PATH", 4))
		i++;
	p->s_path = gc_split(&d->track, &p->envp[i][5], ':');
	i = -1;
	while (p->s_path[++i])
	{
		p->path_access = gc_strjoin(&d->track,
				p->s_path[i], p->cmd_slash);
		if (!access(p->path_access, X_OK))
		{
			commands->cmd_path = p->path_access;
			return ;
		}
		gc_free_malloc(&d->track, (void **)&p->path_access);
	}
	if (access(p->path_access, X_OK) == -1)
	{
		gc_free_all(&d->track);
		perror(argv);
	}
}
