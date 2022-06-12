/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:31:52 by rmattheo          #+#    #+#             */
/*   Updated: 2022/06/11 14:27:19 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/gc.h"

static int	ft_itoa_bis_bis(int i, int nb, int n)
{	
	if (n < 0)
		nb = -nb + 0 * i++;
	while (nb >= 10)
		nb /= 10 + 0 * i++;
	return (i);
}

static void	ft_itoa_bis(int n, char *str)
{
	if (n < 0)
		str[0] = '-';
}

char	*ft_itoa(int n)
{	
	long	nb;
	char	*str;
	int		i;

	i = 1;
	nb = n;
	i = ft_itoa_bis_bis(i, nb, n);
	nb = n;
	if (nb < 0)
		nb = -nb;
	str = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	ft_itoa_bis(n, str);
	while (nb >= 10)
	{
		str[--i] = nb % 10 + 48;
		nb /= 10;
	}
	str[--i] = nb % 10 + 48;
	return (str);
}
