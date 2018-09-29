/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:08:46 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/29 09:50:45 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		key_hook(int key, t_loop *loop)
{
	if (key == 49 && loop->start == 1)
	{
		mlx_loop_hook(loop->mlx->init, stop_prog, loop);
		loop->start = 0;
		key = 0;
	}
	if (key == 49 && loop->start == 0)
	{
		loop->start = 1;
		mlx_loop_hook(loop->mlx->init, make_operation_visual, loop);
	}
	if (key == 123)
		loop->speed++;
	if (key == 124)
		loop->speed != 0 ? loop->speed-- : 1;
	if (key == 53)
	{
		free_lst(&loop->pile_a);
		free_lst(&loop->pile_b);
		free(loop);
		exit(0);
	}
	return (0);
}

int		stop_prog(t_loop *loop)
{
	(void)loop;
	return (1);
}
