/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/18 17:42:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	while (pile_is_sort(pile_a))
	{
		while (pile_a)
		{
			if (pile_b == NULL)
				push_max_decroissant(pile_a, pile_b);
			else if (*(pile_b)->data < (*pile_a)->data &&
								*(pile_b)->data < (*pile_a)->previous->data)
				push_min_croissant(pile_a, pile_b);
			else if (*(pile_b)->data > (*pile_a)->data &&
								*(pile_b)->data > (*pile_a)->previous->data)
				push_max_decroissant(pile_a, pile_b);
		}
		while (pile_b)
		{
			if (pile_a == NULL)
				push_max_decroissant(pile_a, pile_b);
			else if (*(pile_a)->data < (*pile_b)->data &&
								*(pile_b)->data < (*pile_b)->previous->data)
				push_min_croissant(pile_a, pile_b);
			else if (*(pile_a)->data > (*pile_b)->data &&
								*(pile_a)->data > (*pile_b)->previous->data)
				push_max_decroissant(pile_a, pile_b);
		}
	}

}

int		pile_is_sort(t_pile **pile)
{
	t_pile *tmp;
	int		last;

	tmp = *pile->next;
	while(tmp != *pile && tmp != NULL)
	{

	}
	return (1);
}

void	push_max_decroissant(pile_a, pile_b);
{

}

void	push_min_croissant(pile_a, pile_b);
{

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
