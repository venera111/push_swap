/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:56:41 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/02 15:29:23 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"

typedef struct s_lst
{
	int				num;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	*start;
	int		len;
	int		min;
	int		mid;
	int		max;
}	t_stack;

typedef struct s_getarg
{
	int			cntr;
	int			cnt;
	int			i;
	int			k;
	char		**str;
	int			*buff;
}	t_getarg;

typedef struct s_commands
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	f1;
	int	f2;
	int	f3;
	int	f4;
}	t_commands;

int			ft_masslen(int *array);
int			*ft_strjoin_int(int *s1, int *s2, int counter, int count);
int			*ft_strdup_int(const int *s1, int count);
int			*save_buffer(int *array, int *buffer, int count, int counter);
int			*fill_array(int *buffer, char **str, int count);
void		init_getargv(t_getarg *getav);
int			ft_arrlen(char **str);
void		ft_free(char **str);
void		ft_perror(void);
void		check_repeats(int *arg, int counter);
void		check_sort(int *arg, int len);
t_stack		*get_argv(char **argv, t_getarg getav, t_stack *a);
t_stack		*fill_list(t_getarg getav, t_stack *a, int *array);
t_stack		*get_b(t_stack *a);
void		get_a(t_stack *a, t_stack *b);
t_commands	min_move(t_stack *a, t_stack *b);
t_commands	get_move(int pos_a, int pos_b, int len_a, int len_b);
int			position(t_stack *stack, int num);
int			index_num(t_stack *stack, int num);
void		rotate_count(t_stack *stack, int n);
int			check_sort_list(t_stack *a);
void		continue_sorting(t_stack *a);
void		sort_threenum(t_stack *a);
void		sort_threenum2(t_stack *a, int a1, int a2, int a3);
t_lst		*lstnew(int val);
t_lst		*lstnext(t_lst *lst, int val);
void		lstclear(t_lst **lst);
t_lst		*lst_n_elem(t_stack *stack, int n);
void		swap(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		rotate(t_stack *stack);
void		push(t_stack *a, t_stack *b);
void		commands_count(t_stack *stack, void (*f)(t_stack *), int count);
void		shift_to_b(t_stack *a, t_stack *b, int mid);
void		move_1(t_stack *a, t_stack *b, t_commands move);
void		move_2(t_stack *a, t_stack *b, t_commands move);
void		move_3(t_stack *a, t_stack *b, t_commands move);
void		move_4(t_stack *a, t_stack *b, t_commands move);
void		ft_write_count(char *str, int count);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
void		change_stack(t_stack *stack);
char		*get_next_line(int fd);
int			ft_atoi_swap(char *str);

#endif
