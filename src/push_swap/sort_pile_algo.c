/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/24 18:59:21 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	while (pile_is_sort(pile_a) != 1)
	{
		while (*pile_a != NULL)
		{
			push_max_decroissant(pile_a, pile_b, 'a');
			push_min_croissant(pile_a, pile_b, 'a');
		}
		while (*pile_b != NULL)
		{
			push_max_decroissant(pile_b, pile_a, 'b');
			push_min_croissant(pile_b, pile_a, 'b');
		}
	}
}

void	push_max_decroissant(t_pile **pile_one, t_pile **pile_two, char c)
{
	if (*pile_one == NULL)
		return;
	if (*pile_two == NULL)
	{
		if ((*pile_one)->previous->data > (*pile_one)->data && (*pile_one)->previous->data > (*pile_one)->next->data)
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->data > (*pile_one)->next->data)
			push(pile_one, pile_two, c);
		else
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
	}
	while (*pile_one != NULL)
	{
		// ft_printf("BOUCLE PUSH MAX DECROISSANT\n");
		// print_pile_AB(*pile_one, *pile_two);
		if(test_previous_max(&(*pile_one)->previous, (*pile_two)->data))
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if(test_top_max(pile_one, (*pile_two)->data))
		{
			push(pile_one, pile_two, c);
		}
		else if((*pile_one)->next->data < (*pile_two)->data)
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
		 else
			return;
	}
}

void	push_min_croissant(t_pile **pile_one, t_pile **pile_two, char c)
{
	if (*pile_one == NULL)
		return;
	if (*pile_two == NULL)
	{
		if ((*pile_one)->previous->data < (*pile_one)->data && (*pile_one)->previous->data < (*pile_one)->next->data)
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->data < (*pile_one)->next->data)
			push(pile_one, pile_two, c);
		else
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
	}
	while (*pile_one != NULL)
	{
		// ft_printf("BOUCLE PUSH MIN CROISSANT\n");
		// print_pile_AB(*pile_one, *pile_two);
		if(test_previous_min((*pile_one)->previous, (*pile_two)->data))
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if(test_top_min(*pile_one, (*pile_two)->data))
		{
			push(pile_one, pile_two, c);
		}
		else if((*pile_one)->next->data > (*pile_two)->data)
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else
			return ;
	}
}
