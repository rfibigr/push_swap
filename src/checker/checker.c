/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:26:52 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 18:21:37 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;

	if (ac == 1)
		return (0);
	check_argument(ac, av);
	pile_b = NULL;
	pile_a = NULL;
	create_pile(&(pile_a), &av);
	if (!pile_a)
		return (0);
	if (pile_a->next != NULL)
		make_operation(&pile_a, &pile_b);
	if (pile_is_sort(&pile_a) == 1 && pile_b == NULL)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		free_lst(&pile_b);
	}
	free_lst(&pile_a);
	return (0);
}
