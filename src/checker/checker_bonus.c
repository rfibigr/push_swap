/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:26:52 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/27 19:15:13 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_argument(int ac, char **av)
{
	if (ft_strcmp(av[1], "-v\0"))
		return ;
	else
		main_visualizer(ac, av);
}

int		main_visualizer(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_mlx	mlx;
	t_coord	coord;
	t_loop	*loop;

	if (ac == 2)
		exit(0);
	mlx = ft_initialise();
	mlx.image = mlx_new_image(mlx.init, IMG_X, IMG_Y);
	mlx.str = mlx_get_data_addr(mlx.image, &mlx.bpp,
												&mlx.size_line, &mlx.endian);
	pile_b = NULL;
	pile_a = NULL;
	av = av + 1;
	create_pile(&(pile_a), &av);
	if (!pile_a)
		return (0);
	coord = define_x_y_ratio(pile_a);
	loop = init_loop(pile_a, pile_b, coord, &mlx);
	draw_pile_image(pile_a, pile_b, coord, &mlx);
	mlx_key_hook(mlx.name, key_hook, loop);
	mlx_loop_hook(mlx.init, make_operation_visual, loop);
	mlx_loop(mlx.init);
	return (0);
}

t_loop	*init_loop(t_pile *pile_a, t_pile *pile_b, t_coord coord, t_mlx *mlx)
{
	t_loop *loop;

	if (!(loop = (t_loop*)malloc(sizeof(t_loop))))
		return (NULL);
	loop->mlx = mlx;
	loop->pile_a = pile_a;
	loop->pile_b = pile_b;
	loop->coord = coord;
	loop->speed = 4;
	loop->iteration = 0;
	return (loop);
}
