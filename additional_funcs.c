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
	//if(keycode == 123 || keycode == 124) //for macos
    if(keycode == 65361 || keycode == 65362) //for linux
        {
		if(keycode == 65361)
			dx *= -1;
		mlx->xmin += dx / 7.5;
		mlx->xmax += dx / 7.5;
	}
    //	if(keycode == 126 || keycode == 125) //for macos
    if(keycode == 65362 || keycode == 65364) //for linux
	{
		if(keycode == 65362)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
	}
    //	if (keycode == 8) //for macos
    if (keycode == 99) //for linux
	{
		mlx->color += 0x00321123;
	}
    if (keycode == 119)
        mlx->juliay += 0.2;
    if (keycode == 115)
        mlx->juliay -= 0.2;
    if(keycode == 97)
        mlx->juliax -= 0.2;
    if (keycode == 100)
        mlx->juliax += 0.2;
    ft_run(mlx,1);
	printf("you clicked %d!\n", keycode);
	return 0;
}
int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float dx;
	float dy;

    //	printf("keycode:%d - x:%d - y:%d\n",keycode,x,y);
	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
    //	printf("dx:%f  / dy:%f\n", dx,dy);
	if (keycode == 1)
	{
		mlx->xmin = (mlx->xmin + ((dx * x) * 0.5));
		mlx->xmax = (mlx->xmax - ((dx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax - ((dy * y) * 0.5));
		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - y))  * 0.5));
	}
	//if (keycode == 2) // for macos
    if (keycode == 3) // for linux
	{
		mlx->xmin = (mlx->xmin - ((dx * x) * 0.5));
		mlx->xmax = (mlx->xmax + ((dx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax + ((dy * y) * 0.5));
		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - y))  * 0.5));
	}
	ft_run(mlx,1);
	return (0);
}
