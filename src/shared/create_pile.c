/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:24:47 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 17:40:53 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_pile(t_pile **pile_a, char ***av)
{
	t_pile	*tmp;

	*av = *av + 1;
	while (**av)
	{
		while (***av != '\0')
		{
			add_element(pile_a, *av);
		}
		*av = *av + 1;
	}
	tmp = *pile_a;
	if (!tmp)
		return ;
	if (tmp->previous)
	{
		tmp->previous->next = NULL;
		merge_sort(&tmp);
		reorder_lst_order(*pile_a);
	}
}

void	reorder_lst_order(t_pile *pile_a)
{
	t_pile *tmp;

	tmp = pile_a;
	if (tmp->previous == NULL)
		return ;
	while (tmp->previous != pile_a)
	{
		tmp->previous->next = tmp;
		tmp = tmp->previous;
	}
	tmp->previous->next = tmp;
}

void	add_element(t_pile **begin, char **av)
{
	t_pile *new_element;
	t_pile *tail;

	create_element(&new_element, begin);
	tail = NULL;
	if (*begin == NULL)
		*begin = new_element;
	else if ((*begin)->next == NULL)
	{
		new_element->next = *begin;
		new_element->previous = *begin;
		(*begin)->next = new_element;
		(*begin)->previous = new_element;
	}
	else
	{
		tail = (*begin)->previous;
		(*begin)->previous->next = new_element;
		(*begin)->previous = new_element;
		new_element->next = *begin;
		new_element->previous = tail;
	}
	new_element->data = ft_atoi_exit(av, begin);
}

void	create_element(t_pile **new_element, t_pile **begin)
{
	if (!(*new_element = (t_pile*)malloc(sizeof(t_pile))))
		exit_error_malloc(begin);
	(*new_element)->next = NULL;
	(*new_element)->previous = NULL;
}
