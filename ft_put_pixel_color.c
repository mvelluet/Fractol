/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:06:45 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:05 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_choice_of_color(t_mlx *ap, double r, int pos)
{
	if (ap->i == ap->ite_max)
	{
		ap->blue = 0;
		ap->green = 0;
		ap->red = 0;
		ap->img_str[pos] = ap->blue;
		ap->img_str[pos + 1] = ap->green;
		ap->img_str[pos + 2] = ap->red;
		ap->img_str[pos + 3] = ap->alpha;
	}
	else
	{
		ap->img_str[pos] = (ap->blue + ap->blue_more) * r * 15;
		ap->img_str[pos + 1] = (ap->green + ap->green_more) * r * 10;
		ap->img_str[pos + 2] = (ap->red + ap->red_more) * r * 5;
		ap->img_str[pos + 3] = ap->alpha;
	}
}

void			ft_put_pixel(t_mlx *ap, int x, int y)
{
	unsigned	pos_x;
	unsigned	pos_y;
	unsigned	pos;
	double		r;

	pos_x = (unsigned)x * (WIDTH * 4);
	pos_y = (unsigned)y * 4;
	r = ap->i / 70;
	if (y > 0 && y < WIDTH)
	{
		pos = pos_x + pos_y;
		if (pos > 0 && pos < (HEIGHT * WIDTH * 4))
			ft_choice_of_color(ap, r, pos);
	}
}
