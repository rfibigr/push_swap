/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:28:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/27 19:30:32 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"
# include "mlx.h"

# define SCREEN_X 2000
# define SCREEN_Y 1300
# define IMG_X 2000
# define IMG_Y 1200

enum				e_op
{
	e_op_sa,
	e_op_sb,
	e_op_ss,
	e_op_pa,
	e_op_pb,
	e_op_ra,
	e_op_rb,
	e_op_rr,
	e_op_rra,
	e_op_rrb,
	e_op_rrr,
};

typedef struct		s_mlx
{
	void			*init;
	void			*image;
	void			*name;
	int				bpp;
	int				size_line;
	int				endian;
	char			*str;
}					t_mlx;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				min;
	int				max;
	int				len_pile;
}					t_coord;

typedef struct		s_loop
{
	t_mlx			*mlx;
	t_coord			coord;
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				speed;
	int				iteration;
}					t_loop;

typedef	void		(*t_make)(t_pile **, t_pile **);

/*
** MAKE OPERATION
*/
void				make_operation(t_pile **pile_a, t_pile **pile_b);
int					calcul_operation(char *str_operation, int *operation);
void				print_result(t_pile **pile_a, t_pile **pile_b);

/*
** OPERATION
*/
void				op_pa(t_pile **pile_a, t_pile **pile_b);
void				op_pb(t_pile **pile_a, t_pile **pile_b);
void				op_rrr(t_pile **pile_a, t_pile **pile_b);
void				op_rra(t_pile **pile_a, t_pile **pile_b);
void				op_rrb(t_pile **pile_a, t_pile **pile_b);
void				op_rr(t_pile **pile_a, t_pile **pile_b);
void				op_ra(t_pile **pile_a, t_pile **pile_b);
void				op_rb(t_pile **pile_a, t_pile **pile_b);
void				op_sa(t_pile **pile_a, t_pile **pile_b);
void				op_sb(t_pile **pile_a, t_pile **pile_b);
void				op_ss(t_pile **pile_a, t_pile **pile_b);

/*
** BONNUS
*/
/*
** initilise image
*/
t_mlx				ft_initialise(void);
void				fill_pixel(char **img_str, int x, int y,
												unsigned long color);
void				fill_line(char **img_str, int x, int y, int len);
void				trace_border(t_mlx *mlx);

/*
** CHECKER VISUALIZER
*/
void				check_argument(int ac, char **av);
int					main_visualizer(int ac, char **av);
t_loop				*init_loop(t_pile *pile_a, t_pile *pile_b,
										t_coord coord, t_mlx *mlx);

/*
** CALCUL IMAGE
*/
t_coord				define_x_y_ratio(t_pile *list_a);
void				draw_pile_image(t_pile *pile_a, t_pile *pile_b,
										t_coord coord, t_mlx *mlx);
int					color_element(int len);
void				add_pile(t_pile *pile_a, t_coord coord,
										t_mlx *mlx, int side_screen);

/*
** MAKE OPEREATION VISUAL
*/
int					make_operation_visual(t_loop *loop);
void				make_instruction(t_loop *loop, char *str_operation,
														int operation);

/*
** FT EVENT
*/
int					key_hook(int key, t_loop *loop);
/*
** TOOLS CHECKER
*/
int					v_abs(int value);
void				print_result_visualizer(t_pile **pile_a, t_pile **pile_b,
													t_mlx *mlx, int iteration);
int					size_pile(t_pile *list_a);

/*
** EVENT
*/

#endif
