/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:01:14 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/30 16:28:55 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int     ft_strcmp(char *s1, char *s2)
{
        unsigned int    i;

        i = 0;
        while (s2[i] && s1[i] && s1[i] == s2[i])
                i++;
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
	}
    if(keycode == 126 || keycode == 125)
	{
		if(keycode == 125)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
	}
	if (keycode == 8)
		mlx->color += 0x00321123;
    if (keycode == 1)
        mlx->juliay += 0.2;
    if (keycode == 13)
        mlx->juliay -= 0.2;
    if(keycode == 0)
        mlx->juliax -= 0.2;
    if (keycode == 2)
        mlx->juliax += 0.2;
    ft_run(mlx , 1);
	return 0;
}
int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float dx;
	float dy;

	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
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
	ft_run(mlx,1);
	return (0);
}
