/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:08:57 by fwahl             #+#    #+#             */
/*   Updated: 2023/12/05 16:19:53 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int get_color(int itr)
{
	unsigned int	colors[15];
	
	colors[0] = C1;
	colors[1] = C2;
	colors[2] = C3;
	colors[3] = C4;
	colors[4] = C5;
	colors[5] = C6;
	colors[6] = C7;
	colors[7] = C8;
	colors[8] = C9;
	colors[9] = C10;
	colors[10] = C11;
	colors[11] = C12;
	colors[12] = C13;
	colors[13] = C14;
	colors[14] = C15;

	return (colors[itr % 15]);
}

t_cmplx	sum_cmplx(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	res;
	
	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_cmplx	square_cmplx(t_cmplx z)
{
	t_cmplx	res;
	
	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = z.x * z.y * 2;
	return (res);
}

double	atodbl(char *s)
{
	long	int_part;
	double	fract_part;
	double	pow;
	int		sign;

	int_part = 0;
	fract_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32 || *s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		++s;
	}
	while (*s != '.' && *s != '\0')
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10.0;
		fract_part = fract_part + (*s - '0') * pow;
		++s;
	}
	return(((double)int_part + fract_part) * (double)sign);
}