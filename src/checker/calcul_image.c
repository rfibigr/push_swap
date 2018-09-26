/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:22:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 19:34:10 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	calcul_image(t_mlx *mlx, t_pile *pile_a, t_pile *pile_b)
{
	t_coord coord;
	trace_border(mlx);
	coord = define_x_y_ratio(pile_a);
	add_pile_image(pile_a, pile_b, coord, mlx);
}

t_coord define_x_y_ratio(t_pile *list_a)
{
	t_pile	*tmp;
	t_coord	coord;
	int		len_pile;
	int		max_value;

	tmp = list_a->next;
	max_value = v_abs(list_a->data);
	len_pile = 1;
	while (tmp != list_a)
	{
		if (v_abs(tmp->data) > max_value)
			max_value = tmp->data;
		tmp = tmp->next;
		len_pile++;
	}
	coord.y = (IMG_Y - 1) / (len_pile);
	coord.x = ((IMG_X / 4) / max_value);
	return (coord);
}

void	add_pile_image(t_pile *pile_a, t_pile *pile_b, t_coord coord, t_mlx *mlx)
{
	(void)pile_b;
	t_pile	*tmp;
	int		y;
	int		nbr_elem;

	y = 0;
	nbr_elem = 1;
	tmp = pile_a;
		while (y < (coord.y * nbr_elem))
		{
			fill_line(&mlx->str, (IMG_X / 4), y, 0xffffff, (tmp->data * coord.x));
			y++;
		}
		nbr_elem++;
		tmp = tmp->next;
	while (tmp != pile_a)
	{
		while (y < (coord.y * nbr_elem))
		{
			fill_line(&mlx->str, (IMG_X / 4), y, 0xffffff, (tmp->data * coord.x));
			y++;
		}
		nbr_elem++;
		tmp = tmp->next;
	}
}

//calcul du nombre d'element de la liste et valeur absolue max en (min et max)

// on en deduit la taille y de chaue element en y
// et le ratio de chaque element en x
//pour chaque element de la liste on ajoutes les pixel x et y;

// apres chaque operation on recalcul le chaque element
