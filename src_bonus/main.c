/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/03/24 01:54:34 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	/* <<<<<<<<<<<<<START>>>>>>>>>>>>>>>> */

	t_data		d;
	int	fd_out;
	
	ft_init_ptr(&d);
	d.infile = open (argv[1], O_RDONLY);
	while (argv[d.i])
		d.i++;
	d.outfile = open (argv[d.i - 1], O_RDWR | O_CREAT);
	d.m.pid = ft_calloc(sizeof(int), d.i - 2);
	printf("argc = %i\n", argc);
	d.i = 0;
	if (pipe(d.m.pfd) == -1)
		ft_error(0, 0, &d);
	fd_out =  d.m.pfd[1];
	while (d.i < argc)
	{
		if (d.i != 0 && d.i != argc - 1)
			ft_path_step(envp, argv[d.i],&d.path, &d);
		if ((d.m.pid[d.i] = fork()) == -1)
			ft_error(1, 0, &d);
		if (d.m.pid[d.i] == 0 && d.i == 0)
			ft_infile_fork(&d, envp);
		else if (d.m.pid[d.i] == 0 && d.i == argc - 1)
			ft_outfile_fork(&d, envp);
		else if (d.m.pid[d.i] == 0)
			ft_pipe_fork(&d, envp, fd_out);
		dprintf(2, "pid ========> %i\n", d.m.pid[0]);
		if (pipe(d.m.pfd) == -1)
			ft_error(0, 0, &d);
		fd_out =  d.m.pfd[1];
		d.i++;
	}
	if (close (d.m.pfd[0]) == -1)
			ft_free_all(&d);
	if (close (d.m.pfd[1]) == -1)
			ft_free_all(&d);
	if (close (d.outfile) == -1)
		ft_free_all(&d);
	if (close (d.infile) == -1)
		ft_free_all(&d);
	d.i = 0;
	// while (d.m.pid[d.i])
	// {
	// 	if (waitpid(d.m.pid[d.i], NULL, 0) == -1)
	// 		ft_free_all(&d);
	// }
	ft_free_all(&d);

	/* <<<<<<<<<<<<<FINISH>>>>>>>>>>>>>>>> */
	return (0);
}
