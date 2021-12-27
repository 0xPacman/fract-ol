/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:45:27 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/27 16:26:04 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_set(float x, float y, t_data *mlx)
{
	ft_draw(mlx, mlx->loopx, mlx->loopy, 0);
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
	while (mlx->loopy <= SIZEY)
	{
		while (mlx->loopx <= SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * (mlx->xmax - mlx->xmin) / SIZEX);
			y = mlx->ymax - (mlx->loopy * (mlx->ymax - mlx->ymin) / SIZEY);
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}
int key(int keycode, t_data *vars)
{
	printf("you clicked %d!\n", keycode);
	return 0;
}
void start_mandelbrot(void)
{
	t_data *mlx;
	mlx = (t_data *)malloc(sizeof (t_data));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SIZEX, SIZEY, "Fract'ol - Mandelbrot");
	mlx->xmin = MINX;
	mlx->ymin = MINY;
	mlx->xmax = MAXX;
	mlx->ymax = MAXY;
	//mlx_key_hook(mlx->win, key, &mlx);
	mandelbrot(mlx);
	mlx_loop(mlx->mlx);
}
