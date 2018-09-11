/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/11 09:56:53 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **list)
{
	int tmp;

	tmp = *list->data;
	*list->data = *list->next->data;
	*list->next->data = tmp;
}

void	push(t_pile **list_a, t_pile **list_b)
{
	t_pile *tmp;

	tmp = *list_a;
	*list_a = *list_a->next;
	if (*list->b)
		tmp->next = *list_b;
	*list_b = tmp;
}

void	rotate(t_pile **list)
{
	*list = *list->next;
}

void	reverse_rotate(t_pile **list)
{
	*list = *list->previous;
}
