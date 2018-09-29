/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge_condition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:26:03 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 16:02:29 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_previous_min(t_pile *pile_one, int data_two)
{
	if (pile_one->data < data_two)
		return (0);
	if (pile_one->next->data > data_two
									&& pile_one->next->data < pile_one->data)
		return (0);
	if (pile_one->next->next->data > data_two
								&& pile_one->next->next->data < pile_one->data)
		return (0);
	return (1);
}

int		test_top_min(t_pile *pile_one, int data_two)
{
	if (pile_one->data < data_two)
		return (0);
	if (pile_one->next->data > data_two
									&& pile_one->next->data < pile_one->data)
		return (0);
	return (1);
}

int		test_previous_max(t_pile **pile_one, int data_two)
{
	if ((*pile_one)->data > data_two)
		return (0);
	if ((*pile_one)->next->data < data_two
								&& (*pile_one)->data < (*pile_one)->next->data)
		return (0);
	if ((*pile_one)->next->next->data < data_two
						&& (*pile_one)->data < (*pile_one)->next->next->data)
		return (0);
	return (1);
}

int		test_top_max(t_pile **pile_one, int data_two)
{
	if ((*pile_one)->data > data_two)
		return (0);
	if ((*pile_one)->next->data < data_two
								&& (*pile_one)->data < (*pile_one)->next->data)
		return (0);
	return (1);
}
