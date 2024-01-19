/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:55 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/19 22:06:14 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_key(struct mlx_key_data key_data, void *param)
{
	t_fractol	*fr;

	fr = (t_fractol *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		handle_close(fr);
	if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		fr->center_x -= 0.05;
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		fr->center_x += 0.05;
	if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
		fr->center_y -= 0.05;
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
		fr->center_y += 0.05;
	if (key_data.key == MLX_KEY_I && key_data.action == MLX_PRESS)
		fr->max_itr += 4;
	if (key_data.key == MLX_KEY_O && key_data.action == MLX_PRESS)
		fr->max_itr -= 4;
	draw_fractal(fr);
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fr;

	(void)xdelta;
	fr = (t_fractol *)param;
	if (ydelta > 0)
		handle_zoom(fr->mlx_init, fr, 1.1);
	else if (ydelta < 0)
		handle_zoom(fr->mlx_init, fr, 0.9);
}

void	handle_zoom(mlx_t *mlx, t_fractol *fr, double zoom_factor)
{
	int32_t	x;
	int32_t	y;
	double	mouse_x;
	double	mouse_y;

	mlx_get_mouse_pos(mlx, &x, &y);
	mouse_x = (x - WIDTH / 2.0) * (2.0 / (WIDTH * fr->zoom)) + fr->center_x;
	mouse_y = (y - HEIGHT / 2.0) * (2.0 / (HEIGHT * fr->zoom)) + fr->center_y;
	fr->zoom *= zoom_factor;
	fr->center_x = mouse_x;
	fr->center_y = mouse_y;
	draw_fractal(fr);
}

void	handle_close(t_fractol *fr)
{
	mlx_delete_image(fr->mlx_init, fr->img.img);
	mlx_close_window(fr->mlx_init);
	free(fr->mlx_init);
	exit(EXIT_SUCCESS);
}
