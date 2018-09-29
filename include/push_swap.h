/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 15:07:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

/*
** PUSH SWAP
*/

void	sort_pile(t_pile **pile_a, t_pile **pile_b, int len);

/*
** SORT
*/
void	sort_2(t_pile **pile_a, t_pile **pile_b);
void	sort_3(t_pile **pile_a, t_pile **pile_b);
void	sort_selection(t_pile **pile_a, t_pile **pile_b);
void	rotate_to_min_value(int min, t_pile **pile);

/*
** SORT_MERGE
*/
void	push_max_decroissant(t_pile **pile_one, t_pile **pile_two, char c);
void	push_min_croissant(t_pile **pile_one, t_pile **pile_two, char c);
void	initial_pile_min(t_pile **pile_one, t_pile **pile_two, char c);
void	initial_pile_max(t_pile **pile_one, t_pile **pile_two, char c);
void	sort_merge(t_pile **pile_a, t_pile **pile_b);

/*
** SORT_MERGE_CONDITION
*/
int		test_previous_min(t_pile *pile_one, int data_two);
int		test_previous_previous_min(t_pile *pile_one, int data_two);
int		test_top_min(t_pile *pile_one, int data_two);
int		test_top_top_min(t_pile *pile_one, int data_two);
int		test_previous_max(t_pile **pile_one, int data_two);
int		test_previous_previous_max(t_pile **pile_one, int data_two);
int		test_top_max(t_pile **pile_one, int data_two);
int		test_top_top_max(t_pile **pile_one, int data_two);
int		test_pile_decroissant_coissant(t_pile **pile);

/*
** OPERATION
*/
void	swap(t_pile **pile, char c);
void	push(t_pile **pile_one, t_pile **pile_two, char c);
void	rotate(t_pile **pile, char c);
void	reverse_rotate(t_pile **pile, char c);

/*
** TOOL PUSH
*/
int		pile_len(t_pile *pile_a);
int		calcul_min_value(t_pile *pile);

#endif
