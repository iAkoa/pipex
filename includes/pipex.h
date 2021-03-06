/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:38 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 18:40:03 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft2/include/libft.h"
# include <errno.h>
# define CMD 1
# define FILE 2

# define INFILE 3
# define OUTFILE 4
# define HEREDOC 5

typedef struct s_commands
{
	char	**args_vec;
	char	**envp;
	char	*cmd_path;
	char	*infile;
	char	*outfile;
	char	*here_doc;
	int		infile_type;
	int		pid;
	int		pid_heredoc;
	int		stop;
}			t_commands;

typedef struct s_pars
{
	char	**s_path;
	char	*path_access;
	char	*cmd_slash;
	int		argc;
	char	**argv;
	char	**envp;
	int		pfd[2];
	int		fd_in;
	int		fd_out;
	char	**cmd;
	int		i;
	int		j;
	t_track	*track;
}			t_pars;

typedef struct s_data
{
	t_pars		pars;
	t_commands	*commands;
	t_track		*track;
}			t_data;

void		p_add_heredoc(t_data *d, t_commands *commands, char *argv);
void		p_add_file(t_commands *commands, char *argv, int file);
void		p_add(t_data *d, t_commands *commands, char *argv, int file);
t_commands	*p_malloc_struct(t_data *d, t_pars *p);
t_commands	*p_parsing(t_data *d, t_pars *p);
void		p_check_path(t_data *d, t_pars *p,
				t_commands *commands, char *argv);
void		close_all_file(t_commands *c);
void		heredoc_pipe(t_commands *c, int i);
void		open_pipe(t_commands *c, int i);
void		close_all_pipe(t_commands *c);
void		e_exec(t_pars *p, t_commands *c);
int			e_outfile(t_pars *p, t_commands *c, int i);
int			e_infile(t_pars *p, t_commands *c, int i);
void		e_heredoc(t_commands c);
int			e_child(t_pars *p, t_commands *c, int i);
void		e_execve(t_pars *p, t_commands *c, int i);

#endif
