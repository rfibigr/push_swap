/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:31:35 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/07 19:42:54 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_param(t_list **list)
{
	(void) **list;
	write(1, "Error\n", 6);
	//free lst;
	exit (1);

}

void	exit_error_malloc(t_list **list)
{
	(void) **list;
	write(1, "Malloc : fail\n", 14);
	//free lst;
	exit (1);
}
