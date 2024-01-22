/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:42:05 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/22 17:14:19 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH	1024
# define HEIGHT	1024

# define BLACK			0x00000080

# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_img;

typedef struct s_cmplx
{
	double	x;
	double	y;
}	t_cmplx;

typedef struct s_fractol
{
	mlx_t	*mlx_init;
	t_img	img;
	char	*name;
	int		max_itr;
	int		color_shift;
	t_cmplx	z;
	t_cmplx	c;
	double	zoom;
	double	center_x;
	double	center_y;
	double	cursor_x;
	double	cursor_y;
}	t_fractol;

//main functions
int				main(int argc, char **argv);
void			draw_fractal(t_fractol *fractal);
void			start_cords(int x, int y, t_fractol *fractal);
void			render_mandel_julia(int x, int y, t_fractol *fr);
void			render_bs(int x, int y, t_fractol *fr);

//inits
void			init_fractal(t_fractol *fractal);
void			init_struct(t_fractol *fractal);
void			init_events(t_fractol *fractal);

//errors
void			error_malloc(void);
void			error_input(void);

//utils
unsigned int	get_color_mandel_julia(int itr, int shift);
unsigned int	get_color_bs(int itr, int shift);
double			atodbl(char *s);

//events
void			handle_key(struct mlx_key_data key_data, void *param);
void			handle_scroll(double xdelta, double ydelta, void *param);
void			handle_zoom(mlx_t *mlx, t_fractol *fr, double zoom_factor);
void			handle_close(t_fractol *fractal);

#endif