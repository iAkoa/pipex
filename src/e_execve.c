/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:08:33 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 13:21:21 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	e_execve(t_pars *p, t_commands *c, int i)
{
	if (execve(c[i].cmd_path, c[i].args_vec, p->envp) == -1)
	{
		write(2, "bash: ", 6);
		write(2, c[i].args_vec[0], ft_strlen(c[i].args_vec[0]));
		write(2, ": command not found\n", 21);
	}
}
