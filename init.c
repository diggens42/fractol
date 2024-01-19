/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:50:46 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/19 22:06:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractol *fr)
{
	fr -> mlx_init = mlx_init(WIDTH, HEIGHT, fr->name, true);
	if (fr->mlx_init == NULL)
	{
		mlx_terminate(fr->mlx_init);
		free(fr->mlx_init);
		error_malloc();
	}
	fr->img.img = mlx_new_image(fr->mlx_init, WIDTH, HEIGHT);
	if (fr->img.img == NULL)
	{
		mlx_terminate(fr->mlx_init);
		free(fr->mlx_init);
		error_malloc();
	}
	init_struct(fr);
	init_events(fr);
}

void	init_struct(t_fractol *fr)
{
	fr->max_itr = 42;
	fr->zoom = 1.0;
	fr->center_x = 0.0;
	fr->center_y = 0.0;
	fr->color_shift = 1;
}

void	init_events(t_fractol *fr)
{
	mlx_key_hook(fr->mlx_init, handle_key, fr);
	mlx_scroll_hook(fr->mlx_init, handle_scroll, fr);
}
