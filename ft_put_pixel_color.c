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

static void		ft_write_color(t_mlx *ap, double r, int pos)
{
	double	b;
	double	g;
	double	rd;

	b = (ap->blue + ap->blue_more) * (0.5 + 0.5 * sin(r * PI));
	g = (ap->green + ap->green_more) * (0.5 + 0.5 * sin(r * PI + 2));
	rd = (ap->red + ap->red_more) * (0.5 + 0.5 * sin(r * PI + 4));
	ap->img_str[pos] = (char)(b > 255 ? 255 : b);
	ap->img_str[pos + 1] = (char)(g > 255 ? 255 : g);
	ap->img_str[pos + 2] = (char)(rd > 255 ? 255 : rd);
	ap->img_str[pos + 3] = ap->alpha;
}

void			ft_put_pixel_iter(t_mlx *ap, int x, int y, double iter)
{
	unsigned	pos;
	double		r;

	pos = (unsigned)x * (WIDTH * 4) + (unsigned)y * 4;
	if (y <= 0 || y >= WIDTH || pos == 0 || pos >= (HEIGHT * WIDTH * 4))
		return ;
	if (iter >= ap->ite_max)
	{
		ap->img_str[pos] = 0;
		ap->img_str[pos + 1] = 0;
		ap->img_str[pos + 2] = 0;
		ap->img_str[pos + 3] = ap->alpha;
	}
	else
	{
		r = iter / ap->ite_max;
		ft_write_color(ap, r, pos);
	}
}
