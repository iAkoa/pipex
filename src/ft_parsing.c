/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:35:24 by pat               #+#    #+#             */
/*   Updated: 2022/06/11 14:27:48 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_add_heredoc(t_data *d, char *argv)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (line)
			gc_free_malloc(&d->track, (void **)&line);
		write(1, "> ", 2);
		line = gc_get_next_line(&d->track, STDIN_FILENO);
		if (!ft_strncmp(argv, line, ft_strlen(line) - 1))
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
	if (d->lst->next)
		d->lst = d->lst->next;
	if (pipe(pipe_fd) == -1)
		gc_free_all(&d->track);
	d->lst->command->pfdin = pipe_fd[1];
	d->lst->command->pfdout = pipe_fd[0];
	d->lst->command->argc = d->main.argc;
	if (file)
	{
		ft_add_command_bis(d, argv, file);
	}
	else
	{
		d->lst->command->cmd = gc_split(&d->track, argv, ' ');
		ft_check_path(d, argv);
	}
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
	while (d->main.argv[i])
	{
		if (!ft_strncmp(d->main.argv[1], "here_doc", ft_strlen("here_doc"))
			&& i == 1)
		{
			ft_add_command(d, d->main.argv[i], D_HEREDOC);
			i += 2;
		}
		else if (i == 1)
		{
			ft_add_command(d, d->main.argv[i], D_INFILE);
			i++;
		}
		if (i == d->main.argc - 1)
			ft_add_command(d, d->main.argv[i], D_OUTFILE);
		else
			ft_add_command(d, d->main.argv[i], 0);
		i++;
	}
}
