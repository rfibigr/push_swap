/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:31:35 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 14:01:26 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_param(t_pile **list)
{
	write(1, "Error\n", 6);
	if (list != NULL)
	{
		free_lst(list);
		exit(1);
	}
}

void	exit_error_malloc(t_pile **list)
{
	(void)**list;
	write(1, "Malloc : fail\n", 14);
	free_lst(list);
	exit(1);
}

void	exit_error_checker(t_pile **list_a, t_pile **list_b)
{
	write(1, "Error\n", 6);
	if (list_a != NULL)
		free_lst(list_a);
	if (list_b != NULL)
		free_lst(list_b);
	exit(1);
}

void	free_lst(t_pile **list)
{
	t_pile *tmp;
	t_pile *start;

	if (!*list)
		return ;
	start = *list;
	tmp = *list;
	while ((*list)->previous != start && (*list)->previous != NULL)
	{
		tmp = *list;
		*list = (*list)->previous;
		free(tmp);
	}
	free(*list);
}
