/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:27 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/30 20:05:04 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	burning_set(double x, double y, t_data *mlx)
{
	int		i;
	double	zx;
	double	zy;
	double	tmp;

	zx = 0;
	zy = 0;
	i = 1;
	while (i < ITERATION)
	{
		tmp = zx;
		zx = ((zx * zx) - (zy * zy)) - x;
		zy = fabs(2 * tmp * zy) - y;
		if ((zx * zx) + (zy * zy) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy,
				(mlx->color) + 0x00ABCDEF * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy, 0);
	return (0);
}

int	burning(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			burning_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (3);
}

void	start_burning(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol - Burning Ship");
	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	mlx.color = 0;
	mlx.fractol = 3;
	burning((void *)&mlx);
	mlx_key_hook(mlx.win, keys, (void *)&mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, (void *)0);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 15, 10, 0x001B273C, "Burning Ship");
	mlx_loop(mlx.mlx);
}
