/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:11:09 by rmattheo          #+#    #+#             */
/*   Updated: 2022/01/18 11:43:18 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_usigned_fd(unsigned int n, int fd, int i)
{	
	if (fd == 0)
		return (0);
	else if (n >= 10)
	{	
		i = ft_putnbr_fd(n / 10, fd, i);
		i += ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		i += ft_putchar_fd(n + '0', fd);
	return (i);
}
