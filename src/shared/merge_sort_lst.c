/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:40:22 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/24 14:54:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_pile **list)
{
	t_pile *left;
	t_pile *right;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	split_chain(*list, &left, &right);
	merge_sort(&left);
	merge_sort(&right);
	merge(list, left, right);
}

void	merge(t_pile **list, t_pile *left, t_pile *right)
{
	t_pile *result;

	result = NULL;
	while (left != NULL && right != NULL)
	{
		if (left->data == right->data)
			exit_error_param(list);
		if (left->data < right->data)
			push_back(&result, &left);
		else
			push_back(&result, &right);
	}
	while (left != NULL)
		push_back(&result, &left);
	while (right != NULL)
		push_back(&result, &right);
	*list = result;
}

void	split_chain(t_pile *begin, t_pile **left, t_pile **right)
{
	t_pile *fast;
	t_pile *slow;

	slow = begin;
	fast = begin->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = begin;
	*right = slow->next;
	slow->next = NULL;
}

void	push_back(t_pile **result, t_pile **add)
{
	t_pile *elem_to_add;
	t_pile *tmp;

	tmp = *result;
	/* isolation of the first node of add in the pointeur tmp */
	elem_to_add = *add;
	*add = (*add)->next;
	elem_to_add->next = NULL;
	if (tmp == NULL)
		*result = elem_to_add;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem_to_add;
	}
}
