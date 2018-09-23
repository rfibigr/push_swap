/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:24:47 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/17 15:10:06 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_pile(t_pile **pile_a, char **av)
{
	int		i;
	t_pile	*tmp;

	i = 1;
	while (av[i])
	{
		if (!(test_param(av[i])))
			exit_error_param(pile_a);
		add_element(pile_a, av[i]);
		i++;
	}
	/*
	* merge sorting algo with exit condition if duplicate are found
	* tmp to make the listnull terminated
	*/
	tmp = *pile_a;
	if (tmp->previous)
		tmp->previous->next = NULL;
	merge_sort(&tmp);
	reorder_lst_order(*pile_a);
}

void	reorder_lst_order(t_pile *pile_a)
{
	t_pile *tmp;

	tmp = pile_a;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	while(tmp->previous != pile_a)
	{
		tmp->previous->next = tmp;
		tmp = tmp->previous;
	}
	tmp->previous->next = tmp;
}

/*
** Test if parameter are number
** Add fonction to run ./push_swap 12 "45 65" 34
*/
int		test_param(char *av)
{
	int i;

	i = 0;
	if (av[i] == '-')
		i++;
	//ft_printf("strcmp = %d\n", ft_strcmp(intmax, av) + i);
	// if (ft_strcmp(intmax, av) + i > 0)
	//	return (0);
	// VERIF INT MAX / INT MIN
	while (av[i])
	{
		if (i != 0 && (av[i] < '0' || av[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

void	add_element(t_pile **begin, char *av)
{
	t_pile *new_element;
	t_pile *tail;

/*
** OPTIOMISATION Add fonction to create_element and initialise it if begin == null
*/
	if (!(new_element = (t_pile*)malloc(sizeof(t_pile))))
		exit_error_malloc(begin);
	tail = NULL;
	if (*begin == NULL)
	{
		new_element->next = NULL;
		new_element->previous = NULL;
		*begin = new_element;
	}
	else if ((*begin)->next == NULL)
	{
		new_element->next = *begin;
		new_element->previous = *begin;
		(*begin)->next = new_element;
		(*begin)->previous = new_element;
	}
	else
	{
		tail = (*begin)->previous;
		(*begin)->previous->next = new_element;
		(*begin)->previous = new_element;
		new_element->next = *begin;
		new_element->previous = tail;
	}
	new_element->data = ft_atoi_exit(av, begin);
}
