/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/19 13:05:02 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	while (pile_is_sort(pile_a) != 1)
	{
		ft_printf("pile is sort %d\n", pile_is_sort(pile_a));
		while (pile_a)
		{
		print_pile_AB(*pile_a, *pile_b);
			push_max_decroissant(pile_a, pile_b);
			push_min_croissant(pile_a, pile_b);
		}
		while (pile_b)
		{
		print_pile_AB(*pile_a, *pile_b);
			push_max_decroissant(pile_a, pile_b);
			push_min_croissant(pile_a, pile_b);
		}
	}
}

int		pile_is_sort(t_pile **pile)
{
	t_pile *tmp;
	int		last;

	tmp = (*pile)->next;
	last = (*pile)->data;
	while(tmp != *pile && tmp != NULL)
	{
		if (last > tmp->data)
			return (0);
		last = tmp ->data;
		tmp = tmp->next;
	}
	return (1);
}

void	push_max_decroissant(t_pile **pile_one, t_pile **pile_two)
{
	if (pile_two == NULL)
		push(pile_one, pile_two);
	while (pile_one)
	{
		if ((*pile_one)->previous == NULL && (*pile_one)->data < (*pile_two)->data)
			push(pile_one, pile_two);
		else if ((*pile_one)->previous->data > (*pile_one)->data
										&& (*pile_one)->previous->data < (*pile_two)->data)
		{
			reverse_rotate(pile_one);
			push(pile_one, pile_two);
		}
		else if ((*pile_one)->previous->data < (*pile_one)->data
										&& (*pile_one)->data < (*pile_two)->data)
			push(pile_one, pile_two);
	}
	return ;
}

void	push_min_croissant(t_pile **pile_one, t_pile **pile_two)
{
	if (pile_two == NULL)
		push(pile_one, pile_two);
	while (pile_one)
	{
		if ((*pile_one)->previous == NULL && (*pile_one)->data > (*pile_two)->data)
			push(pile_one, pile_two);
		else if ((*pile_one)->previous->data > (*pile_one)->data
										&& (*pile_one)->previous->data > (*pile_two)->data)
		{
			reverse_rotate(pile_one);
			push(pile_one, pile_two);
		}
		else if ((*pile_one)->previous->data < (*pile_one)->data
													&& (*pile_one)->data > (*pile_two)->data)
			push(pile_one, pile_two);
	}
	return ;
}
/* IDEE ALGO
phase 1 :
**top de la pile -> on envoie le plus grand en premier
**bottom de la pile -> on envoie le plus petit en premier
**jusqu'a pile A vide
**
phase 2 : on envoie le plus grand entre haut et bas jusqu'a que ce ne soit plus possible
on recommence la phase 2 en inversant (plus petit en premier)

jusqu'a trie

*/
