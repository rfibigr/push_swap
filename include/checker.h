/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 17:52:13 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"

enum				e_op
{
	e_op_sa,
	e_op_sb,
	e_op_ss,
	e_op_pa,
	e_op_pb,
	e_op_ra,
	e_op_rb,
	e_op_rr,
	e_op_rra,
	e_op_rrb,
	e_op_rrr,
};

typedef	void		(*t_make)(t_pile **, t_pile **);

/*
** MAKE OPERATION
*/
void	make_operation(t_pile **pile_a, t_pile **pile_b);
int		calcul_operation(char *str_operation, int *operation);

/*
** OPERATION
*/
void	op_pa(t_pile **pile_a, t_pile **pile_b);
void	op_pb(t_pile **pile_a, t_pile **pile_b);
void	op_rrr(t_pile **pile_a, t_pile **pile_b);
void	op_rra(t_pile **pile_a, t_pile **pile_b);
void	op_rrb(t_pile **pile_a, t_pile **pile_b);
void	op_rr(t_pile **pile_a, t_pile **pile_b);
void	op_ra(t_pile **pile_a, t_pile **pile_b);
void	op_rb(t_pile **pile_a, t_pile **pile_b);
void	op_sa(t_pile **pile_a, t_pile **pile_b);
void	op_sb(t_pile **pile_a, t_pile **pile_b);
void	op_ss(t_pile **pile_a, t_pile **pile_b);

#endif
