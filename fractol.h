/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:34:10 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/29 22:54:07 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
# define	FRACTOL_H
#define ITERATION 200
#define MINX -2
#define MINY -2
#define MAXX 2
#define MAXY 2
#define SIZEX 700
#define SIZEY 700
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_data
{
	void *mlx;
	void *win;
	int loopx;
	int loopy;
	float xmin;
	float ymin;
	float xmax;
	float ymax;
	int color;
	int fractol;
} t_data;

void	start_mandelbrot(void);
int		mandelbrot(t_data *mlx);
int		mandelbrot_set(float x, float y, t_data *mlx);
int		keys(int keycode, t_data *vars);
int		endian_detect(void);
int		zoom(int keycode, int x, int y, t_data *mlx);
void 	set2zero(t_data *mlx);
#endif
