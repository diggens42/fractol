/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:55 by fwahl             #+#    #+#             */
/*   Updated: 2023/12/08 16:56:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_key(struct mlx_key_data key_data, void *param)
{
	t_fractol *fractal;

	fractal = (t_fractol *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		handle_close(fractal);
	if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		fractal -> center_x -= 0.1;
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		fractal -> center_x += 0.1;
	if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
		fractal -> center_y -= 0.1;
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
		fractal -> center_y += 0.1;
	if (key_data.key == MLX_KEY_I && key_data.action == MLX_PRESS)
		fractal -> max_itr += 10;
	if (key_data.key == MLX_KEY_O && key_data.action == MLX_PRESS)
		fractal -> max_itr -= 10;
	draw_fractal(fractal);

	
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol *fractal;
	// double	m_x;
	// double	m_y;
	// double	old_zoom;

	fractal = (t_fractol *)param;
	// old_zoom = fractal -> zoom;
	if (ydelta > 0)
		fractal -> zoom *= 1.1;
	else if (ydelta < 0)
		fractal -> zoom *= 0.9;
	// m_x = (fractal -> mouse_x - WIDTH / 2.0) * old_zoom + fractal -> center_x;
	// m_y = (fractal -> mouse_y - WIDTH / 2.0) * old_zoom + fractal -> center_y;
	// fractal -> center_x = m_x - (fractal -> mouse_x - WIDTH / 2) * fractal -> zoom;
	// fractal -> center_y = m_y - (fractal -> mouse_y - WIDTH / 2) * fractal -> zoom;
	draw_fractal(fractal);
}

// void	handle_mouse_pos(double x, double y, void *param)
// {
// 	t_fractol *fractal;

// 	fractal = (t_fractol *)param;
// 	fractal -> mouse_x = x;
// 	fractal -> mouse_y = y;
// }

void	handle_close(t_fractol *fractal)
{
	mlx_delete_image(fractal -> mlx_init, fractal -> img.img);
	mlx_close_window(fractal -> mlx_init);
	free(fractal -> mlx_init);
	exit(EXIT_SUCCESS);
}