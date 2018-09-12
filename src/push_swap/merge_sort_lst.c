/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:40:22 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/12 18:37:58 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_pile **list)
{
//	ft_printf("merge_sort\n");
	t_pile *left;
	t_pile *right;

	if (*list == NULL || (*list)->next == NULL)
		return;
	split_chain(*list, &left, &right);
	merge_sort(&left);
	merge_sort(&right);


//	*list = merge(left, right);
	*list = add(left, right);
	print_pile(*list, 'X');
}

t_pile	*add(t_pile *left, t_pile *right)
{
	t_pile *result;
	result = NULL;

	if (*list == NULL)
	{
	left->next = NULL;
	right->next = left;
	result = right;
	}
	else
	{
		left->next = *list;
		*list = left;
		right->next = *list;
		*list = right;
	}
	return (result);
	// add left;
}

t_pile	*merge(t_pile *left, t_pile *right)
{
	t_pile *result;

	result = NULL;
	if (left == NULL)
		return(right);
	else if (right = NULL)
		return (left);

	ft_printf("adress left = %p\n", left);
	ft_printf("adress left->next = %p\n", left->next);
	ft_printf("adress right = %p\n", right);
	ft_printf("adress right->next = %p\n", right->next);
	//print_pile(left, 'L');
	//print_pile(right, 'R');
	//print_pile(result, '=');
	while (left != NULL && right !=NULL)
	{
		/*
		** If duplicate we exit the sorting algoritm
		*/
		if (left->data == right->data)
			exit_error_param(NULL);
		if (left->data > right->data)
			push_front(&result, &left);
		else
			push_front(&result, &right);
	//	ft_printf("data left after = %d\n", left->data);
	//	ft_printf("data right after = %d\n", right->data);
	}
	ft_printf("adress after left = %p\n", left);
	if (left)
		ft_printf("adress after left->next = %p\n", left->next);
	ft_printf("adress after right = %p\n", right);
	if (right)
		ft_printf("adress after right->next = %p\n", right->next);
	 //print_pile(left, 'L');
	 //print_pile(right, 'R');
	// print_pile(result, '=');
	while (left != NULL)
	{
		ft_printf("Restant left\n");
		push_front(&result, &left);
	//	print_pile(result, '=');
	}
	while (right != NULL)
	{
		ft_printf("right\n");
		ft_printf("right->data = %d\n", right->data);
		push_front(&result, &right);
	//	print_pile(result, '=');
	}
	return (result);
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

void	push_front(t_pile **result, t_pile **add)
{
	t_pile *tmp;

	tmp = *add;
	if (*result == NULL)
	{
		*result = *add;
		(*result)->next = NULL;
	}
	else
	{
		(*add)->next = *result;
		*result = *add;
	}
	*add = tmp->next;
	//ft_printf("data add after = %d\n", (*add)->data);
}
/*
int		list_len(t_pile *list)
{
	t_pile *tmp;
	int		i;

	i = 1;
	tmp = list;
	if (!(tmp))
		return(0);
	else if (!(tmp->next))
		return(1);
	else
	{
		tmp = tmp->next;
		while (tmp != list)
		{
			tmp = tmp->next
			i++;
		}
	}
	return (i);
}
*/
