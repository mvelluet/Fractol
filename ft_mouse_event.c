/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:39:18 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:03:44 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mouse_pointer(int x, int y, t_mlx *ap)
{
	ap->j_x = ap->c_x_init + (((float)x - HEIGHT / 2) / 1000);
	ap->j_y = ap->c_y_init + (((float)y - WIDTH / 2) / 1000);
	ft_print_image(ap);
	return (0);
}

void		ft_zoom(t_mlx *ap, int x, int y, int keycode)
{
	double	xscale;
	double	yscale;
	double	ztemp;
	double	xtemp;
	double	ytemp;

	ztemp = ap->z;
	xtemp = ap->x;
	ytemp = ap->y;
	if (keycode == 1 || keycode == 4)
		ap->zoom *= 1.1;
	else if (keycode == 2 || keycode == 5)
		ap->zoom /= 1.1;
	ap->z = ap->z_init / ap->zoom;
	ap->x += (ztemp - ap->z) / 2;
	ap->y += (ztemp - ap->z) / 2;
	xscale = ap->z / WIDTH;
	yscale = ap->z / HEIGHT;
	x = (x - WIDTH / 2);
	y = (y - HEIGHT / 2);
	ap->x += (x * (ztemp / WIDTH)) - (x * xscale);
	ap->y += (y * (ztemp / HEIGHT)) - (y * yscale);
}

void		ft_zoom_mouse(int keycode, int x, int y, t_mlx *ap)
{
	if (keycode == 1 || keycode == 4)
	{
		ft_zoom(ap, x, y, keycode);
		ap->ite_max += 1;
	}
	if (keycode == 2 || keycode == 5)
	{
		ft_zoom(ap, x, y, keycode);
		ap->ite_max -= 1;
	}
}

int			ft_mouse_event(int button, int x, int y, t_mlx *ap)
{
	ft_zoom_mouse(button, x, y, ap);
	ft_print_image(ap);
	return (button);
}
