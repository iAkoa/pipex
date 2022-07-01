/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 13:41:56 by pat              ###   ########lyon.fr   */
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

	if (argc != 5)
	{
		write (1, "need 4 arguments !\n", 20);
		exit(1);
	}
	track = NULL;
	d.track = track;
	p_set(argc, argv, envp, &d.pars);
	d.commands = p_parsing(&d, &d.pars);
	while (d.track != NULL)
	{
		dprintf("track address = %p\n", d.track->address);
		d.track->next = d.track;
	}
	e_exec(&d, &d.pars, d.commands);
	return (0);
}
