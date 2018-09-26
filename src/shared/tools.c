/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:48:19 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/26 14:34:31 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_exit(char **s, t_pile **begin)
{
	long long	nbr;
	int			neg;

	neg = 0;
	nbr = 0;
	skip_space(s);
	if (**s == '-')
		neg = 1;
	if (**s == '-' || **s == '+')
		*s = *s + 1;
	if (!(**s >= '0' && **s <= '9'))
		exit_error_param(begin);
	while (**s >= '0' && **s <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + **s - '0';
		if (nbr > INT_MAX || (nbr * -1 < INT_MIN))
			exit_error_param(begin);
		*s = *s + 1;
	}
	skip_space(s);
	if (neg == 1)
		return (-nbr);
	return (nbr);
}

void	skip_space(char **s)
{
	while (**s == ' ' || **s == '\t' || **s == '\n' || **s == '\v' ||
			**s == '\r' || **s == '\f')
		*s = *s + 1;
}

int		pile_is_sort(t_pile **pile)
{
	t_pile	*tmp;
	int		last;

	tmp = (*pile)->next;
	last = (*pile)->data;
	while (tmp != *pile && tmp != NULL)
	{
		if (last > tmp->data)
			return (0);
		last = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}
