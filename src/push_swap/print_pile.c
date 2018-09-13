/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:16:00 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/13 11:13:55 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	print_pile_AB(t_pile *pile_a, t_pile *pile_b)
{
	print_pile(pile_a, 'A');
	print_pile(pile_b, 'B');
	ft_printf("\n-----------------------------------\n");

}

void	print_pile(t_pile *list, char c)
{
	t_pile *tmp;
	int i;

	i = 0;
	tmp = list;
	ft_printf("PILE %c \n", c);
	if (tmp == NULL)
		return;
	ft_printf("data[%d] = %d\n",i, tmp->data);
	i++;
	tmp = tmp->next;
	//while (i < 10 && tmp != list)
	while (tmp != NULL)
	{
		ft_printf("data[%d] = %d\n",i, tmp->data);
		i++;
		tmp = tmp->next;
	}
	ft_printf("\n");
}
