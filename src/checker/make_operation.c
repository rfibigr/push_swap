/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/24 12:26:22 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	make_operation(t_pile **pile_a, t_pile **pile_b)
{
	char	*str_operation;
	(void)pile_a;
	(void)pile_b;
	/*
	int		operation;
	t_make assign[8];

	make[e_sa] = op_sa;
	make[e_sb] = op_sb;
	make[e_ss] = op_ss;
	make[e_pa] = op_pa;
	make[e_pb] = op_pb;
	make[e_ra] = op_ra;
	make[e_rb] = op_rb;
	make[e_rr] = op_rr;
	make[e_rra] = op_rra;
	make[e_rrb] = op_rrb;
	make[e_rrr] = op_rrr;
	*/
	while (get_next_line(0, &str_operation))
	{
		// calcul_operation(str_operation, &operation)
		// make[operation](pile_a, pile_b);
		ft_printf("operation = %s\n", str_operation);
	}
}

/*

int		calcul_operation(char *str_operation, int *operation)
{
	static char	conv[12][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
	"rra", "rrb", "rrr" "\0"};
	int			i;

	i = 0;
	operation = 0;
	while (conv[i])
	{
		if (strdif (str_operation, conv[i] == 0)
		{
			*operation = i;
			return (1);
		}
		i++;
	}
	// error
	return (0);
}
*/

int		pile_is_sort(t_pile **pile)
{
	t_pile *tmp;
	int		last;

	tmp = (*pile)->next;
	last = (*pile)->data;
	while(tmp != *pile && tmp != NULL)
	{
		if (last > tmp->data)
			return (0);
		last = tmp ->data;
		tmp = tmp->next;
	}
	return (1);
}
