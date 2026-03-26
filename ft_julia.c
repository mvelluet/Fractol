/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:32:31 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:45 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_julia_px(t_mlx *ap, int x2, int y2)
{
	double	zoom;
	double	z_x;
	double	z_y;
	double	tmp;
	double	i;

	zoom = HEIGHT / ap->z;
	z_x = x2 / zoom + ap->x;
	z_y = y2 / zoom + ap->y;
	i = 0;
	while (z_x * z_x + z_y * z_y < 4 && i < ap->ite_max)
	{
		tmp = z_x;
		z_x = z_x * z_x - z_y * z_y + ap->j_x;
		z_y = 2 * z_y * tmp + ap->j_y;
		i++;
	}
	ft_put_pixel_iter(ap, y2, x2, i);
}

void		*ft_julia_thread(void *arg)
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
			ft_julia_px(t->ap, x2, y2);
	}
	return (NULL);
}

void		ft_julia(t_mlx *ap)
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
		pthread_create(&threads[j], NULL, ft_julia_thread, &tdata[j]);
	}
	j = -1;
	while (++j < NUM_THREADS)
		pthread_join(threads[j], NULL);
}
