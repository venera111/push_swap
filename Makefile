# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 14:12:43 by qestefan          #+#    #+#              #
#    Updated: 2022/02/02 08:09:53 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

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

SRCS =	$(DIR)main.c $(DIR)get_argv.c $(DIR)get_b.c $(DIR)fill_list.c $(DIR)get_a.c \
		$(DIR)commands_count.c $(DIR)commands.c $(DIR)lists.c $(DIR)move.c $(DIR)utils.c \
		$(DIR)sorting.c $(DIR)utils2.c

BONUS_SRCS =	$(DIR)checker.c $(DIR)get_argv.c $(DIR)utils2.c $(DIR)sorting.c \
			$(DIR)lists.c $(DIR)commands.c $(DIR)commands_count.c $(DIR)utils.c \
			$(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c $(DIR)fill_list.c

AR = ar rc

.c.o:
	$(CC) $(FLAGS) -c -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

all: $(LIBFT) $(NAME_PROJECT)

$(NAME): $(OBJS) $(HEADER)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) $(OBJS) $(LIB_NAME) -I$(HEADER) -o $(NAME_PROJECT)

bonus : $(BONUS_PART) $(LIBFT) $(NAME_BONUS)
$(BONUS_PART):
		$(BONUS_OBJS) -I$(HEADER) get_next_line/get_next_line.h
$(LIBFT):
		@$(MAKE) -C $(LIB_DIR)
$(NAME_BONUS): $(BONUS_OBJS)
		$(CC) $(FLAGS) -I$(HEADER) $(BONUS_OBJS) -L. $(LIB_NAME) -o $(NAME_BONUS)

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
