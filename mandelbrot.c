/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:27 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/29 22:04:45 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_set(float x, float y, t_data *mlx)
{
    int i;
    float xx;
    float yy;
    float temp;

    xx = 0;
    yy = 0;
    i = 1;
    while (i < ITERATION)
        {
            temp = xx;
            xx = ((xx * xx) - (yy * yy)) + x;
            yy = (2 * temp * yy) + y;
            if ((xx * xx) + (yy * yy) > 4)
                {
					mlx_pixel_put(mlx -> mlx, mlx -> win, mlx->loopx, mlx->loopy, (mlx->color)+0x008DE3EC * i);
                    return (0);
                }
            i++;
        }
	mlx_pixel_put(mlx -> mlx, mlx -> win, mlx->loopx, mlx->loopy, 0x000E0E0E);
	return (0);
}

int mandelbrot(t_data *mlx)
{
	float x;
	float y;
	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (0);
}

void start_mandelbrot(void)
{
	t_data mlx;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol - Mandelbrot");
	mlx.xmin = MINX;
    mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	mandelbrot((void *)&mlx);
	mlx_key_hook(mlx.win, keys, (void *)&mlx);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 15, 10, 0x001B273C, "Mandelbrot");
	mlx_loop(mlx.mlx);
}
