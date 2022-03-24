/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/03/23 19:19:34 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	/* <<<<<<<<<<<<<START>>>>>>>>>>>>>>>> */

	t_data d;

	d.infile = open (argv[1], O_RDONLY);
	d.outfile = open (argv[4], O_RDWR | O_CREAT);
	printf("%i\n", d.infile);
	printf("%i\n", d.outfile);
	ft_init_ptr(&d);
	/* check argv correct */
	if (argc != 5)
		ft_error(0, 0, &d);
	/* fonction parsing argv and envp before operation */
	ft_path (envp, argv, &d);
	/* create pipe */
	if (pipe(d.m.pfd) == -1)
		ft_error(0, 0, &d);
	/* first fork create */
	if ((d.m.pid1 = fork()) == -1)
		ft_error(1, 0, &d);
	/* first fork operation */
	if (d.m.pid1 == 0)
		ft_first_fork(&d, envp);
	/* 2nd fork create */
	if ((d.m.pid2 = fork()) == -1)
		ft_error(1, 0, &d);
	/* 2nd fork operation */
	if (d.m.pid2 == 0)
		ft_second_fork(&d, envp);
	close (d.outfile);
	close (d.infile);
	/* close fd pipe for no conflit with other processus */
	if (close (d.m.pfd[0]) == -1)
		ft_free_all(&d);
	if (close (d.m.pfd[1]) == -1)
		ft_free_all(&d);
	/* fonction wait processus fork finish */
	if (waitpid(d.m.pid1, NULL, 0) == -1)
		ft_free_all(&d);
	if (waitpid(d.m.pid2, NULL, 0) == -1)
		ft_free_all(&d);
	ft_free_all(&d);
	/* <<<<<<<<<<<<<FINISH>>>>>>>>>>>>>>>> */
	return (0);
}
