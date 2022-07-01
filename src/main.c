/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 17:17:17 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	p_set(int argc, char **argv, char **envp, t_pars *p)
{
	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;
	
	(void)argc;
	(void)argv;
	(void)envp;
	d.track = NULL;
	if (argc != 5)
	{
		write (1, "need 4 arguments !\n", 20);
		exit(1);
	}
	p_set(argc, argv, envp, &d.pars);
	d.commands = p_parsing(&d, &d.pars);
	// while (d.track->next != NULL)
	// {
	// 	if (d.track->address)
	// 		dprintf(2, "track address = %p\n", d.track->address);
	// 	d.track = d.track->next;
	// }
	e_exec(&d, &d.pars, d.commands);
	gc_free_all(&d.track);
	return (0);
}
