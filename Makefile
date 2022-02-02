# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 14:12:43 by qestefan          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/02/02 10:08:03 by qestefan         ###   ########.fr        #
=======
#    Updated: 2022/02/02 08:09:53 by qestefan         ###   ########.fr        #
>>>>>>> 43c9e8702250249d4e9f5eb4e812f6c28adda6db
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_B	= checker

<<<<<<< HEAD
SRCS	= 	main.c commands_count.c commands.c fill_list.c get_a.c get_argv.c\
			get_b.c lists.c move.c sorting.c utils.c utils2.c
=======
NAME_PROJECT = push_swap
NAME_BONUS = checker
LIB_DIR = ./libft/
GNL_DIR = ./get_next_line/
LIB_NAME =	libft/libft.a
LIB_HEADER = libft
LIBFT = libft.a
CC = gcc
HEADER = ./includes/
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DIR = ./src/
>>>>>>> 43c9e8702250249d4e9f5eb4e812f6c28adda6db

SRCS_B	= 	checker.c commands_count.c commands.c fill_list.c get_a.c get_argv.c\
			get_b.c lists.c move.c sorting.c utils.c utils2.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

<<<<<<< HEAD
LIBFT 	= ./libft/libft.a
LIB_DIR = ./libft
GNL_DIR = get_next_line/get_next_line.h
HEADER  = push_swap.h ./libft/libft.h
=======
BONUS_SRCS =	$(DIR)checker.c $(DIR)get_argv.c $(DIR)utils2.c $(DIR)sorting.c \
			$(DIR)lists.c $(DIR)commands.c $(DIR)commands_count.c $(DIR)utils.c \
			$(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c $(DIR)fill_list.c
>>>>>>> 43c9e8702250249d4e9f5eb4e812f6c28adda6db

RM		= rm -f

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

CC		= gcc

CFLAGS	=	-Wall -Wextra -Werror

<<<<<<< HEAD
$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C $(LIB_DIR)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o ${NAME}

bonus:		$(OBJS_B) $(HEADER) $(GNL_DIR)
			$(MAKE) -C $(LIB_DIR)
			$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o ${NAME_B}

all:		$(NAME)
=======
bonus : $(BONUS_PART) $(LIBFT) $(NAME_BONUS)
$(BONUS_PART):
		$(BONUS_OBJS) -I$(HEADER) get_next_line/get_next_line.h
$(LIBFT):
		@$(MAKE) -C $(LIB_DIR)
$(NAME_BONUS): $(BONUS_OBJS)
		$(CC) $(FLAGS) -I$(HEADER) $(BONUS_OBJS) -L. $(LIB_NAME) -o $(NAME_BONUS)
>>>>>>> 43c9e8702250249d4e9f5eb4e812f6c28adda6db

clean:
			$(RM) $(OBJS) $(OBJS_B)
			$(MAKE) clean -C $(LIB_DIR)

fclean:		clean
			$(RM) $(NAME) $(NAME_B) $(LIBFT)

re:			fclean all

norm:
			norminette *.c *.h

.PHONY:		all clean fclean bonus re norm
