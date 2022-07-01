/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:32 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 19:06:41 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	p_while_check(t_data *d, t_pars *p, t_commands *commands, int i)
{
	p->path_access = gc_strjoin(&d->track,
			p->s_path[i], p->cmd_slash);
	if (!access(p->cmd[0], X_OK))
	{
		commands->cmd_path = p->cmd[0];
		return (0);
	}
	if (!access(p->path_access, X_OK))
	{
		commands->cmd_path = p->path_access;
		return (0);
	}
	gc_free_malloc(&d->track, (void **)&p->path_access);
	return (1);
}

void	p_check_path(t_data *d, t_pars *p, t_commands *commands, char *argv)
{
	int		i;

	i = 0;
	p->cmd = gc_split(&d->track, argv, ' ');
	if (access(p->cmd[0], X_OK) && p->cmd[0])
		commands->cmd_path = gc_strdup(&d->track, p->cmd[0]);
	p->cmd_slash = gc_strjoin(&d->track, "/", p->cmd[0]);
	while (ft_strncmp (p->envp[i], "PATH", 4))
		i++;
	p->s_path = gc_split(&d->track, &p->envp[i][5], ':');
	i = -1;
	while (p->s_path[++i])
	{
		if (!p_while_check(d, p, commands, i))
			return ;
	}
}
