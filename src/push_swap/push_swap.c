/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/05 18:25:09 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	int *pile_a;
	int *pile_b;
	int len_a;
	int len_b;

	len_a = ac - 1;
	len_b = 0;
	pile_a = create_pile(len_a, av);
	if (!(pile_b = (int *)malloc(sizeof(int) * len_a) ))
		exit (0);
	print_pile(ac - 1, pile_a);
	print_pile(ac - 1, pile_b);


	return(0);
}

void	print_pile(int len, int *pile)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("printf_pile : %d\n", pile[i]);
		i++;
	}
}

int		*create_pile(int len, char **av)
{
	int *pile_a;
	int i;

	if (!(pile_a = (int *)malloc(sizeof(int) * len) ))
		exit (0);

	i = 1;
	if(!(test_param(av)))
	{
		ft_printf("Error\n");
		//free
		exit (1);
	}
	while (av[i])
	{
		ft_printf("av = %s\n", av[i]);
		pile_a[i - 1] = ft_atoi(av[i]);
		ft_printf("pile = %d\n", pile_a[i - 1]);
		i++;
	}
	return (pile_a);
}

int	test_param(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (j == 0 && av[i][j] != '-' && (av[i][j] < '0' || av[i][j] > '9'))
					{
						ft_printf("Error\n");
						return (0);
					}
			else if ( j != 0 && (av[i][j] < '0' || av[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
