/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 02:12:28 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 04:58:34 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define HEIGHT 600
# define WIDTH 600
# define PI 3.1415926535898

typedef struct		s_mlx
{
	char			*img_str;
	char			*name;
	void			*mlx;
	void			*win;
	void			*ptr_img;
	int				height;
	int				width;
	int				alpha;
	int				nb;
	double			red;
	double			green;
	double			blue;
	double			red_more;
	double			green_more;
	double			blue_more;
	double			c_x;
	double			c_y;
	double			c_x_init;
	double			c_y_init;
	double			j_y;
	double			j_x;
	double			z_x;
	double			z_y;
	double			x;
	double			y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			diff_x;
	double			diff_y;
	double			z;
	double			z_init;
	double			i;
	double			ite_max;
	double			zoom;
	double			zoom_x;
	double			zoom_x_init;
	double			zoom_y;
	double			zoom_y_init;
	double			tmp;
	double			h;
}					t_mlx;

int					ft_verif_arg(int argc, char **argv, t_mlx *ap);
void				ft_initialisation_mandelbrot(t_mlx *ap);
void				ft_initialisation_julia(t_mlx *ap);
void				ft_initialisation_mike(t_mlx *ap);
void				ft_initialisation(t_mlx *ap, int nb);
void				ft_choice_of_color(t_mlx *ap, double r, int pos);
void				ft_put_pixel(t_mlx *ap, int x, int y);
void				ft_mandelbrot_next(t_mlx *ap);
void				ft_mandelbrot(t_mlx *ap);
void				ft_julia_next(t_mlx *ap);
void				ft_julia(t_mlx *ap);
void				ft_mike_next(t_mlx *ap);
void				ft_mike(t_mlx *ap);
int					ft_key_event(int keycode, t_mlx *ap);
void				ft_change_color(int keycode, t_mlx *ap);
void				ft_change_ite(int keycode, t_mlx *ap);
void				ft_deplacement(int keycode, t_mlx *ap);
void				ft_reset(int keycode, t_mlx *ap);
void				ft_print_image(t_mlx *ap);
int					ft_mouse_pointer(int x, int y, t_mlx *ap);
void				ft_zoom_mouse(int keycode, int x, int y, t_mlx *ap);
int					ft_mouse_event(int button, int x, int y, t_mlx *ap);

#endif
