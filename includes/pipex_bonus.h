/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:42:38 by pat               #+#    #+#             */
/*   Updated: 2022/03/25 20:33:48 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft2/include/libft.h"


typedef struct s_check
{
	
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
}			t_data;
/* check */
void	ft_check(t_data *d);

/* ft_free_error */

/* ft_set */
void ft_set(int argc, char **argv, char **envp, t_data *data);

/* ft_opertation */


#endif
