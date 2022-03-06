/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:44 by pat               #+#    #+#             */
/*   Updated: 2022/03/06 22:59:49 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	const char *quisuisje;

	pid_t pid;
	quisuisje = "le pere";
	pid = fork();
	if (pid == 0)
	{
		quisuisje = "le fils";
		printf("je suis %s\n", quisuisje);
	}
	else
	{
		printf("je suis %s\n", quisuisje);
		wait(NULL);
	}
	return 0;
}
