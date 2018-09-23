/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:31:35 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/20 10:48:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_param(t_pile **list)
{
	write(1, "Error\n", 6);
	// print_pile(*list, "EXIT ERROR PARAM : LST BEFORE FREE");
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

void	free_lst(t_pile **list)
{
	t_pile *tmp;
	t_pile *start;

	start = *list;
	tmp = *list;
	while ((*list)->previous != start && (*list)->previous != NULL)
	{
		tmp = *list;
		*list = (*list)->previous;
		// ft_printf("free %p\n", tmp);
		free(tmp);
	}
	// ft_printf("free %p\n", *list);
	free(*list);
}
