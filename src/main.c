/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/03/31 21:22:45 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data d;
	t_track *track;

	if (argc < 5)
	{
		write (1, "not enough arguments !\n", 23);
		exit(1);
	}
	track = NULL;
	ft_set(argc, argv, envp, &d);
	d.track = track;
	ft_pars_cmd(&d);
	d.lst = d.lst_start;
	printf("path == %s\n", d.check.path_access);
	ft_exec(&d);
	d.lst = d.lst_start;
	return (0);
}
