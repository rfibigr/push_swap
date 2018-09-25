/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 17:53:03 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

/*
** SORT_PILE
*/
void	sort_pile(t_pile **pile_a, t_pile **pile_b);
void	push_max_decroissant(t_pile **pile_one, t_pile **pile_two, char c);
void	push_min_croissant(t_pile **pile_one, t_pile **pile_two, char c);

int		test_previous_min(t_pile *pile_one, int data_two);
int		test_top_min(t_pile *pile_one, int data_two);
int		test_previous_max(t_pile **pile_one, int data_two);
int		test_top_max(t_pile **pile_one, int data_two);

/*
** OPERATION
*/
void	swap(t_pile **pile, char c);
void	push(t_pile **pile_one, t_pile **pile_two, char c);
void	rotate(t_pile **pile, char c);
void	reverse_rotate(t_pile **pile, char c);

#endif
