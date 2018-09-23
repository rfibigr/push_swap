/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:26:52 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/23 20:46:02 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;

	(void)ac;
	pile_b = NULL;
	pile_a = NULL;
	if (ac < 2)
		return (1);
	create_pile(&(pile_a), av);
	if (pile_a->next != NULL)
		make_operation(&pile_a, &pile_b);
	free_lst(&pile_a);
	return (0);
}
