# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/09/27 18:22:39 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DEFINE COLOR *******************/
NC = \033[0m
RED = \033[1;31m
GREEN = \033[0;32m
LOW_GREEN = \033[1;32m
BLUE = \033[1;34m
PURPLE = \033[0;35m
WHITE = \033[1;37m
YELLOW = \033[1;33m
CYAN = \033[0;36m
BLACK = \033[0;30m
DARK_GRAY = \033[1;30m


#/******************* DIRECTORIES *******************/
SRC_PATH_PUSH =	src/push_swap
SRC_PATH_CHECKER =	src/checker
SRC_PATH_SHARED =	src/shared
OBJ_PATH =	obj
OBJ_PATH_PUSH =	obj/push_swap
OBJ_PATH_CHECKER =	obj/checker
OBJ_PATH_SHARED =	obj/shared
INC_PATH =	include
LIB_PATH =	lib

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra
FRAMEWORK = 	-framework OpenGL -framework AppKit

#/********************** BINARY *********************/
NAME = push_swap checker

#/********************** SOURCE *********************/
SRC_PUSH =		push_swap.c \
				sort_pile_algo.c \
				sort_pile_condition.c \

SRC_CHECKER =	checker.c \
				checker_bonus.c \
				make_operation.c \
				make_operation_visual.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \
				ft_event.c \
				calcul_image.c \
				tools_checker.c \
				initialise_image.c \

SRC_SHARED = 	exit.c \
				create_pile.c \
				print_pile.c \
				merge_sort_lst.c \
				tools.c \
				operation.c \

OBJ_PUSH	=		$(SRC_PUSH:.c=.o)
OBJ_CHECKER =		$(SRC_CHECKER:.c=.o)
OBJ_SHARED  =		$(SRC_SHARED:.c=.o)

LIBNAME =	libft/libft.a \
			ft_printf/libftprintf.a \
			minilibx_macos/libmlx.a \

#/********************** PATH  *********************/
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))
LIBP = 		$(addprefix $(LIB_PATH)/,$(LIBNAME))
OBJ_CHECKER_P =		$(addprefix $(OBJ_PATH_CHECKER)/,$(OBJ_CHECKER))
OBJ_PUSH_P =		$(addprefix $(OBJ_PATH_PUSH)/,$(OBJ_PUSH))
OBJ_SHARED_P =		$(addprefix $(OBJ_PATH_SHARED)/,$(OBJ_SHARED))


###################################################
#/********************** RULES *********************/

all : push_swap checker

push_swap : $(OBJ_PUSH_P) $(OBJ_SHARED_P)
	@echo "$(GREEN) --Compiling--\t\tshared"
	@echo "$(GREEN) --Compiling--\t\tpush_swap"
	@echo "$(LOW_GREEN) --Compiling lib--\tlibft"
	@make -C $(LIB_PATH)/libft
	@echo "$(LOW_GREEN) --Compiling lib--\tft_printf"
	@make -C $(LIB_PATH)/ft_printf
	@echo "$(LOW_GREEN) --Compiling lib--\tminilibix"
	@make -C $(LIB_PATH)/minilibx_macos
	@echo "$(PURPLE) --Linking--\t\tpush_swap"
	@$(CC) -o $@ $^ $(LIBP)

checker : $(OBJ_CHECKER_P) $(OBJ_SHARED_P)
	@echo "$(GREEN) --Compiling--\t\tchecker"
ifneq (,$(filter checker ,$(MAKECMDGOALS)))
	@echo "$(LOW_GREEN) --Compiling lib--\tlibft"
	@make -C $(LIB_PATH)/libft
	@echo "$(LOW_GREEN) --Compiling lib--\tft_printf"
	@make -C $(LIB_PATH)/ft_printf
endif
	@echo "$(LOW_GREEN) --Compiling lib--\tminilibix"
	@make -C $(LIB_PATH)/minilibx_macos
	@echo "$(PURPLE) --Linking--\t\tchecker"
	@$(CC) -o $@ $^ $(LIBP) $(FRAMEWORK)

$(OBJ_PATH_PUSH)/%.o: $(SRC_PATH_PUSH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH_PUSH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_CHECKER)/%.o: $(SRC_PATH_CHECKER)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH_CHECKER) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_SHARED)/%.o: $(SRC_PATH_SHARED)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH_SHARED) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

clean :
	@echo "$(RED) --Cleaning--\t\tobject folder"
	@rm -rf $(OBJ_PUSH) $(OBJ_SHARED) $(OBJ_CHECKER)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED) --Cleaning--\t\tlibrary libft"
	@make clean -C $(LIB_PATH)/libft
	@echo "$(RED) --Cleaning--\t\tlibrary ft_printf"
	@make clean -C $(LIB_PATH)/ft_printf
	@echo "$(RED) --Cleaning--\t\tlibrary minilibx"
	@make clean -C $(LIB_PATH)/minilibx_macos

clibft :
	@echo "$(RED) --Cleaning--\t\tlibrary libft"
	@make clean -C $(LIB_PATH)/libft
cprintf :
	@echo "$(RED) --Cleaning--\t\tlibrary ft_printf"
	@make clean -C $(LIB_PATH)/ft_printf

fclean : clean
	@echo "$(RED) --Cleaning--\t\texecutable"
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)/libft
	@make fclean -C $(LIB_PATH)/ft_printf

re: fclean all
