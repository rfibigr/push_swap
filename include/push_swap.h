/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/07 19:58:25 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// STRUCTURE
typedef struct		s_list
{
	int data;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

// TOOLS
void	print_pile(t_list *list);


// CREATE PILE
void	create_pile(t_list **list, char **av);
int		test_param(char *av);
void	add_element(t_list **list, char *av);

//EXIT
void	exit_error_malloc(t_list **list);
void	exit_error_param(t_list **list);

#endif
