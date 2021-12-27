/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:34:10 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/27 16:07:40 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
# define	FRACTOL_H
#define ITERATIION 500
#define MINX -2
#define MINY -2
#define MAXX 2
#define MAXY 2
#define SIZEX 800
#define SIZEY 800
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_data
{
	void *mlx;
	void *win;
	void *img;
	void *img_addr;
	int bits_per_pixel;
	int size_line;
	int endian;
	int loopx;
	int loopy;
	float xmin;
	float ymin;
	float xmax;
	float ymax;
} t_data;

void	start_mandelbrot(void);
void	mandelbrot(t_data *mlx);
int		mandelbrot_set(float x, float y, t_data *mlx);
void	ft_draw(t_data *mlx, int x, int y, int color);

#endif
