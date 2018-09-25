/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:48:19 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/25 12:27:20 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_exit(char **s, t_pile **begin)
{
	long long	nbr;
	int neg;

	neg = 0;
	nbr = 0;
	while (is_space(**s))
		*s = *s + 1;
	if (**s == '-')
		neg = 1;
	if (**s == '-' || **s == '+')
		*s = *s + 1;
	while (**s >= '0' && **s <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + **s - '0';
		if (nbr > INT_MAX || (nbr * -1 < INT_MIN))
			exit_error_param(begin);
		*s = *s + 1;
	}
	while (is_space(**s))
		*s = *s + 1;
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\r' || c == '\f')
		return (1);
	return (0);
}

int		pile_is_sort(t_pile **pile)
{
	t_pile *tmp;
	int		last;

	tmp = (*pile)->next;
	last = (*pile)->data;
	while(tmp != *pile && tmp != NULL)
	{
		if (last > tmp->data)
			return (0);
		last = tmp ->data;
		tmp = tmp->next;
	}
	return (1);
}
