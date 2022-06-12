/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:38 by pat               #+#    #+#             */
/*   Updated: 2022/06/11 14:23:48 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft2/include/libft.h"
# include <errno.h>

typedef struct s_check
{
	char	**s_path;
	char	*path_access;
	char	*cmd_slash;
}			t_check;

typedef struct s_main
{
	int		argc;
	char	**argv;
	char	**envp;
}			t_main;

typedef struct s_data
{
	t_list		*lst;
	t_track		*track;
	t_check		check;
	t_main		main;
	t_list		*lst_start;
}			t_data;

void	ft_check_path(t_data *d, char *argv);
void	ft_check_fd(t_data *d, int infile, int outfile);
void	ft_add_heredoc(t_data *d, char *argv);
void	ft_add_command(t_data *d, char *argv, int file);
void	ft_add_command_bis(t_data *d, char *argv, int file);
void	ft_pars_cmd(t_data *d);
void	ft_close_all_pipe(t_data *d);
void	ft_set(int argc, char **argv, char **envp, t_data *data);
void	ft_creat_lst(t_data *d);
void	ft_pipe_infile_cmd(t_data *d);
void	ft_pipe_cmd_cmd(t_data *d);
void	ft_pipe_cmd_outfile(t_data *d);
void	ft_pipe_heredock_cmd(t_data *d);
void	ft_pipe_infile_cmd_outfile(t_data *d);
void	ft_pipe_heredock_cmd_outfile(t_data *d);
void	ft_exec(t_data *d);

#endif
