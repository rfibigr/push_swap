/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 22:22:39 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 16:02:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_pile **pile_a, t_pile **pile_b)
{
	(void)pile_b;
	swap(pile_a, 'a');
	return ;
}

void	sort_3(t_pile **pile_a, t_pile **pile_b)
{
	(void)pile_b;
	if ((*pile_a)->data < (*pile_a)->next->data &&
		(*pile_a)->data < (*pile_a)->previous->data)
	{
		reverse_rotate(pile_a, 'a');
		swap(pile_a, 'a');
	}
	else if ((*pile_a)->data > (*pile_a)->next->data &&
		(*pile_a)->data < (*pile_a)->previous->data)
		swap(pile_a, 'a');
	else if ((*pile_a)->data < (*pile_a)->next->data &&
		(*pile_a)->data > (*pile_a)->previous->data)
		reverse_rotate(pile_a, 'a');
	else if ((*pile_a)->data > (*pile_a)->next->data &&
		(*pile_a)->data > (*pile_a)->previous->data)
	{
		if ((*pile_a)->next->data > (*pile_a)->previous->data)
		{
			swap(pile_a, 'a');
			reverse_rotate(pile_a, 'a');
		}
		else
			rotate(pile_a, 'a');
	}
	return ;
}

void	sort_selection(t_pile **pile_a, t_pile **pile_b)
{
	int min;

	while (pile_len(*pile_a) != 3)
	{
		min = calcul_min_value(*pile_a);
		if ((*pile_a)->data != min)
		{
			rotate_to_min_value(min, pile_a);
			push(pile_a, pile_b, 'a');
		}
		else
			push(pile_a, pile_b, 'a');
	}
	sort_3(pile_a, pile_b);
	while (*pile_b != NULL)
		push(pile_b, pile_a, 'b');
}

void	rotate_to_min_value(int min, t_pile **pile)
{
	int		index_rotate;
	int		index_reverse_rotate;
	t_pile	*tmp;

	index_rotate = 1;
	index_reverse_rotate = 1;
	tmp = (*pile)->next;
	while (tmp->data != min)
	{
		tmp = tmp->next;
		index_rotate++;
	}
	tmp = (*pile)->previous;
	while (tmp->data != min)
	{
		tmp = tmp->previous;
		index_reverse_rotate++;
	}
	if (index_rotate <= index_reverse_rotate)
		while (index_rotate-- != 0)
			rotate(pile, 'a');
	else
		while (index_reverse_rotate-- != 0)
			reverse_rotate(pile, 'a');
}
