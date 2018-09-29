/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 16:40:49 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_ra(t_pile **pile_a, t_pile **pile_b)
{
	(void)pile_b;
	if (*pile_a && (*pile_a)->next)
		*pile_a = (*pile_a)->next;
}

void	op_rb(t_pile **pile_a, t_pile **pile_b)
{
	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
		*pile_b = (*pile_b)->next;
}

void	op_rr(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a && (*pile_a)->next)
		*pile_a = (*pile_a)->next;
	if (*pile_b && (*pile_b)->next)
		*pile_b = (*pile_b)->next;
}
