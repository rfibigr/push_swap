/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 16:54:32 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;

	(void)ac;
	pile_b = NULL;
	pile_a = NULL;
	if (ac < 2)
		return (1);
//	print_arg(av);
	create_pile(&(pile_a), &av);
	print_pile_AB(pile_a, pile_b);
	if (!pile_a)
		return (0);
	if (pile_a->next != NULL)
		sort_pile(&pile_a, &pile_b);
		// test(&pile_a, &pile_b);
	// ft_printf("		END\n--------------------------\n");
	free_lst(&pile_a);
	return (0);
}
