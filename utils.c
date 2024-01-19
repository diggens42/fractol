/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:08:57 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/19 21:09:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color_mandel_julia(int itr, int shift)
{
	unsigned int	colors[15];

	colors[0] = 0x000764FF;
	colors[1] = 0x0C2F8DFF;
	colors[2] = 0x1957B6FF;
	colors[3] = 0x387CD1FF;
	colors[4] = 0x69A0DDFF;
	colors[5] = 0x9AC3EAFF;
	colors[6] = 0xCBE6F6FF;
	colors[7] = 0xEEF7E8FF;
	colors[8] = 0xF3DFA1FF;
	colors[9] = 0xF8C759FF;
	colors[10] = 0xFDAF11FF;
	colors[11] = 0xC78500FF;
	colors[12] = 0x7D5400FF;
	colors[13] = 0x332300FF;
	colors[14] = 0x000000FF;
	return (colors[(itr + shift) % 15]);
}

unsigned int	get_color_bs(int itr, int shift)
{
	unsigned int	colors[15];

	colors[0] = 0xFF0000FF;
	colors[1] = 0xFF0D00FF;
	colors[2] = 0xFF1A00FF;
	colors[3] = 0xFF2600FF;
	colors[4] = 0xFF3300FF;
	colors[5] = 0xFF4000FF;
	colors[6] = 0xFF4D00FF;
	colors[7] = 0xFF5900FF;
	colors[8] = 0xFF6600FF;
	colors[9] = 0xFF7300FF;
	colors[10] = 0xFF8000FF;
	colors[11] = 0xFF8C00FF;
	colors[12] = 0xFF9900FF;
	colors[13] = 0xFFA600FF;
	colors[14] = 0xFFFF00FF;
	return (colors[(itr + shift) % 15]);
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
	while ((*s >= 9 && *s <= 13) || *s == 32 || *s == '+' || (*s == '-'))
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
		fract_part = fract_part + (*s++ - '0') * pow;
	}
	return (((double)int_part + fract_part) * (double)sign);
}
