/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:51:34 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/27 16:20:37 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
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

int ft_detect(char *s)
{
	if(!ft_strcmp(s,"Mandelbrot"))
		return (1);
	if(!ft_strcmp(s,"Julia"))
		return (2);
	if(!ft_strcmp(s,"Burning ship"))
		return(3);
	return (0);
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
//	printf("%d\n",keycode);

//	mlx_destroy_window(x->mlx, x->win);
	exit(0);
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
//		printf("%d",ft_detect(argv[1]));
		ft_header();
		ft_usage();
		/*	t_obj x;
		int xp = 0;
		int yp = 0; */
		start_mandelbrot();
/*		x.mlx = mlx_init();
		x.win = mlx_new_window(x.mlx, 800, 800, "Fract'ol");

*/
		/*
		  x.img.data = mlx_xpm_file_to_image(x.mlx, "./simple.xpm", &x.img.width, &x.img.height);
		  mlx_put_image_to_window(x.mlx, x.win, x.img.data, 0 , 0);
		  mlx_put_string();
		  mlx_mouse_get_pos(x.win, &xp, &yp);
		  printf("mouse: %d - %d/n", xp, yp);
		  mlx_hook(x.win, 2, 0, func, &x);


		mlx_hook(x.win, 2, 1L<<0, ft_close, &x);
		mlx_hook(x.win, 17, 1L<<17, ft_close, &x);
		mlx_loop(x.mlx);
		*/
	}
	else
	{
		ft_usage();
		start_mandelbrot();
	}
}
