/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:38 by pat               #+#    #+#             */
/*   Updated: 2022/03/23 18:57:01 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft2/include/libft.h"


typedef struct s_path
{
	int		i;
	char	**s_envp;
	char	**s_argv;
	char	*check_access;
	char	*argv;
}			t_path;

typedef struct s_main
{
	int		pfd[2];
	int		pid1;
	int		pid2;
}			t_main;

typedef struct s_data
{
	t_path	path1;
	t_path	path2;
	t_main	m;
	int		infile;
	int		outfile;
}			t_data;

/* ft_free_error */
void	ft_free_split(void ***ptr);
void	ft_error(int i, char *argv, t_data *d);
void	ft_free_all(t_data *d);
void	ft_memdel(void **ptr);
void	ft_init_ptr(t_data *d);

/* ft_check */
void	ft_path (char **envp, char **argv, t_data *d);
int		ft_path_step (char **envp, char *argv, t_path *p, t_data *d);

/* ft_opertation */
void	ft_first_fork(t_data *d, char **envp);
void	ft_second_fork(t_data *d, char **envp);


#endif
