/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:26:52 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/27 11:29:40 by rfibigr          ###   ########.fr       */
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
	print_result(&pile_a, &pile_b);
	free_lst(&pile_a);
	return (0);
}
