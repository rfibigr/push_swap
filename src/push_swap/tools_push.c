/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:03:26 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 13:37:56 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pile_len(t_pile *pile_a)
{
	t_pile	*tmp;
	int		len;

	len = 1;
	tmp = pile_a->next;
	while (tmp != pile_a)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int		calcul_min_value(t_pile *pile)
{
	t_pile	*tmp;
	int		min_value;

	tmp = pile->next;
	min_value = pile->data;
	while (tmp != pile)
	{
		if (tmp->data < min_value)
			min_value = tmp->data;
		tmp = tmp->next;
	}
	return (min_value);
}
