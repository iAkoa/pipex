/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 00:33:22 by pat               #+#    #+#             */
/*   Updated: 2022/07/01 18:32:37 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	p_set(int argc, char **argv, char **envp, t_pars *p)
{
	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
}
