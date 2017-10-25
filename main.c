/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 11:49:43 by mvelluet          #+#    #+#             */
/*   Updated: 2017/05/05 05:04:19 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_verif_arg(int argc, char **argv, t_mlx *ap)
{
	if (argc != 2)
		return (1);
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		ft_initialisation_mandelbrot(ap);
		return (0);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		ft_initialisation_julia(ap);
		return (0);
	}
	else if (ft_strcmp(argv[1], "Mike") == 0)
	{
		ft_initialisation_mike(ap);
		return (0);
	}
	else
		return (1);
	return (0);
}

int			ft_leave(void *param)
{
	if (param)
		exit(-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	ap;

	if (ft_verif_arg(argc, argv, &ap) == 1)
	{
		ft_putstr("Mandelbrot - Julia - Mike\n");
		return (0);
	}
	ft_initialisation(&ap, 0);
	ap.name = argv[1];
	if (ft_strcmp(ap.name, "Mandelbrot") == 0)
		ft_mandelbrot(&ap);
	if (ft_strcmp(ap.name, "Julia") == 0)
		ft_julia(&ap);
	if (ft_strcmp(ap.name, "Mike") == 0)
		ft_mike(&ap);
	mlx_put_image_to_window(ap.mlx, ap.win, ap.ptr_img, 0, 0);
	mlx_mouse_hook(ap.win, ft_mouse_event, &ap);
	if (ft_strcmp(ap.name, "Julia") == 0)
		mlx_hook(ap.win, 6, (1L << 6), ft_mouse_pointer, &ap);
	mlx_hook(ap.win, 2, (1L << 0), ft_key_event, &ap);
	mlx_hook(ap.win, 17, (1L << 17), ft_leave, &ap);
	mlx_loop(ap.mlx);
	return (0);
}
