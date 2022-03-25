/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:35:24 by pat               #+#    #+#             */
/*   Updated: 2022/03/25 20:51:49 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_heredoc(t_data *d, char *argv)
{
	char	*line;
	char	*tmp_line;
	d->lst->command->limiter = argv;
	line = gc_get_next_line(&d->track, STDIN_FILENO);
	d->lst->command->here_doc = line;
	while (line != argv)
	{
		d->lst->command->here_doc = gc_strjoin(&d->track,
			d->lst->command->here_doc, line);
		gc_free_malloc(&d->track, line);
		line = gc_get_next_line(&d->track, STDIN_FILENO);
	}
	gc_free_malloc(&d->track, line);
}

void	ft_add_command(t_data *d, char *argv, int file)
{
	int pipe_fd[2];
	int fd_infile;
	int fd_outfile;
	
	if (file)
	{	
		if (file == infile)
		{
			fd_infile = open(argv, O_RDONLY);
			d->lst->command->fd_infile = fd_infile;
		}
		if (file == outfile)
		{
			fd_outfile = open(argv, O_RDWR, O_CREAT);
			d->lst->command->fd_outfile = fd_outfile;
		}
		if (file == heredoc)
			ft_heredoc(d, argv);
	}
	else
		d->lst->command->cmd_path = argv;
	d->lst->command->pfdin = pipe_fd[1];
	d->lst->command->pfdout = pipe_fd[0];
	d->lst->command->argc = d->main.argc;
	
}

int	ft_check(t_data *d)
{
	int	i;
	t_list *lst_cmd;
	i = 1;
	if (d->main.argc < 4)
		gc_free_all(&d->track);
	lst_cmd = gc_calloc(sizeof(t_list), d->main.argc, &d->track);
	while (d->main.argv[i])
	{
		if (i == 1)
			ft_add_command(d, d->main.argv[i], 1)

	}
	return (0);	
}
