/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 11:04:41 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** STRUCTURE
*/
typedef struct		s_pile
{
	int				data;
	struct s_pile	*next;
	struct s_pile	*previous;
}					t_pile;

/*
** TOOLS
*/
void				print_pile(t_pile *list, char *str);
void				print_pile_previous(t_pile *list, char *str);
void				print_pile_ab(t_pile *pile_a, t_pile *pile_b);

/*
** CREATE PILE
*/
void				create_pile(t_pile **pile_a, char ***av);
int					test_param(char **av);
void				create_element(t_pile **new_element, t_pile **begin);
void				add_element(t_pile **begin, char **av);
void				reorder_lst_order(t_pile *pile_a);
/*
** MERGE SORT
*/
void				merge_sort(t_pile **list);
void				merge(t_pile **list, t_pile *left, t_pile *right);
void				split_chain(t_pile *begin, t_pile **left, t_pile **right);
void				push_back(t_pile **result, t_pile **add);

/*
** EXIT
*/
void				exit_error_malloc(t_pile **list);
void				exit_error_param(t_pile **list);
void				exit_error_checker(t_pile **list_a, t_pile **list_b);
void				free_lst(t_pile **list);

/*
** TOOLS
*/
int					ft_atoi_exit(char **s, t_pile **begin);
void				skip_space(char **s);
int					pile_is_sort(t_pile **pile);

#endif
