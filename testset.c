/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:27 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/28 19:01:39 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_set(float x, float y, t_data *mlx)
{
    int i;
    float xx;
    float yy;
//	int x2;
//	int y2;
    float temp;

    xx = 0;
    yy = 0;
    i = 1;
//	x2 = ((int)x>>11);
//	y2 = ((int)y>>11);
    while (i < ITERATION)
        {
            temp = xx;
            xx = ((xx * xx) - (yy * yy)) + x;
            yy = (2 * temp * yy) + y;
            if ((xx * xx) + (yy * yy) > 4)
                {
                    ft_draw(mlx, mlx->loopx, mlx->loopy, /*(mlx->color) %*/ 0x008DE3EC * i);
                    return (0);
                }
            //            printf("%f %f\n%d iter\n", x,y,i);
            i++;
        }
	ft_draw(mlx, mlx->loopx, mlx->loopy, 0x000E0E0E);
	return (0);
}

void mandelbrot(t_data *mlx)
{
	float x;
	float y;
	mlx->img = mlx_new_image(mlx->mlx, SIZEX, SIZEY);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	mlx->loopx = 0;
	mlx->loopy = 0;
	int i = 0;
	while(i < 3){
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
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	//mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

void start_mandelbrot(void)
{
	t_data *mlx;
	mlx = (t_data *)malloc(sizeof (t_data));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SIZEX, SIZEY, "Fract'ol - Mandelbrot");
	mlx->xmin = MINX;
    mlx->xmax = MAXX;
	mlx->ymin = MINY;
	mlx->ymax = MAXY;
	mlx->endian = endian_detect();
	mlx_key_hook(mlx->win, keys, &mlx);
	mandelbrot(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 15, 10, 0x000E0E0E, "Mandelbrot");
	mlx_loop(mlx->mlx);
}
