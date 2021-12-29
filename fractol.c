/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:51:34 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/29 22:52:11 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	func(int keycode, t_data *obj)
{

	static int x, y;
	printf("%d - %d\n",x,y);
	if (keycode == 53)
		exit(0);
	if (keycode >= 123 && keycode <= 126)
	{
		keycode -= 123;
		if (keycode == 0)
			x--;
		else if (keycode == 1)
			x++;
		else if (keycode == 2)
			y++;
		else
			y--;
	}
	mlx_clear_window(obj->mlx, obj->win);
	mlx_put_image_to_window(obj->mlx, obj->win, obj->img.data, x * obj->img.width, y * obj->img.height);
	return (0);
}
*/
void ft_header()
{
	printf(".::::::::                          .::  .::           .::\n");
	printf(".::                                .::   .:           .::\n");
	printf(".::      .: .:::   .::       .:::.:.: .:      .::     .::\n");
	printf(".::::::   .::    .::  .::  .::     .::      .::  .::  .::\n");
	printf(".::       .::   .::   .:: .::      .::     .::    .:: .::\n");
	printf(".::       .::   .::   .::  .::     .::      .::  .::  .::\n");
	printf(".::      .:::     .:: .:::   .:::   .::       .::    .:::\n");
}

void ft_detect(char *s, t_data *mlx)
{
	if(!ft_strcmp(s,"Mandelbrot"))
	{
		mlx->fractol = 1;
		//	start_mandelbrot();
	}
	if(!ft_strcmp(s,"Julia"))
		mlx->fractol = 2;
	if(!ft_strcmp(s,"Burning ship"))
		mlx->fractol = 3;
}

void ft_usage(void)
{
	printf("Usage: ./fractol <name>\n");
	printf("List of available fractals:\n");
	printf("- Mandelbrot\n");
	printf("- Julia\n");
	printf("- Burning ship\n");
}

int ft_close(int keycode, t_data *x)
{
	exit(0);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data *mlx;
	if (argc == 2)
	{
		//	printf("%d", ft_strcmp(argv[1], "test"));
		//	ft_header();
			ft_usage();
			set2zero(mlx);
			if(!ft_strcmp(argv[1], "Mandelbrot"))
				start_mandelbrot();
			if(!ft_strcmp(argv[1], "Julia"))
				return (0);
			if(!ft_strcmp(argv[1], "Burning ship"))
				return (0);

			//	ft_memset(mlx, 0, sizeof(t_data));
			//	ft_detect(argv[1], mlx);
			//	start_mandelbrot();
	}
	else
	{
		ft_usage();
		start_mandelbrot();
	}
}
