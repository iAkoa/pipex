/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:35:24 by pat               #+#    #+#             */
/*   Updated: 2022/03/23 23:06:47 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_path_step (char **envp, char *argv, t_path *p, t_data *d)
{
	/* on cherche la variables d’environnement PATH */
	p->i = 0;
	while (ft_strncmp(envp[p->i], "PATH", 4))
		p->i++;
	/* [5] retire le 'PATH=' de la chaine de caractère puis on split des differents chemins d'accès*/
	p->s_envp = ft_split(&envp[p->i][5], ':');
	if (!p->s_envp)
		ft_free_all(d);
	p->i = -1;
	/* split la commande ls -la en ls et -la */
	p->s_argv = ft_split(argv, ' ');
	if (!p->s_argv)
		ft_free_all(d);
	/* trouve la commande dans les differents chemins d'accès*/
	while (p->s_envp[++(p->i)])
	{	
		p->check_access = ft_strjoin(p->s_envp[p->i], p->s_argv[0]);
		if (!p->check_access)
			ft_free_all(d);
		if (!access(p->check_access, X_OK))
			return (1);
		ft_memdel((void **)&p->check_access);
	}
	return (0);	
}