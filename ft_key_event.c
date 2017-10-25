/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:35:11 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:41 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_reset(int keycode, t_mlx *ap)
{
	if (keycode == 82)
	{
		ft_initialisation(ap, 1);
		if (ft_strcmp(ap->name, "Mandelbrot") == 0)
			ft_initialisation_mandelbrot(ap);
		if (ft_strcmp(ap->name, "Julia") == 0)
			ft_initialisation_julia(ap);
		if (ft_strcmp(ap->name, "Mike") == 0)
			ft_initialisation_mike(ap);
		ft_print_image(ap);
	}
}

void		ft_deplacement(int keycode, t_mlx *ap)
{
	double	ratio;

	ratio = 0.1 / ap->zoom;
	if (keycode == 125)
		ap->y += ratio;
	if (keycode == 126)
		ap->y -= ratio;
	if (keycode == 124)
		ap->x += ratio;
	if (keycode == 123)
		ap->x -= ratio;
}

void		ft_change_ite(int keycode, t_mlx *ap)
{
	if (keycode == 69)
		ap->ite_max += 1;
	if (ap->ite_max > 50)
	{
		if (keycode == 78)
			ap->ite_max -= 1;
	}
}

void		ft_change_color(int keycode, t_mlx *ap)
{
	if (keycode == 43)
	{
		ap->red_more -= 10;
		ap->green_more -= 10;
		ap->blue_more -= 10;
	}
	else if (keycode == 47)
	{
		ap->red_more += 10;
		ap->green_more += 10;
		ap->blue_more += 10;
	}
	else if (keycode == 15)
		ap->red_more -= 10;
	else if (keycode == 11)
		ap->blue_more -= 10;
	else if (keycode == 5)
		ap->green_more -= 10;
}

int			ft_key_event(int keycode, t_mlx *ap)
{
	if (keycode == 69 || keycode == 78)
		ft_change_ite(keycode, ap);
	if (keycode >= 123 || keycode <= 126)
		ft_deplacement(keycode, ap);
	if (keycode == 43 || keycode == 47 || keycode == 15 || keycode == 5
		|| keycode == 11)
		ft_change_color(keycode, ap);
	if (keycode == 82)
		ft_reset(keycode, ap);
	if (keycode == 53)
		exit(-1);
	ft_print_image(ap);
	return (keycode);
}
