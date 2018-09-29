/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 15:55:28 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	pile_a = NULL;
	if (ac == 1)
		return (0);
	create_pile(&(pile_a), &av);
	if (!pile_a)
		return (0);
	if (pile_a->next != NULL)
		sort_pile(&pile_a, &pile_b, pile_len(pile_a));
	free_lst(&pile_a);
	return (0);
}

void	sort_pile(t_pile **pile_a, t_pile **pile_b, int len)
{
	if (len == 2)
		sort_2(pile_a, pile_b);
	else if (len == 3)
		sort_3(pile_a, pile_b);
	else if (len <= 40)
		sort_selection(pile_a, pile_b);
	else
		sort_merge(pile_a, pile_b);
}
