/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:50:46 by fwahl             #+#    #+#             */
/*   Updated: 2023/12/07 19:14:04 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractol *fractal)
{
	fractal -> mlx_init = mlx_init(WIDTH, HEIGHT, fractal -> name, true);
	if (fractal -> mlx_init == NULL)
	{
		mlx_terminate(fractal -> mlx_init);
		free(fractal -> mlx_init);
		error_malloc();
	}
	fractal->img.img = mlx_new_image(fractal -> mlx_init, WIDTH, HEIGHT);
	if (fractal -> img.img == NULL)
	{
		mlx_terminate(fractal -> mlx_init);
		free(fractal -> mlx_init);
		error_malloc();
	}
	init_struct(fractal);
	init_events(fractal);
}

void	init_struct(t_fractol *fractal)
{
	fractal -> div_val = 4;
	fractal -> max_itr = 50;
	fractal -> zoom = 1.0;
	fractal -> center_x = 0.0;
	fractal -> center_y = 0.0;
	if (!ft_strncmp(fractal -> name, "julia", 5))
	{
		fractal -> c.x = fractal -> julia_x;
		fractal -> c.y = fractal -> julia_y;		
	}

}

void	init_events(t_fractol *fractal)
{
	mlx_key_hook(fractal -> mlx_init, handle_key, fractal);
	// mlx_cursor_hook(fractal -> mlx_init, handle_mouse_pos, &fractal);
	mlx_scroll_hook(fractal -> mlx_init, handle_scroll, fractal);
}
