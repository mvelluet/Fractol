/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:04:43 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:50 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initialisation_mandelbrot(t_mlx *ap)
{
	ap->c_x = 0;
	ap->c_y = 0;
	ap->z_x = 0;
	ap->z_y = 0;
	ap->i = 0;
	ap->ite_max = 50;
	ap->x = -2.2;
	ap->y = -1.4;
	ap->z = 2.8;
	ap->z_init = ap->z;
	ap->zoom = 1.0;
	ap->tmp = 0;
}

void	ft_initialisation_julia(t_mlx *ap)
{
	ap->c_x = 0.285;
	ap->c_y = 0.013;
	ap->c_x_init = ap->c_x;
	ap->c_y_init = ap->c_y;
	ap->j_x = ap->c_x;
	ap->j_y = ap->c_y;
	ap->z_x = 0;
	ap->z_y = 0;
	ap->i = 0;
	ap->ite_max = 100;
	ap->x = -1.4;
	ap->y = -1.4;
	ap->z = 2.8;
	ap->z_init = ap->z;
	ap->zoom = 1.0;
	ap->tmp = 0;
}

void	ft_initialisation_mike(t_mlx *ap)
{
	ap->c_x = 0;
	ap->c_y = 0;
	ap->z_x = 0;
	ap->z_y = 0;
	ap->i = 0;
	ap->ite_max = 50;
	ap->x = -2.5;
	ap->y = -0.7;
	ap->z = 1.4;
	ap->z_init = ap->z;
	ap->zoom = 1.0;
	ap->tmp = 0;
	ap->nb = 1;
}

void	ft_initialisation(t_mlx *ap, int nb)
{
	int	bpp;
	int	s_l;
	int	end;

	if (nb == 0)
	{
		ap->mlx = mlx_init();
		ap->height = HEIGHT;
		ap->width = WIDTH;
		ap->win = mlx_new_window(ap->mlx, ap->width, ap->height, "Fractol");
		ap->ptr_img = mlx_new_image(ap->mlx, ap->width, ap->height);
		ap->img_str = mlx_get_data_addr(ap->ptr_img, &(bpp), &(s_l), &(end));
	}
	ap->red_more = 192;
	ap->green_more = 57;
	ap->blue_more = 43;
	ap->alpha = 0;
}
