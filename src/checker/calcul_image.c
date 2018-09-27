/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:22:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/27 17:40:58 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_coord define_x_y_ratio(t_pile *list_a)
{
	t_pile	*tmp;
	t_coord	coord;

	tmp = list_a->next;
	coord.min = list_a->data;
	coord.max = list_a->data;
	coord.len_pile = 1;
	while (tmp != list_a)
	{
		if (tmp->data < coord.min)
			coord.min = tmp->data;
		if (tmp->data > coord.max)
			coord.max = tmp->data;
		tmp = tmp->next;
		coord.len_pile++;
	}
	coord.y = (IMG_Y - 1) / (coord.len_pile);
	if (v_abs(coord.max) > v_abs(coord.min))
		coord.x = ((IMG_X / 4) / v_abs(coord.max));
	else
		coord.x = ((IMG_X / 4) / v_abs(coord.min));
	return (coord);
}

void	draw_pile_image(t_pile *pile_a, t_pile *pile_b, t_coord coord, t_mlx *mlx)
{
	ft_bzero(mlx->str, (IMG_X * IMG_Y) * 4);
	trace_border(mlx);
	add_pile(pile_a, coord, mlx, 1);
	add_pile(pile_b, coord, mlx, 3);
	mlx_put_image_to_window(mlx->init, mlx->name, mlx->image, 0, 100);
}

void	add_pile(t_pile *pile, t_coord coord, t_mlx *mlx, int side_screen)
{
	t_pile	*tmp;
	int		y;
	int		nbr_elem;
	int		color;

	if (!pile)
		return ;
	y = 1;
	nbr_elem = 1;
	tmp = pile;
	color = color_element(tmp->data, coord);
		while (y < (coord.y * nbr_elem))
		{
			fill_line(&mlx->str, (IMG_X / 4) * side_screen, y++, color, (tmp->data * coord.x));
		}
		nbr_elem++;
		tmp = tmp->next;
	while (tmp != pile)
	{
	color = color_element(tmp->data, coord);
		while (y < (coord.y * nbr_elem))
			fill_line(&mlx->str, (IMG_X / 4) * side_screen, y++, color, (tmp->data * coord.x));
		nbr_elem++;
		tmp = tmp->next;
	}
}

int		color_element(int data, t_coord coord)
{
	int color;
	(void)coord;
	(void)data;
	if (data < 0)
		color = 0xfff000;
	else
		color = 0x000fff;

	return(color);
}
