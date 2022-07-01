/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 18:40:43 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	p_set(int argc, char **argv, char **envp, t_pars *p)
{
	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;
	t_track	*track;

	if (argc < 4 && ft_strcmp(argv[1], "here_doc"))
	{
		write (1, "need 4 arguments !\n", 20);
		exit(1);
	}
	if (argc < 5 && !ft_strcmp(argv[1], "here_doc"))
	{
		write (1, "need 5 arguments !\n", 20);
		exit(1);
	}
	track = NULL;
	d.track = track;
	p_set(argc, argv, envp, &d.pars);
	d.commands = p_parsing(&d, &d.pars);
	e_exec(&d.pars, d.commands);
	return (0);
}
