/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/07 18:56:22 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	int tmp;

	tmp = *list->data;
	*list->data = *list->next->data;
	*list->next->data = tmp;
}

void	push(t_list **list_a, t_list **list_b)
{
	t_list *tmp;

	tmp = *list_a;
	*list_a = *list_a->next;
	if (*list->b)
		tmp->next = *list_b;
	*list_b = tmp;
}

void	rotate(t_list **list)
{
	*list = *list->next;
}

void	reverse_rotate(t_list **list)
{
	*list = *list->previous;
}
