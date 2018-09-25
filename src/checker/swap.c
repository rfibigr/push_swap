/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 16:18:23 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_sa(t_pile **pile_a, t_pile **pile_b)
{
	int tmp;
	(void)pile_b;

	if (!*pile_a)
		return ;
	tmp = (*pile_a)->data;
	(*pile_a)->data = (*pile_a)->next->data;
	(*pile_a)->next->data = tmp;
}

void	op_sb(t_pile **pile_a, t_pile **pile_b)
{
	int tmp;
	(void)pile_a;

	if (!*pile_b)
		return ;
	tmp = (*pile_b)->data;
	(*pile_b)->data = (*pile_b)->next->data;
	(*pile_b)->next->data = tmp;
}

void	op_ss(t_pile **pile_a, t_pile **pile_b)
{
	int tmp;

	if (!*pile_a || !*pile_b)
		return ;
	tmp = (*pile_a)->data;
	(*pile_a)->data = (*pile_a)->next->data;
	(*pile_a)->next->data = tmp;
	tmp = (*pile_b)->data;
	(*pile_b)->data = (*pile_b)->next->data;
	(*pile_b)->next->data = tmp;
}
