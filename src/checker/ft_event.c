/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:08:46 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 14:49:59 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		key_hook(int key, void *param)
{
	ft_printf("key = %d", key);

	if (key == 53)
	{
		ft_printf("EHHH\n");
		free_lst(param);
		exit (0);
	}
	return (1);
}
