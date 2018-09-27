/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:08:46 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/27 18:55:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			key_hook(int key, t_loop *loop)
{
	if (key == 123)
	{
		loop->speed++;
	}
	if (key == 124)
	{
		if (loop->speed != 0)
			loop->speed--;
	}
	if (key == 53)
	{
		free_lst(&loop->pile_a);
		free_lst(&loop->pile_b);
		free(loop);
		exit(0);
	}
	return (0);
}
