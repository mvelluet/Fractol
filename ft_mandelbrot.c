/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:07:17 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:28 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mandelbrot_px(t_mlx *ap, int x2, int y2)
{
	double	zoom;
	double	z_x;
	double	z_y;
	double	c[2];
	double	i;

	zoom = HEIGHT / ap->z;
	c[0] = x2 / zoom + ap->x;
	c[1] = y2 / zoom + ap->y;
	z_x = 0;
	z_y = 0;
	i = 0;
	while (z_x * z_x + z_y * z_y < 4 && i < ap->ite_max)
	{
		double tmp = z_x;
		z_x = z_x * z_x - z_y * z_y + c[0];
		z_y = 2 * z_y * tmp + c[1];
		i++;
	}
	ft_put_pixel_iter(ap, y2, x2, i);
}

void		*ft_mandelbrot_thread(void *arg)
{
	t_thread	*t;
	int			x2;
	int			y2;

	t = (t_thread *)arg;
	x2 = t->x_start - 1;
	while (++x2 < t->x_end)
	{
		y2 = -1;
		while (++y2 < HEIGHT)
			ft_mandelbrot_px(t->ap, x2, y2);
	}
	return (NULL);
}

void		ft_mandelbrot(t_mlx *ap)
{
	pthread_t	threads[NUM_THREADS];
	t_thread	tdata[NUM_THREADS];
	int			j;
	int			band;

	band = WIDTH / NUM_THREADS;
	j = -1;
	while (++j < NUM_THREADS)
	{
		tdata[j].ap = ap;
		tdata[j].x_start = j * band;
		tdata[j].x_end = (j + 1 == NUM_THREADS) ? WIDTH : (j + 1) * band;
		pthread_create(&threads[j], NULL, ft_mandelbrot_thread, &tdata[j]);
	}
	j = -1;
	while (++j < NUM_THREADS)
		pthread_join(threads[j], NULL);
}
