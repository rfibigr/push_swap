/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:48:19 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/23 20:35:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_exit(const char *s, t_pile **begin)
{
	int i;
	long long	nbr;
	int neg;

	i = 0;
	neg = 0;
	nbr = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i - 1] == '-')
		neg = 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + s[i] - '0';
		if (nbr > INT_MAX || (nbr > INT_MIN && neg == 1))
			exit_error_param(begin);
		i++;
	}
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}
