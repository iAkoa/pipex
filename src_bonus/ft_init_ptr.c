/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:25:37 by pat               #+#    #+#             */
/*   Updated: 2022/03/23 23:47:02 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_init_ptr(t_data *d)
{
	d->i = 0;
	d->path.check_access = NULL;
	d->m.pid = NULL;
	d->path.s_argv = NULL;
	d->path.s_envp = NULL;
	d->path.argv = NULL;
}