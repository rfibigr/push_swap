/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 17:43:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile, char c)
{
	int tmp;

	tmp = (*pile)->data;
	(*pile)->data = (*pile)->next->data;
	(*pile)->next->data = tmp;
	ft_printf("s%c\n", c);
}

void	push(t_pile **pile_one, t_pile **pile_two, char c)
{
	t_pile *new_top_one;

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
	c == 'a' ? ft_printf("pb\n") : ft_printf("pa\n");
}

void	rotate(t_pile **pile, char c)
{
	*pile = (*pile)->next;
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_pile **pile, char c)
{
	*pile = (*pile)->previous;
	ft_printf("rr%c\n", c);
}
