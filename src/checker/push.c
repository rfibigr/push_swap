/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 17:18:08 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_pa(t_pile **pile_two, t_pile **pile_one)
{
	t_pile *new_top_one;

	if (!(op_push_control(pile_one, pile_two)))
		return ;
	new_top_one = NULL;
	if ((*pile_one)->next != (*pile_one))
	{
		new_top_one = (*pile_one)->next;
		new_top_one->previous = (*pile_one)->previous;
		new_top_one->previous->next = new_top_one;
	}
	if (*pile_two == NULL)
	{
		(*pile_two) = (*pile_one);
		(*pile_two)->next = (*pile_two);
		(*pile_two)->previous = (*pile_two);
	}
	(*pile_one)->next = (*pile_two);
	(*pile_one)->previous = (*pile_two)->previous;
	(*pile_one)->previous->next = (*pile_one);
	(*pile_two)->previous = (*pile_one);
	(*pile_two) = (*pile_one);
	(*pile_one) = new_top_one;
}

void	op_pb(t_pile **pile_one, t_pile **pile_two)
{
	t_pile *new_top_one;

	if (!(op_push_control(pile_one, pile_two)))
		return ;
	new_top_one = NULL;
	if ((*pile_one)->next != (*pile_one))
	{
		new_top_one = (*pile_one)->next;
		new_top_one->previous = (*pile_one)->previous;
		new_top_one->previous->next = new_top_one;
	}
	if (*pile_two == NULL)
	{
		(*pile_two) = (*pile_one);
		(*pile_two)->next = (*pile_two);
		(*pile_two)->previous = (*pile_two);
	}
	(*pile_one)->next = (*pile_two);
	(*pile_one)->previous = (*pile_two)->previous;
	(*pile_one)->previous->next = (*pile_one);
	(*pile_two)->previous = (*pile_one);
	(*pile_two) = (*pile_one);
	(*pile_one) = new_top_one;
}

int		op_push_control(t_pile **pile_one, t_pile **pile_two)
{
	if (!*pile_one)
		return (0);
	if ((*pile_one)->next == NULL)
	{
		*pile_two = *pile_one;
		*pile_one = NULL;
		return (0);
	}
	return (1);
}
