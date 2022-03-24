/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:25:37 by pat               #+#    #+#             */
/*   Updated: 2022/03/19 12:02:10 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_ptr(t_data *d)
{
	d->path1.s_argv = NULL;
	d->path1.s_envp = NULL;
	d->path2.s_argv = NULL;
	d->path2.s_envp = NULL;
	d->path1.argv = NULL;
	d->path2.argv = NULL;
	d->path2.check_access = NULL;
	d->path1.check_access = NULL;
}