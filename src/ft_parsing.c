/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:35:24 by pat               #+#    #+#             */
/*   Updated: 2022/03/28 19:13:29 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_add_heredoc(t_data *d, char *argv)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (line)
			gc_free_malloc(&d->track, (void **)&line);
		write(1, "> ", 2);
		line = gc_get_next_line(&d->track, STDIN_FILENO);
		if (!ft_strncmp(argv, line, ft_strlen(line) -1))
			break ;
		d->lst->command->here_doc = gc_strjoin(&d->track,
			d->lst->command->here_doc, line);
	}
	gc_free_malloc(&d->track, (void **)&line);
}

void	ft_add_command(t_data *d, char *argv, int file)
{
	int	pipe_fd[2];

	ft_creat_lst(d);
	if(d->lst->next)
		d->lst = d->lst->next;
	if(pipe(pipe_fd) == -1)
		gc_free_all(&d->track);
	d->lst->command->pfdin = pipe_fd[1];
	d->lst->command->pfdout = pipe_fd[0];
	d->lst->command->argc = d->main.argc;
	if (file)
	{	
		if (file == d_infile)
		{
			d->lst->command->fd_infile = open(argv, O_RDONLY);
			if (d->lst->command->fd_infile == -1)
				perror(argv);

		}
		if (file == d_outfile)
		{
			(d->lst->command->fd_outfile = open(argv, O_TRUNC | O_WRONLY | O_CREAT, 0660));
			if (d->lst->command->fd_outfile == -1)
				perror(argv);
			
		}
		if (file == d_heredoc)
			ft_add_heredoc(d, d->main.argv[2]);
	}
	else
	{
		d->lst->command->cmd = gc_split(&d->track, argv, ' ');
		ft_check_path(d, argv);
	}
	ft_check_fd(d, d->lst->command->fd_infile, d->lst->command->fd_outfile);
}

void	ft_creat_lst(t_data *d)
{
	if (!d->lst)
	{
		d->lst = ft_lstnew(gc_calloc(sizeof(t_command), 1, &d->track));
		d->lst_start = d->lst;
	}
	else
	{
		ft_lstadd_back(&d->lst,
			ft_lstnew(gc_calloc(sizeof(t_command), 1, &d->track)));
	}
}

void	ft_pars_cmd(t_data *d)
{
	int	i;

	i = 1;
	if (ft_strncmp(d->main.argv[1], "here_doc", 8) && d->main.argc < 5)
		gc_free_all(&d->track);
	if (d->main.argc < 4)
		gc_free_all(&d->track);
	while (d->main.argv[i])
	{
		if (!ft_strncmp(d->main.argv[1], "here_doc", ft_strlen("here_doc")) && i == 1)
		{
			ft_add_command(d, d->main.argv[i], d_heredoc);
			i += 2;
		}
		else if(i == 1)
		{
			ft_add_command(d, d->main.argv[i], d_infile);
			i++;
		}
		if (i == d->main.argc - 1)
			ft_add_command(d, d->main.argv[i], d_outfile);
		else
			ft_add_command(d, d->main.argv[i], 0);
		i++;
	}
}
