/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/06/28 16:47:00 by pat              ###   ########lyon.fr   */
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
	t_track	*track;
	

	// if (argc != 5)
	// {
	// 	write (1, "need 4 arguments !\n", 20);
	// 	exit(1);
	// }
	track = NULL;
	d.track = track;
	p_set(argc, argv, envp, &d.pars);
	d.commands = p_parsing(&d, &d.pars);
	int i;
	printf("/////////\n");
	i = 0;
	while(!d.commands[i].stop)
	{
		printf("cmd = %s\n", d.commands[i].args_vec[0]);
		printf("infile = %s\n", d.commands[i].infile);
		printf("outfile = %s\n", d.commands[i].outfile);
		printf("cmd path = %s\n", d.commands[i].cmd_path);
		printf("heredoc = %s\n", d.commands[i].here_doc);
		printf("infile ype = %d\n", d.commands[i].infile_type);
		i++;
		printf("/////////\n");
	}
	e_exec(&d, &d.pars, d.commands);
	return (0);
}
