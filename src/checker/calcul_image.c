/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:22:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 16:08:53 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_coord	define_x_y_ratio(t_pile *pile_a)
{
	t_pile	*tmp;
	t_coord	coord;

	tmp = pile_a->next;
	coord.min = pile_a->data;
	coord.max = pile_a->data;
	coord.len_pile = 1;
	while (tmp != pile_a)
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

void	draw_pile_image(t_pile *pile_a, t_pile *pile_b,
													t_coord coord, t_mlx *mlx)
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

	if (!pile)
		return ;
	y = 1;
	nbr_elem = 1;
	tmp = pile;
	if (coord.min < 0)
		add_pile_neg(pile, coord, mlx, side_screen);
	else
	{
		if (side_screen == 3)
			side_screen = (IMG_X / 2 + 1);
		else
			side_screen = 0;
		add_pile_pos(pile, coord, mlx, side_screen);
	}
}

void	add_pile_neg(t_pile *pile, t_coord coord, t_mlx *mlx, int side_screen)
{
	t_pile	*tmp;
	int		y;
	int		nbr_elem;

	y = 1;
	nbr_elem = 1;
	tmp = pile;
	while (y < (coord.y * nbr_elem))
		fill_line(&mlx->str, (IMG_X / 4) * side_screen, y++,
													(tmp->data * coord.x));
	nbr_elem++;
	tmp = tmp->next;
	while (tmp != pile)
	{
		while (y < (coord.y * nbr_elem))
			fill_line(&mlx->str, (IMG_X / 4) * side_screen, y++,
													(tmp->data * coord.x));
		nbr_elem++;
		tmp = tmp->next;
	}
}

void	add_pile_pos(t_pile *pile, t_coord coord, t_mlx *mlx, int side_screen)
{
	t_pile	*tmp;
	int		y;
	int		nbr_elem;

	y = 1;
	nbr_elem = 1;
	tmp = pile;
	while (y < (coord.y * nbr_elem))
		fill_line(&mlx->str, side_screen, y++, (tmp->data * coord.x) * 2);
	nbr_elem++;
	tmp = tmp->next;
	while (tmp != pile)
	{
		while (y < (coord.y * nbr_elem))
			fill_line(&mlx->str, side_screen, y++,
											(tmp->data * coord.x) * 2);
		nbr_elem++;
		tmp = tmp->next;
	}
}
