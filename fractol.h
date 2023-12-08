/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:42:05 by fwahl             #+#    #+#             */
/*   Updated: 2023/12/08 17:46:03 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH	1024
# define HEIGHT	1024
// # define BLACK	0x000000
// # define WHITE	0xFFFFFF
// # define RED	0xFF0000
// # define GREEN	0x00FF00
// # define BLUE	0x0000FF
# define C1		0x000764
# define C2		0x0C2F8D
# define C3		0x1957B6
# define C4		0x387CD1
# define C5		0x69A0DD
# define C6		0x9AC3EA
# define C7		0xCBE6F6
# define C8		0xEEF7E8
# define C9		0xF3DFA1
# define C10	0xF8C759
# define C11	0xFDAF11
# define C12	0xC78500
# define C13	0x7D5400
# define C14	0x332300
# define C15	0x000000


# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
// # include "MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
} t_img;

typedef struct s_cmplx
{
	double	x;
	double	y;
}	t_cmplx;

typedef struct s_fractol
{
	void	*mlx_init;
	t_img	img;
	char	*name;
	int		max_itr;
	t_cmplx	z;
	t_cmplx	c;
	double	div_val;
	double	zoom;
	double	center_x;
	double	center_y;
	double	julia_x;
	double	julia_y;
	// double	mouse_x;
	// double	mouse_y;
} t_fractol;

//main functions
int				main(int argc, char **argv);
void			draw_fractal(t_fractol *fractal);
void			draw_pixel(int x, int y, t_fractol *fractal);

//inits
void			init_fractal(t_fractol *fractal);
void			init_struct(t_fractol *fractal);
void			init_events(t_fractol *fractal);

//errors
void			error_malloc(void);
void			error_input(t_fractol *fractal);

//utils
t_cmplx			sum_cmplx(t_cmplx z1, t_cmplx z2);
t_cmplx			square_cmplx(t_cmplx z);
unsigned int 	get_color(int itr);
double			atodbl(char *s);

//events
void			handle_key(struct mlx_key_data key_data, void *param);
void			handle_scroll(double xdelta, double ydelta, void *param);
void			handle_close(t_fractol *fractal);
// void			handle_mouse_pos(double x, double y, void *param);

#endif