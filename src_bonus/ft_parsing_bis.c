/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:35:24 by pat               #+#    #+#             */
/*   Updated: 2022/06/12 20:30:22 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_add_command_bis(t_data *d, char *argv, int file)
{
	if (file == D_INFILE)
	{
		d->lst->command->fd_infile = open(argv, O_RDONLY);
		if (d->lst->command->fd_infile == -1)
		{
			perror(argv);
			exit(0);
		}
	}
	if (file == D_OUTFILE)
	{
		(d->lst->command->fd_outfile
				= open(argv, O_TRUNC | O_WRONLY | O_CREAT, 0660));
		if (d->lst->command->fd_outfile == -1)
		{
			perror(argv);
			exit(0);
		}
	}
	if (file == D_HEREDOC)
		ft_add_heredoc(d, d->main.argv[2]);
}
