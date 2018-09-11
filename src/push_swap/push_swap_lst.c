/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/11 09:56:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	(void) ac;
	t_pile *list_a;
//	t_pile *list_b;

//	list_b = NULL;
	list_a = NULL;
	create_pile(&(list_a), av);

	print_pile(list_a);
	//print_pile(list_b);

	return(0);
}

void	print_pile(t_pile *list)
{
	t_pile *tmp;
	int i;

	i = 0;
	tmp = list->next;
	ft_printf("data[%d] = %d\n",i, tmp->data);
	i++;
	while (i < 4)
	{
		ft_printf("data[%d] = %d\n",i, tmp->data);
		i++;
		tmp = tmp->next;
	}
}
