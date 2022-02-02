# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 14:12:43 by qestefan          #+#    #+#              #
#    Updated: 2022/02/02 07:49:52 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME_PROJECT = push_swap
LIB_DIR = ./libft/
LIB_NAME =	libft/libft.a
LIB_HEADER = libft
LIBFT = libft.a
CC = gcc
HEADER = ./includes/
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DIR = ./src/
BONUS = ./bonus/

SRCS =	$(DIR)main.c $(DIR)get_argv.c $(DIR)get_b.c $(DIR)fill_list.c $(DIR)get_a.c \
		$(DIR)commands_count.c $(DIR)commands.c $(DIR)lists.c $(DIR)move.c $(DIR)utils.c \
		$(DIR)sorting.c $(DIR)utils2.c

BONUS_SRCS = $(BONUS)checker.c $(DIR)get_argv.c $(DIR)utils2.c $(DIR)commands.c

AR = ar rc

.c.o:
	$(CC) $(FLAGS) -c -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

all: $(LIBFT) $(NAME_PROJECT)

$(NAME): $(OBJS) $(HEADER)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) $(OBJS) $(LIB_NAME) -I$(HEADER) -o $(NAME_PROJECT)

bonus : $(BONUS_PART) $(LIBFT) $(NAME_PROJECT)

$(BONUS_PART):
		$(BONUS_OBJS) -I$(HEADER) get_next_line/get_next_line.h
$(LIBFT):
		@$(MAKE) -C $(LIB_DIR)
$(NAME_PROJECT): $(OBJS)
		$(CC) $(FLAGS) -I$(HEADER) $(OBJS) -L. $(LIB_NAME) -o $(NAME_PROJECT)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME_PROJECT)

re: fclean all

norm:
	norminette src/*.c includes/*.h

.PHONY: all clean fclean re bonus norm
