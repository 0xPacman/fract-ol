/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:01:14 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/29 22:05:04 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((char *)s)[n] = c;
	return (s);
}

void set2zero(t_data *mlx)
{

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx->xmin = 0;
	mlx->ymin = 0;
	mlx->xmax = 0;
	mlx->ymax = 0;
	mlx->color = 0;
	mlx->fractol = 0;
}

void	ft_draw(t_data *mlx, int x, int y, int color)
{
	mlx_pixel_put(mlx -> mlx, mlx -> win, x, y, color);
}

int	keys(int keycode, t_data *mlx)
{
	float dx;
	float dy;

	dx = (mlx->xmax - mlx->xmin);
	dy = (mlx->ymax - mlx->ymin);
	if (keycode == 53)
		exit(0);
	if(keycode == 123 || keycode == 124)
	{
		if(keycode == 123)
			dx *= -1;
		mlx->xmin += dx / 7.5;
		mlx->xmax += dx / 7.5;
		mandelbrot(mlx);
	}
	if(keycode == 126 || keycode == 125)
	{
		if(keycode == 126)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
		mandelbrot(mlx);
	}
	if (keycode == 8)
	{
		mlx->color += 0x00321123;
		//	mlx_destroy_window(mlx, mlx->win);
		mandelbrot(mlx);
	}
	printf("you clicked %d!\n", keycode);
	return 0;
}
int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float dx;
	float dy;

	printf("keycode:%d - x:%d - y:%d\n",keycode,x,y);
	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
	printf("dx:%f  / dy:%f\n", dx,dy);
	if (keycode == 1)
	{
		mlx->xmin = (mlx->xmin + ((dx * x) * 0.5));
		mlx->xmax = (mlx->xmax - ((dx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax - ((dy * y) * 0.5));
		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - y))  * 0.5));
	}
	if (keycode == 2)
	{
		mlx->xmin = (mlx->xmin - ((dx * x) * 0.5));
		mlx->xmax = (mlx->xmax + ((dx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax + ((dy * y) * 0.5));
		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - y))  * 0.5));
	}

	mandelbrot(mlx);
	return (0);
}

int	endian_detect(void)
{
	short int word;
	char *b;
	word = 0x001;
	b = (char *)&word;
	if (b[0])
		return (0);
	else
		return (1);
}
