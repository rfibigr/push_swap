/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/11 09:58:41 by rfibigr          ###   ########.fr       */
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
typedef struct		s_pile
{
	int				data;
	struct s_pile	*next;
	struct s_pile	*previous;
}					t_pile;

// TOOLS
void	print_pile(t_pile *list);


// CREATE PILE
void	create_pile(t_pile **list, char **av);
int		test_param(char *av);
void	add_element(t_pile **list, char *av);

//EXIT
void	exit_error_malloc(t_pile **list);
void	exit_error_param(t_pile **list);

#endif
