/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controleur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:34:05 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:52 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_image(t_mlx *ap)
{
	int	bpp;
	int	s_l;
	int	endian;

	mlx_destroy_image(ap->mlx, ap->ptr_img);
	ap->ptr_img = mlx_new_image(ap->mlx, ap->width, ap->height);
	ap->img_str = mlx_get_data_addr(ap->ptr_img, &(bpp), &(s_l), &(endian));
	if (ft_strcmp(ap->name, "Mandelbrot") == 0)
		ft_mandelbrot(ap);
	else if (ft_strcmp(ap->name, "Julia") == 0)
		ft_julia(ap);
	else if (ft_strcmp(ap->name, "Mike") == 0)
		ft_mike(ap);
	mlx_put_image_to_window(ap->mlx, ap->win, ap->ptr_img, 0, 0);
}
