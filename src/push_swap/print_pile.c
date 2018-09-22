/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:16:00 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/22 23:28:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	print_pile_AB(t_pile *pile_a, t_pile *pile_b)
{
	print_pile(pile_a, "A");
	print_pile(pile_b, "B");
	ft_printf("\n-----------------------------------\n");

}

void	print_pile(t_pile *list, char *str)
{
	t_pile *tmp;
	int i;

	ft_printf("PILE %s \n", str);
	i = 0;
	tmp = list;
	if (tmp == NULL)
		return;
	ft_printf("data[%d] = %d | %p\n",i, tmp->data, tmp);
	i++;
	tmp = tmp->next;
	while (tmp != list && tmp != NULL)
	{
		ft_printf("data[%d] = %d | %p\n",i, tmp->data, tmp);
		i++;
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_pile_previous(t_pile *list, char *str)
{
	t_pile *tmp;
	int i;

	i = 0;
	tmp = list;
	ft_printf("PILE %s \n", str);
	if (tmp == NULL)
		return;
	// ft_printf("data[%d] = %d\n",i, tmp->data);
	ft_printf("data[%d] = %p\n",i, tmp);
	i++;
	tmp = tmp->previous;
	while (tmp != list && tmp != NULL)
	{
		// ft_printf("data[%d] = %d\n",i, tmp->data);
		ft_printf("data[%d] = %p\n",i, tmp);
		i++;
		tmp = tmp->previous;
	}
	ft_printf("\n");
}
