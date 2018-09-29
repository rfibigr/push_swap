/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:49:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 16:39:57 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_rra(t_pile **pile_a, t_pile **pile_b)
{
	(void)pile_b;
	if (*pile_a && (*pile_a)->next)
		*pile_a = (*pile_a)->previous;
}

void	op_rrb(t_pile **pile_a, t_pile **pile_b)
{
	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
		*pile_b = (*pile_b)->previous;
}

void	op_rrr(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a && (*pile_a)->next)
		*pile_a = (*pile_a)->previous;
	if (*pile_b && (*pile_b)->next)
		*pile_b = (*pile_b)->previous;
}
