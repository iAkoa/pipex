/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:35:24 by pat               #+#    #+#             */
/*   Updated: 2022/06/28 16:58:25 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	p_add_heredoc(t_data *d, t_commands *commands, char *argv)
{
	char	*line;

	line = NULL;
	// commands[0].here_doc = gc_calloc(sizeof(char), 1, &d->track);
	while (1)
	{
		
		if (line)
			gc_free_malloc(&d->track, (void **)&line);
		write(1, "> ", 2);
		line = gc_get_next_line(&d->track, STDIN_FILENO);
		line[ft_strlen(line) - 1] = 0;
		if (!ft_strncmp(argv, line, ft_strlen(argv)))
			break ;
		commands[0].here_doc = gc_strjoin(&d->track,
				commands->here_doc, line);
		commands[0].here_doc = gc_strjoin(&d->track, commands[0].here_doc,
				"\n");
	}
	gc_free_malloc(&d->track, (void **)&line);
}

void	p_add_file(t_commands *commands, char *argv, int file)
{
	if (file == D_INFILE)
	{
		commands->infile = argv;
	}
	if (file == D_OUTFILE)
		commands->outfile = argv;
}

void	p_add(t_data *d, t_commands *commands, char *argv, int file)
{
	if (file == D_HEREDOC)
	{
		p_add_heredoc(d, commands, d->pars.argv[2]);
	}
	else if (file)
	{
		p_add_file(commands, argv, file);
	}
	else
	{
		commands->args_vec = gc_split(&d->track, argv, ' ');
		p_check_path(d, &d->pars, commands, argv);
	}
}

t_commands	*p_malloc_struct(t_data *d, t_pars *p)
{
	t_commands *commands;
	if (ft_strncmp(p->argv[1], "here_doc", 8) == 0)
	{
		commands = gc_calloc(sizeof(t_commands), p->argc - 3, &d->track);
		commands[p->argc - 4].stop = 1;
	}
	else
	{
		commands = gc_calloc(sizeof(t_commands), p->argc - 2, &d->track);
		commands[p->argc - 3].stop = 1;
	}
	return (commands);
}

/* JE PARS EN FONCTION DE SI JAI UN INFILE UN OUTFILE OU UN HEREDOC */
t_commands *p_parsing(t_data *d, t_pars *p)
{
	int	i;
	int j;
	t_commands *commands;

	j = 0;
	i = 1;
	commands = p_malloc_struct(d, p);
	while (p->argv[i])
	{
		if (!ft_strncmp(p->argv[1], "here_doc", ft_strlen("here_doc"))
			&& i == 1)
		{
			p_add(d, &commands[j], p->argv[i], D_HEREDOC);
			i += 2;
		}
		else if (i == 1)
		{
			p_add(d, &commands[j], p->argv[i], D_INFILE);
			i++;
		}
		if (i == p->argc - 1)
		{
			p_add(d, &commands[--j], p->argv[i], D_OUTFILE);
		}
		else
		{
			p_add(d, &commands[j], p->argv[i], 0);
		}
		i++;
		j++;
	}
	return (commands);
}
