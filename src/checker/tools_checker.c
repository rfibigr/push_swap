/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:48:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 16:01:30 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		v_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	print_result(t_pile **pile_a, t_pile **pile_b)
{
	if (pile_is_sort(pile_a) == 1 && *pile_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	print_result_visualizer(t_pile **pile_a, t_pile **pile_b, t_mlx *mlx,
																int iteration)
{
	if (pile_is_sort(pile_a) == 1 && *pile_b == NULL)
	{
		mlx_string_put(mlx->init, mlx->name, IMG_X / 2, 30, 0xFFFFFF, "OK");
		mlx_string_put(mlx->init, mlx->name, (IMG_X / 2 - 60), 60, 0xFFFFFF,
															"iteration : ");
		mlx_string_put(mlx->init, mlx->name, (IMG_X / 2 + 40), 60, 0xFFFFFF,
														ft_itoa(iteration));
	}
	else
		mlx_string_put(mlx->init, mlx->name, IMG_X / 2, 40, 0xFFFFFF, "KO");
}

void	exit_ok(t_pile *list_a)
{
	write(1, "\033[41mOK\033[0m", 3);
	if (list_a != NULL)
		free_lst(&list_a);
	exit(0);
}
