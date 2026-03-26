/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:32:40 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:02:50 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_find_root(double z_x, double z_y)
{
	double	d0;
	double	d1;
	double	d2;

	d0 = (z_x - 1) * (z_x - 1) + z_y * z_y;
	d1 = (z_x + 0.5) * (z_x + 0.5) + (z_y - 0.866025) * (z_y - 0.866025);
	d2 = (z_x + 0.5) * (z_x + 0.5) + (z_y + 0.866025) * (z_y + 0.866025);
	if (d0 < d1 && d0 < d2)
		return (0);
	if (d1 < d2)
		return (1);
	return (2);
}

static void	ft_newton_color(t_mlx *ap, int x, int y, double *info)
{
	unsigned	pos;
	double		bright;
	int			root;

	pos = (unsigned)x * (WIDTH * 4) + (unsigned)y * 4;
	if (y <= 0 || y >= WIDTH || pos == 0 || pos >= (HEIGHT * WIDTH * 4))
		return ;
	root = (int)info[0];
	bright = 1.0 - info[1] / (ap->ite_max * 1.5);
	if (bright < 0.15)
		bright = 0.15;
	ap->img_str[pos] = (char)(root == 2 ? 230 * bright : 30 * bright);
	ap->img_str[pos + 1] = (char)(root == 1 ? 230 * bright : 30 * bright);
	ap->img_str[pos + 2] = (char)(root == 0 ? 230 * bright : 30 * bright);
	ap->img_str[pos + 3] = ap->alpha;
}

static void	ft_newton_px(t_mlx *ap, int x2, int y2)
{
	double	z[2];
	double	denom;
	double	f[2];
	double	i;
	double	info[2];

	z[0] = x2 / (HEIGHT / ap->z) + ap->x;
	z[1] = y2 / (HEIGHT / ap->z) + ap->y;
	i = 0;
	while (i < ap->ite_max)
	{
		f[0] = z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] - 1;
		f[1] = 3 * z[0] * z[0] * z[1] - z[1] * z[1] * z[1];
		denom = 3 * ((z[0] * z[0] - z[1] * z[1]) * (z[0] * z[0] - z[1] * z[1])
				+ 4 * z[0] * z[0] * z[1] * z[1]);
		if (denom < 1e-10)
			break ;
		z[0] -= (f[0] * (z[0] * z[0] - z[1] * z[1])
				+ f[1] * 2 * z[0] * z[1]) / denom;
		z[1] -= (f[1] * (z[0] * z[0] - z[1] * z[1])
				- f[0] * 2 * z[0] * z[1]) / denom;
		if (f[0] * f[0] + f[1] * f[1] < 1e-10)
			break ;
		i++;
	}
	info[0] = ft_find_root(z[0], z[1]);
	info[1] = i;
	ft_newton_color(ap, y2, x2, info);
}

void		*ft_newton_thread(void *arg)
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
			ft_newton_px(t->ap, x2, y2);
	}
	return (NULL);
}

void		ft_newton(t_mlx *ap)
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
		pthread_create(&threads[j], NULL, ft_newton_thread, &tdata[j]);
	}
	j = -1;
	while (++j < NUM_THREADS)
		pthread_join(threads[j], NULL);
}
