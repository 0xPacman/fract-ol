/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:34:10 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/30 16:24:53 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
# define	FRACTOL_H
#define 	ITERATION 60
#define 	MINX -2
#define 	MINY -2
#define 	MAXX 2
#define 	MAXY 2
#define 	SIZEX 700
#define 	SIZEY 700
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct s_data
{
	void *mlx;
	void *win;
	int loopx;
	int loopy;
	double xmin;
	double ymin;
	double xmax;
	double ymax;
    double juliax;
    double juliay;
	int color;
	int fractol;
} t_data;

void	ft_run(t_data *mlx, int flag);
void	start_mandelbrot(void);
int		mandelbrot(t_data *mlx);
int		mandelbrot_set(double x, double y, t_data *mlx);
void	start_julia(void);
int		julia(t_data *mlx);
int		julia_set(double x, double y, t_data *mlx);
void	start_burning(void);
int		burning(t_data *mlx);
int		burning_set(double x, double y, t_data *mlx);
int		keys(int keycode, t_data *vars);
int		zoom(int keycode, int x, int y, t_data *mlx);
int     ft_strcmp(char *s1, char *s2);

#endif
