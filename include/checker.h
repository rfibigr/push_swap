/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/23 20:47:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// STRUCTURE
typedef struct		s_pile
{
	int				data;
	struct s_pile	*next;
	struct s_pile	*previous;
}					t_pile;

typedef void	(*t_make)(t_pile **);


// CREATE PILE
void	create_pile(t_pile **pile_a, char **av);
int		test_param(char *av);
void	add_element(t_pile **begin, char *av);
void	reorder_lst_order(t_pile *pile_a);
// MERGE SORT
void	merge_sort(t_pile **list);
void	merge(t_pile **list, t_pile *left, t_pile *right);
void	split_chain(t_pile *begin, t_pile **left, t_pile **right);
void	push_back(t_pile **result, t_pile **add);

//EXIT
void	exit_error_malloc(t_pile **list);
void	exit_error_param(t_pile **list);
void	free_lst(t_pile **list);

//MAKE OPERATION
void	make_operation(t_pile **pile_a, t_pile **pile_b);
int		pile_is_sort(t_pile **pile);

//OPERATION
void	make_ra(t_pile **pile);
void	make_rb(t_pile **pile);
void	make_rrr(t_pile **pile);

//TOOLS
int		ft_atoi_exit(const char *s, t_pile **begin);


void	add(t_pile **list, t_pile *left, t_pile *right);

#endif
