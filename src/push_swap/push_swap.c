/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:08:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/20 15:03:10 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;

	(void)ac;
	pile_b = NULL;
	pile_a = NULL;
	if (ac < 2)
		return (1);
	create_pile(&(pile_a), av);
	if (pile_a->next != NULL)
		sort_pile(&pile_a, &pile_b);
		// test(&pile_a, &pile_b);

	// ft_printf("		END\n--------------------------\n");
	// print_pile_AB(pile_a, pile_b);
	free_lst(&pile_a);
	return (0);
}

void	test(t_pile **pile_a, t_pile **pile_b)
{
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("PUSH\n");
	push(pile_a, pile_b, 'a');
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("PUSH\n");
	push(pile_a, pile_b, 'a');
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("ROTATE A\n");
	rotate(pile_a, 'a');
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("ROTATE B\n");
	rotate(pile_b, 'b');
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("REVERSE ROTATE A\n");
	reverse_rotate(pile_a, 'a');
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("REVERSE ROTATE B\n");
	reverse_rotate(pile_b, 'b');
	print_pile_AB(*pile_a, *pile_b);
	ft_printf("PUSH B\n");
	push(pile_b, pile_a, 'b');
	ft_printf("PUSH B\n");
	push(pile_b, pile_a, 'b');
	print_pile_AB(*pile_a, *pile_b);
	push(pile_b, pile_a, 'b');
	ft_printf("SWAP A\n");
	swap(pile_a, 'a');
	print_pile_AB(*pile_a, *pile_b);

}
