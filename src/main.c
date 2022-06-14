/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/06/14 09:17:59 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	ft_set(argc, argv, envp, &d);
	d.track = track;
	ft_pars_cmd(&d);
	d.lst = d.lst_start;
	ft_exec(&d);
	d.lst = d.lst_start;
	gc_free_all(&d.track);
	return (0);
}
