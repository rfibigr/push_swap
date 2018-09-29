/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 17:15:56 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	make_operation(t_pile **pile_a, t_pile **pile_b)
{
	char	*str_operation;
	int		operation;
	t_make	make[11];

	make[e_op_sa] = op_sa;
	make[e_op_sb] = op_sb;
	make[e_op_ss] = op_ss;
	make[e_op_pa] = op_pa;
	make[e_op_pb] = op_pb;
	make[e_op_ra] = op_ra;
	make[e_op_rb] = op_rb;
	make[e_op_rr] = op_rr;
	make[e_op_rra] = op_rra;
	make[e_op_rrb] = op_rrb;
	make[e_op_rrr] = op_rrr;
	while (get_next_line(0, &str_operation))
	{
		if (!calcul_operation(str_operation, &operation))
			exit_error_checker(pile_a, pile_b);
		make[operation](pile_a, pile_b);
		ft_strdel(&str_operation);
	}
	ft_strdel(&str_operation);
}

int		calcul_operation(char *str_operation, int *operation)
{
	static char	conv[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
								"rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(str_operation, conv[i]) == 0)
		{
			*operation = i;
			return (1);
		}
		i++;
	}
	return (0);
}
