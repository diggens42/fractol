/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:30:27 by fwahl             #+#    #+#             */
/*   Updated: 2023/12/08 18:01:34 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "fractol.h"

// Mandelbrot: z = z^2 + c
//			   z id initially (0,0)
//			   c is actual point
//
// Julia:	   ./fractol <real> <complex>
//			   z = pixel_point + constant

// static void	select_type(int x, int y, t_fractol *fractal)
// {
// 	static int is_init = 0;
// 	double	scale;
	
// 	scale = 2.0 / (WIDTH * fractal -> zoom);
// 	if (!ft_strncmp(fractal -> name, "julia", 5))
// 	{
// 		if (!is_init)
// 		{
// 			fractal -> c.x = fractal -> julia_x;
// 			fractal -> c.y = fractal -> julia_y;
// 			is_init = 1;
// 		}
// 		fractal -> z.x = (x - WIDTH / 2.0) * scale + fractal -> center_x;
// 		fractal -> z.y = (y - HEIGHT / 2.0) * scale + fractal -> center_y;
// 	}
// 	else if (!ft_strncmp(fractal -> name, "mandelbrot", 10))
// 	{
// 		fractal -> c.x = (x - WIDTH / 2.0) * scale + fractal -> center_x;
// 		fractal -> c.y = (y - HEIGHT / 2.0) * scale + fractal -> center_y;
// 		fractal -> z.x = 0;
// 		fractal -> z.x = 0;
// 	}
// }

void	draw_pixel(int x, int y, t_fractol *fractal)
{
	int		i;
	int		color;
	double	scale;
	
	scale = 2.0 / (WIDTH * fractal -> zoom);
	if (!ft_strncmp(fractal -> name, "julia", 5))
	{
		fractal -> z.x = (x - WIDTH / 2.0) * scale + fractal -> center_x;
		fractal -> z.y = (y - HEIGHT / 2.0) * scale + fractal -> center_y;
	}
	else if (!ft_strncmp(fractal -> name, "mandelbrot", 10))
	{
		fractal -> c.x = (x - WIDTH / 2.0) * scale + fractal -> center_x;
		fractal -> c.y = (y - HEIGHT / 2.0) * scale + fractal -> center_y;
		fractal -> z.x = 0;
		fractal -> z.y = 0;
	}
	i = 0;
	while (i < fractal -> max_itr)
	{
		fractal -> z = sum_cmplx(square_cmplx(fractal -> z), fractal -> c);
		if ((fractal -> z.x * fractal -> z.x) + (fractal -> z.y * fractal -> z.y) > fractal -> div_val)
		{
			color = get_color(i);
			mlx_put_pixel(fractal->img.img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal -> img.img, x, y, C15);
}

void	draw_fractal(t_fractol *fractal)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			draw_pixel(x, y, fractal);
		}
	}
	mlx_image_to_window(fractal -> mlx_init, fractal -> img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol fractal;
	
	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		init_fractal(&fractal);
		draw_fractal(&fractal);
		mlx_loop(fractal.mlx_init);
	}
	else
	{
		error_input(&fractal);
		exit(EXIT_FAILURE);
	}
	mlx_terminate(fractal.mlx_init);
}

