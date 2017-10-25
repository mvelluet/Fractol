/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mike.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:32:40 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:02:50 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mike_next(t_mlx *ap)
{
	double	zoom;

	while (++ap->y2 < HEIGHT)
	{
		zoom = HEIGHT / ap->z;
		ap->c_x = ap->x2 / zoom + ap->x;
		ap->c_y = ap->y2 / zoom + ap->y;
		ap->z_x = 0;
		ap->z_y = 0;
		ap->i = 0;
		ap->tmp = ap->z_x;
		ap->z_x = ((ap->z_x * ap->z_x) - (ap->z_y * ap->z_y) + ap->c_x) - (-3);
		ap->z_y = (((2 * ap->z_y) * ap->tmp) + ap->c_y) * 2;
		ap->i++;
		while ((ap->z_x * ap->z_x + ap->z_y * ap->z_y < 4)
			&& (ap->i < ap->ite_max))
		{
			ap->tmp = ap->z_x;
			ap->z_x = (ap->z_x * ap->z_x) - (ap->z_y * ap->z_y) + ap->c_x;
			ap->z_y = ((2 * ap->z_y) * ap->tmp) + ap->c_y;
			ap->i++;
		}
		ft_put_pixel(ap, ap->y2, ap->x2);
	}
}

void	ft_mike(t_mlx *ap)
{
	ap->x2 = -1;
	while (++ap->x2 < WIDTH)
	{
		ap->y2 = -1;
		ft_mike_next(ap);
	}
}
