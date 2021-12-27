/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:01:14 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/27 16:09:14 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_data *mlx, int x, int y, int color)
{
	char *data;
	int pos;
	pos = (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	data = mlx->img_addr + pos;
	*(unsigned int *)data = color;
}
