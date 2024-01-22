/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:11:23 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/20 18:32:08 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_malloc(void)
{
	ft_putstr("Malloc error");
	exit(EXIT_FAILURE);
}

void	error_input(void)
{
	ft_putstr("Invalid input, please enter the following:\n");
	ft_putstr("./fractol mandelbrot\n");
	ft_putstr("./fractol julia <c.x: -2.0 to 2.0> <c.y: -2.0 to 2.0>\n");
	ft_putstr("./fractol bs\n");
	exit(EXIT_FAILURE);
}
