/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/19 13:01:52 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	int tmp;

	tmp = (*pile)->data;
	(*pile)->data = (*pile)->next->data;
	(*pile)->next->data = tmp;
}

void	push(t_pile **pile_one, t_pile **pile_two)
{
	t_pile *tmp;

	tmp = *pile_one;
	(*pile_one) = (*pile_one)->next;
	if (*pile_two)
		tmp->next = (*pile_two);
	(*pile_two) = tmp;
}

void	rotate(t_pile **pile)
{
	*pile = (*pile)->next;
}

void	reverse_rotate(t_pile **pile)
{
	*pile = (*pile)->previous;
}
