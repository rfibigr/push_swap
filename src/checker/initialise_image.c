/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:01:40 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 19:33:28 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_mlx	ft_initialise(void)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.name = mlx_new_window(mlx.init, SCREEN_X, SCREEN_Y, "Checker Visualizer");
	return (mlx);
}

void	trace_border(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < IMG_X)
		fill_pixel(&mlx->str, i++, 0, 0xFFFFFF);
	i = 0;
	while (i < IMG_Y)
		fill_pixel(&mlx->str, 1000, i++, 0xFFFFFF);
	mlx_string_put(mlx->init, mlx->name,500,40, 0xFFFFFF, "PILE A");
	mlx_string_put(mlx->init, mlx->name,1500,40, 0xFFFFFF, "PILE B");
}

void	fill_pixel(char **img_str, int x, int y, unsigned long color)
{
	int		i;
	char	red;
	char	green;
	char	blue;

	i = 0;
	red = color >> 16;
	green = (color & 0x00ff00) >> 8;
	blue = color & 0x0000ff;
	i = (x * 4) + (y * IMG_X * 4);
	(*img_str)[i] = red;
	(*img_str)[i + 1] = green;
	(*img_str)[i + 1] = blue;
}

void	fill_line(char **img_str, int x, int y, unsigned long color, int len)
{
	int	i;


	i = x;
	while (len > 0)
	{
		fill_pixel(img_str, i, y, color);
		i++;
		len--;
	}
}
