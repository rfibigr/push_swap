/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/20 17:25:09 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	while (pile_is_sort(pile_a) != 1)
	{
		while (*pile_a != NULL)
		{
			push_max_decroissant(pile_a, pile_b, 'a');
			push_min_croissant(pile_a, pile_b, 'a');
		}
		while (*pile_b != NULL)
		{
			push_max_decroissant(pile_b, pile_a, 'b');
			push_min_croissant(pile_b, pile_a, 'b');
		}
	}
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

void	push_max_decroissant(t_pile **pile_one, t_pile **pile_two, char c)
{
	if (*pile_one == NULL)
		return;
	if (*pile_two == NULL)
	{
		if ((*pile_one)->previous->data > (*pile_one)->data && (*pile_one)->previous->data > (*pile_one)->next->data)
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->data > (*pile_one)->next->data)
			push(pile_one, pile_two, c);
		else
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
	}
	while (*pile_one != NULL)
	{
		ft_printf("pre = %d, top = %d, next = %d\n",(*pile_one)->previous->data, (*pile_one)->data, (*pile_one)->next->data);
		if(test_previous_max(&(*pile_one)->previous, (*pile_two)->data))
{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
}
		else if(test_top_max(&(*pile_one), (*pile_two)->data))
{
			push(pile_one, pile_two, c);
}
		else if((*pile_one)->next->data < (*pile_two)->data)
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
		 else
			return;


/*
	// ft_printf("pile a = %d, pile a previous = %d, pile b = %d\n",(*pile_one)->data, (*pile_one)->previous->data, (*pile_two)->data);
	if ((*pile_one)->previous->data > (*pile_two)->data
									&& (*pile_one)->data > (*pile_two)->data)
									return ;
		if ((*pile_one)->previous == (*pile_one))
		{
			push(pile_one, pile_two, c);
			return ;
		}
		else if ((*pile_one)->previous->data > (*pile_one)->data
					&& (*pile_one)->previous->data < (*pile_two)->data)
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->data < (*pile_two)->data)
		{
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->previous->data < (*pile_two)->data)
		{
			push(pile_one, pile_two, c);
		}
*/
	}
}

void	push_min_croissant(t_pile **pile_one, t_pile **pile_two, char c)
{
	ft_printf("HELL");
	if (*pile_one == NULL)
		return;
	if (*pile_two == NULL)
	{
		if ((*pile_one)->previous->data < (*pile_one)->data && (*pile_one)->previous->data < (*pile_one)->next->data)
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->data < (*pile_one)->next->data)
			push(pile_one, pile_two, c);
		else
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
	}
	while (*pile_one != NULL)
	{
		if(test_previous_min(&(*pile_one)->previous, (*pile_two)->data))
{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
}
		else if(test_top_min(&(*pile_one), (*pile_two)->data))
{
			push(pile_one, pile_two, c);
}
		else if((*pile_one)->next->data < (*pile_two)->data)
		{
			swap(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else
			return ;




/*
	if ((*pile_one)->previous->data < (*pile_two)->data
									&& (*pile_one)->data < (*pile_two)->data)
									return ;
		if ((*pile_one)->previous == NULL && (*pile_one)->data > (*pile_two)->data)
		{
			push(pile_one, pile_two, c);
			return;
		}
		else if ((*pile_one)->previous->data < (*pile_one)->data
						&& (*pile_one)->previous->data > (*pile_two)->data)
		{
			reverse_rotate(pile_one, c);
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->data > (*pile_two)->data)
		{
			push(pile_one, pile_two, c);
		}
		else if ((*pile_one)->previous->data > (*pile_two)->data)
		{
			push(pile_one, pile_two, c);
		}
*/
	}
}

// CALCUL THE MINIMUM VALUE POSSIBLE TO PUSH AND PILE THE NODE IN TOP OF THE PILE
int		test_previous_min(t_pile **pile_one, int data_two)
{
	if ((*pile_one)->data < data_two)
		return (0);
	if ((*pile_one)->next->data < data_two && (*pile_one)->data > (*pile_one)->next->data)
		return (0);
	if ((*pile_one)->next->next->data < data_two && (*pile_one)->data > (*pile_one)->next->next->data)
		return (0);
	return(1);
}

int		test_top_min(t_pile **pile_one, int data_two)
{
	if ((*pile_one)->data < data_two)
		return (0);
	if ((*pile_one)->next->data < data_two && (*pile_one)->data > (*pile_one)->next->data)
		return (0);
	return(1);
}

int		test_previous_max(t_pile **pile_one, int data_two)
{
	if ((*pile_one)->data > data_two)
		return (0);
	if ((*pile_one)->next->data > data_two && (*pile_one)->data < (*pile_one)->next->data)
		return (0);
	if ((*pile_one)->next->next->data > data_two && (*pile_one)->data < (*pile_one)->next->next->data)
		return (0);
	return(1);
}

int		test_top_max(t_pile **pile_one, int data_two)
{
	if ((*pile_one)->data < data_two)
		return (0);
	if ((*pile_one)->next->data < data_two && (*pile_one)->data > (*pile_one)->next->data)
		return (0);
	return(1);
}
