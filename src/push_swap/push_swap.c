/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/11 14:44:50 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	(void) ac;
	t_pile *pile_a;

	t_pile *pile_b;

	pile_b = NULL;
	pile_a = NULL;
	create_pile(&(pile_a), av);
	print_pile_AB(pile_a, pile_b);


	return(0);
}
