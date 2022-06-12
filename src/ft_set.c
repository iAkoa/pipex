/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:24:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/06/07 17:58:57 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_set(int argc, char **argv, char **envp, t_data *d)
{
	d->main.argc = argc;
	d->main.argv = argv;
	d->main.envp = envp;
}
