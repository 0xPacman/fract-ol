/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:51:34 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/30 16:25:57 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void ft_header()
{
	printf(".::::::::                          .::  .::           .::\n");
	printf(".::                                .::   .:           .::\n");
	printf(".::      .: .:::   .::       .:::.:.: .:      .::     .::\n");
	printf(".::::::   .::    .::  .::  .::     .::      .::  .::  .::\n");
	printf(".::       .::   .::   .:: .::      .::     .::    .:: .::\n");
	printf(".::       .::   .::   .::  .::     .::      .::  .::  .::\n");
	printf(".::      .:::     .:: .:::   .:::   .::       .::    .:::\n\n");
}

void ft_run(t_data *mlx, int flag)
{
	static int i;

	if(mlx->fractol == 1 || i == 1)
        {
			i = 1;
            if(flag)
                mandelbrot(mlx);
            else
                start_mandelbrot();
        }
	if(mlx->fractol == 2 || i == 2)
		{
			i = 2;
            if (flag)
                julia(mlx);
            else
                start_julia();
        }
	if(mlx->fractol == 3 || i == 3)
        {
            i = 3;
            if (flag)
                burning(mlx);
            else
                start_burning();
        }
}

void ft_usage(int flag)
{
    if (flag)
        printf(".:: Usage: ./fractol <name> ::.\n");
	printf(".:: List of available fractals ::.\n");
	printf("::: - Mandelbrot               :::\n");
	printf("::: - Julia                    :::\n");
	printf("::: - Burning ship             :::\n\n");
}

void	ft_how_to_use(void)
{
    printf(".::        Keys to use       ::.\n");
    printf(":::  Left Click: to zoom in  :::\n");
    printf("::: Right Click: to zoom out :::\n");
    printf(":::    C: to change colors   :::\n");
    printf(":::W,A,S,D: for Julia to move:::\n\n");
}

int main(int argc, char *argv[])
{
	t_data mlx;
	if (argc == 2)
	{
			ft_header();
			ft_usage(0);
            ft_how_to_use();
			if(!ft_strcmp(argv[1], "Mandelbrot"))
                mlx.fractol = 1;
			if(!ft_strcmp(argv[1], "Julia"))
				mlx.fractol = 2;
            if(!ft_strcmp(argv[1], "Burning ship"))
                mlx.fractol = 3;
            ft_run((void *)&mlx, 0);
	}
	else
	{
		printf(".::: Invalid Argument! :::.\n");
		ft_usage(1);
	}
}
