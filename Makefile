# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 14:12:43 by qestefan          #+#    #+#              #
#    Updated: 2022/02/02 10:50:21 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_B	= checker

SRCS	= 	main.c commands_count.c commands.c fill_list.c get_a.c get_argv.c\
			get_b.c lists.c move.c sorting.c utils.c utils2.c

SRCS_B	= 	checker.c commands_count.c commands.c fill_list.c get_a.c get_argv.c\
			get_b.c lists.c move.c sorting.c utils.c utils2.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

LIBFT 	= ./libft/libft.a
LIB_DIR = ./libft
GNL_DIR = get_next_line/get_next_line.h
HEADER  = push_swap.h ./libft/libft.h

RM		= rm -f

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

CC		= gcc

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C $(LIB_DIR)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o ${NAME}

bonus:		$(OBJS_B) $(HEADER) $(GNL_DIR)
			$(MAKE) -C $(LIB_DIR)
			$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o ${NAME_B}

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_B)
			$(MAKE) clean -C $(LIB_DIR)

fclean:		clean
			$(RM) $(NAME) $(NAME_B) $(LIBFT)

re:			fclean all

norm:
			norminette *.c *.h

.PHONY:		all clean fclean bonus re norm
