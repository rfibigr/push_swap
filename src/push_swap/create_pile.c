/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:24:47 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/13 11:13:34 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	create_pile(t_pile **pile_a, char **av)
{
	int i;
	t_pile *tmp;

	i = 1;
	while (av[i])
	{
		if (!(test_param(av[i])))
			exit_error_param(pile_a);
		add_element(pile_a, av[i]);
		i++;
	}
	tmp = *pile_a;
	tmp->previous->next = NULL;

	print_pile(tmp, 'a');
	/* Merge sorting algo with exit condition if duplicate are found */
	merge_sort(&tmp);
}

/*
** Test if parameter are number
** Add fonction to run ./push_swap 12 "45 65" 34
*/
int	test_param(char *av)
{
	int i;

	i = 0;
	while(av[i])
	{
		if (i == 0 && av[i] != '-' && (av[i] < '0' || av[i] > '9'))
			return (0);
		else if ( i != 0 && (av[i] < '0' || av[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

void add_element(t_pile **begin, char *av)
{
	t_pile *new_element;
	t_pile *tail;

/*
** OPTIOMISATION Add fonction to create_element and initialise it if begin == null
*/
	if(!(new_element = (t_pile*)malloc(sizeof(t_pile))))
		exit_error_malloc(begin);
	new_element->data = atoi(av);
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
		(*begin)->previous->next = new_element;
		(*begin)->previous = new_element;
		new_element->next = *begin;
		new_element->previous = tail;
	}
}
