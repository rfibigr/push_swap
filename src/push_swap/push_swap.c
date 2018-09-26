/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 15:10:44 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;

	pile_b = NULL;
	pile_a = NULL;
	if (ac == 1)
		return (0);
	create_pile(&(pile_a), &av);
	if (!pile_a)
		return (0);
	if (pile_a->next != NULL)
		sort_pile(&pile_a, &pile_b);
	free_lst(&pile_a);
	return (0);
}
