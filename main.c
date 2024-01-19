/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:50:46 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/19 22:07:16 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_cords(int x, int y, t_fractol *fr)
{
	double	scale;

	scale = 2.0 / (WIDTH * fr->zoom);
	if (!ft_strncmp(fr->name, "julia", 5))
	{
		fr->z.x = (x - WIDTH / 2.0) * scale + fr->center_x;
		fr->z.y = (y - HEIGHT / 2.0) * scale + fr->center_y;
	}
	else if (!ft_strncmp(fr->name, "mandelbrot", 10))
	{
		fr->c.x = (x - WIDTH / 2.0) * scale + fr->center_x;
		fr->c.y = (y - HEIGHT / 2.0) * scale + fr->center_y;
		fr->z.x = 0;
		fr->z.y = 0;
	}
	else if (!ft_strncmp(fr->name, "bs", 12))
	{
		fr->c.x = (x - WIDTH / 2.0) * scale + fr->center_x;
		fr->c.y = (y - HEIGHT / 2.0) * scale + fr->center_y;
		fr->z.x = 0;
		fr->z.y = 0;
	}
}

void	render_bs(int x, int y, t_fractol *fr)
{
	int		i;
	int		color;
	double	temp_zx;

	start_cords(x, y, fr);
	i = -1;
	while (++i < fr->max_itr)
	{
		temp_zx = fr->z.x * fr->z.x - fr->z.y * fr->z.y + fr->c.x;
		fr->z.y = 2 * fabs(fr->z.x * fr->z.y) + fr->c.y;
		fr->z.x = temp_zx;
		if ((fr->z.x * fr->z.x) + (fr->z.y * fr->z.y) > 4.0)
		{
			color = get_color_bs(i, fr->color_shift);
			mlx_put_pixel(fr->img.img, x, y, color);
			return ;
		}
	}
	mlx_put_pixel(fr -> img.img, x, y, BLACK);
}

void	render_mandel_julia(int x, int y, t_fractol *fr)
{
	int		i;
	int		color;
	double	temp_zx;

	start_cords(x, y, fr);
	i = -1;
	while (++i < fr -> max_itr)
	{
		temp_zx = fr->z.x * fr->z.x - fr->z.y * fr->z.y + fr->c.x;
		fr->z.y = 2 * fr->z.x * fr->z.y + fr->c.y;
		fr->z.x = temp_zx;
		if ((fr->z.x * fr->z.x) + (fr->z.y * fr->z.y) > 4.0)
		{
			color = get_color_mandel_julia(i, fr->color_shift);
			mlx_put_pixel(fr->img.img, x, y, color);
			return ;
		}
	}
	mlx_put_pixel(fr -> img.img, x, y, BLACK);
}

void	draw_fractal(t_fractol *fr)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (!ft_strcmp(fr->name, "bs"))
				render_bs(x, y, fr);
			else
				render_mandel_julia(x, y, fr);
		}
	}
	fr->color_shift = (fr->color_shift + 1) % 15;
	mlx_image_to_window(fr->mlx_init, fr->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	fr;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia"))
		|| (argc == 2 && !ft_strcmp(argv[1], "bs")))
	{
		fr.name = argv[1];
		if (!ft_strcmp(argv[1], "julia"))
		{
			fr.c.x = atodbl(argv[2]);
			fr.c.y = atodbl(argv[3]);
		}
		init_fractal(&fr);
		draw_fractal(&fr);
		mlx_loop(fr.mlx_init);
	}
	else
	{
		error_input();
		exit(EXIT_FAILURE);
	}
	mlx_terminate(fr.mlx_init);
}
