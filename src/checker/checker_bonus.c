/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:26:52 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 19:02:58 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_argument(int ac, char **av)
{
	if (ft_strcmp(av[1], "-v\0"))
		return ;
	else
		main_visualizer(ac,av);

}

int		main_visualizer(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_mlx	mlx;

	if (ac == 2)
		exit (0);
	mlx = ft_initialise();
	pile_b = NULL;
	pile_a = NULL;
	av = av + 1;
	create_pile(&(pile_a), &av);
	mlx.image = mlx_new_image(mlx.init, IMG_X, IMG_Y);
	mlx.str = mlx_get_data_addr(mlx.image, &mlx.bpp, &mlx.size_line, &mlx.endian);
	calcul_image(&mlx, pile_a, pile_b);

	//fill_pixel(&img_str, 10, 10, 0xFFFFFF);
	mlx_put_image_to_window(mlx.init, mlx.name, mlx.image, 0, 100);

	// if (!pile_a)
	// 	return (0);
	// if (pile_a->next != NULL)
	// 	make_operation(&pile_a, &pile_b);
	// if (pile_is_sort(&pile_a) == 1 && pile_b == NULL)
	// 	ft_printf("OK\n");
	// else
	// {
	// 	ft_printf("KO\n");
	// 	free_lst(&pile_b);
	// }
	mlx_key_hook(mlx.name, key_hook, (void*)&pile_a);
	mlx_loop(mlx.init);
	free_lst(&pile_a);
	exit (0);
}
