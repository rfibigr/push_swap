/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_operation_visual.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 15:54:40 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		make_operation_visual(t_loop *loop)
{
	char	*str_operation;
	int		operation;

	operation = 0;
	str_operation = NULL;
	usleep(1000 * (SPEED * loop->speed));
	make_instruction(loop, str_operation, operation);
	draw_pile_image(loop->pile_a, loop->pile_b, loop->coord, loop->mlx);
	return (1);
}

void	make_instruction(t_loop *loop, char *str_operation, int operation)
{
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
	if (get_next_line(0, &str_operation))
	{
		loop->iteration++;
		if (!calcul_operation(str_operation, &operation))
			exit_error_checker(&loop->pile_a, &loop->pile_b);
		make[operation](&loop->pile_a, &loop->pile_b);
		ft_strdel(&str_operation);
	}
	else
		print_result_visualizer(&loop->pile_a, &loop->pile_b,
												loop->mlx, loop->iteration);
}
