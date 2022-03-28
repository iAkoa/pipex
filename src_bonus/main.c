/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 02:44:03 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data d;
	t_track *track;

	track = NULL;
	ft_set(argc, argv, envp, &d);
	d.track = track;
	ft_pars_cmd(&d);
	d.lst = d.lst_start;
	printf("\n\n\n");
	// while (d.lst)
	// {	
	// 	if (d.lst->command->cmd)
	// 		printf("cmd = %s\n",d.lst->command->cmd[0]);
	// 	printf("path = %s\n",d.lst->command->cmd_path);
	// 	printf("fd infile =  %i\n",d.lst->command->fd_infile);
	// 	printf("fd outfile =  %i\n",d.lst->command->fd_outfile);
	// 	printf("heredoc = %s\n",d.lst->command->here_doc);
	// 	printf("pfdin = %i\n",d.lst->command->pfdin);
	// 	printf("pfout = %i\n",d.lst->command->pfdout);
	// 	printf("\n\n\n");
	// 	d.lst = d.lst->next;
	// }
	ft_exec(&d);
	return (0);
}
