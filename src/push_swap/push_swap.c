/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/13 14:57:12 by rfibigr          ###   ########.fr       */
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
	if (ac < 3)
		return (1);
	create_pile(&(pile_a), av);
	print_pile_AB(pile_a, pile_b);
	//sort_pile(pile_a, pile_b)
	return (0);
}
