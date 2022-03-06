/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colinterpolate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:07 by rmattheo          #+#    #+#             */
/*   Updated: 2022/02/24 18:18:04 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_colinterpolate(int color1, int color2, double purcent)
{
	unsigned char	c[6];

	c[0] = (color1 >> 16) & 0xff;
	c[1] = (color2 >> 16) & 0xff;
	c[2] = (color1 >> 8) & 0xff;
	c[3] = (color2 >> 8) & 0xff;
	c[4] = color1 & 0xff;
	c[5] = color2 & 0xff;
	return ((int)((c[1] - c[0]) * purcent + c[0]) << 16 |
		(int)((c[3] - c[2]) * purcent + c[2]) << 8 |
		(int)((c[5] - c[4]) * purcent + c[4]));
}
