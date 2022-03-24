/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:25:27 by pat               #+#    #+#             */
/*   Updated: 2022/03/24 01:15:37 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void ft_free_split(void ***ptr)
{
	//char **pstr = (char **)*ptr;
	if (!ptr || !*ptr)
		return;
	int i = 0;
	while ((*ptr)[i])
	{
		ft_memdel(&(*ptr)[i]);
		i++;
	}  
	ft_memdel((void **)ptr);
}

void ft_error(int i, char *argv, t_data *d)
{
	/* free tous et send des messages d'erreurs */

	if (i == 0)
		write(1, "pipe failed !\n", 15);
	if (i == 1)
		write(1, "fork failed !\n", 15);
	if (i == 2)
	{
		write(1, "command not found : ", ft_strlen("command not found : "));
		write(1, argv, strlen(argv));
		write(1, "\n", 1);
	}
	ft_free_all(d);
	// exit(1);
}

void ft_free_all(t_data *d)
{
	// ft_free_split((void ***)&d->path1.s_envp);
	// ft_free_split((void ***)&d->path2.s_envp);
	// ft_free_split((void ***)&d->path1.s_argv);
	// ft_free_split((void ***)&d->path2.s_argv);
	// ft_free_split((void ***)&d->path1.argv);
	// ft_free_split((void ***)&d->path2.argv);
	// ft_memdel((void **)&d->path1.check_access);
	// ft_memdel((void **)&d->path2.check_access);
	d->i = d->i;
	// exit(1);
}

void	ft_memdel(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
