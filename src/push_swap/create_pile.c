/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:24:47 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/11 09:56:49 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	create_pile(t_pile **list, char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!(test_param(av[i])))
			exit_error_param(list);
		add_element(list, av[i]);
		i++;
	}
}

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

void add_element(t_pile **list, char *av)
{
	t_pile *new_element;
	t_pile *tmp;
	t_pile *lprevious;

	tmp = *list;
	if(!(new_element = (t_pile*)malloc(sizeof(t_pile))))
		exit_error_malloc(list);
	new_element->data = atoi(av);
	if (*list == NULL)
	{
		new_element->next = NULL;
		new_element->previous = NULL;
	}
	else if (new_element->next == NULL)
	{
		new_element->next = *list;
		new_element->previous = *list;
		tmp->next = new_element;
		tmp->previous = new_element;
	}
	else
	{
		//lst
		lprevious = tmp->previous;
		tmp->previous = new_element;
		//lst->previous;
		lprevious->next = new_element;
		//new_element
		new_element->next = *list;
		new_element->previous = tmp;
	}
	*list = new_element;
}
