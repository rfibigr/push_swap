# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/09/17 19:33:16 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DIRECTORIES *******************/
SRC_PATH =	src/push_swap
OBJ_PATH =	obj
INC_PATH =	include
LIB_PATH =	lib

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra

#/********************** BINARY *********************/
NAME = push_swap

#/********************** SOURCE *********************/
SRC =	push_swap.c \
		exit.c \
		create_pile.c \
		print_pile.c \
		merge_sort_lst.c \
		tools.c \


OBJ =		$(SRC:.c=.o)
LIBNAME =	libft/libft.a \
			ft_printf/libftprintf.a

#/********************** PATH  *********************/
LIBP = 		$(addprefix $(LIB_PATH)/,$(LIBNAME))
OBJP =		$(addprefix $(OBJ_PATH)/,$(OBJ))
SRCP =		$(addprefix $(SRC_PATH)/,$(SRC))
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))


###################################################
#/********************** RULES *********************/

all : $(NAME)

$(NAME) : $(OBJP)
	make -C $(LIB_PATH)/libft
	make -C $(LIB_PATH)/ft_printf
	$(CC) -o $@ $^ $(LIBP)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)
clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	make clean -C $(LIB_PATH)/libft
	make clean -C $(LIB_PATH)/ft_printf

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIB_PATH)/libft

re: fclean all

debug : $(OBJP)
	make -C $(LIB_PATH)/libft
	make clean -C $(LIB_PATH)/ft_printf
	$(CC) -g3 -fsanitize=address $^ $(LIBP) -o $(NAME)
